#include "viewer.h"

Viewer::Viewer(QWidget *parent) : QOpenGLWidget(parent) {}

Viewer::~Viewer() { free_data(); }

void Viewer::free_data() {
  if (verts != NULL)
    if (verts->vertex != NULL) free(verts->vertex);
  if (polygons != NULL) free(polygons);
  verts = NULL, polygons = NULL;
}

void Viewer::initializeGL() {
  initializeOpenGLFunctions();
  glEnable(GL_DEPTH_TEST);
}

void Viewer::resizeGL(int w, int h) {
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
}

void Viewer::paintGL() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  // установка фона
  glClearColor(color_background.redF(), color_background.greenF(),
               color_background.blueF(), 0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  // установка проекции (с границами объекта)
  if (projection_type == 1) {
    glFrustum(min_x, max_x, min_y, max_y, 1, 100);
    glTranslatef(0, 0, -2.5 * max_z);
  } else {
    glOrtho(min_x * scale_factor, max_x * scale_factor, min_y * scale_factor,
            max_y * scale_factor, min_z * scale_factor, max_z * scale_factor);
  }

  if (verts != NULL && polygons != NULL) {
    glEnableClientState(GL_VERTEX_ARRAY);
    // указатель на массив с вершинами
    glVertexPointer(3, GL_DOUBLE, 0, verts->vertex);

    // для вращения мышкой
    glRotatef(xRot, 1, 0, 0);
    glRotatef(yRot, 0, 1, 0);

    drawObject();
    glDisableClientState(GL_VERTEX_ARRAY);
  }
  update();
}

void Viewer::resetMouseRotate() {
  xRot = 0, yRot = 0;
  scale_factor = 1.75;
}

void Viewer::drawObject() {
  // если не выключены вершины
  if (point_type != 2) drawPoints();
  drawLines();
}

void Viewer::drawLines() {
  glLineWidth(line_width);
  glLineStipple(1, 0x3333);  // вкл пунктирную
  if (line_type == 1) glEnable(GL_LINE_STIPPLE);
  // цвет ребер
  glColor3d(color_line.redF(), color_line.greenF(), color_line.blueF());

  glDrawElements(GL_LINES, polygons_count, GL_UNSIGNED_INT, polygons);

  glDisable(GL_LINE_STIPPLE);
}

void Viewer::drawPoints() {
  glPointSize(point_size);
  if (point_type == 1)  // вкл гладкие
    glEnable(GL_POINT_SMOOTH);

  glColor3d(color_point.redF(), color_point.greenF(),
            color_point.blueF());  // задаем цвет вершин

  glDrawArrays(GL_POINTS, 0, verts->count);

  glDisable(GL_POINT_SMOOTH);
}

void Viewer::convert_objects(object_t *obj) {
  verts = (vertices *)malloc(sizeof(vertices));
  verts->count = obj->vert->count;
  verts->vertex = (double *)malloc(verts->count * 3 * sizeof(double));
  std::memcpy(verts->vertex, obj->vert->vertex,
              obj->vert->count * 3 * sizeof(double));
  //  verts = obj->vert;

  polygons_count = 0;
  for (unsigned int i = 0; i < obj->count_polygons; i++) {
    polygons_count += obj->polygons[i].value;
  }
  polygons = (unsigned int *)malloc(polygons_count * sizeof(unsigned int));

  for (unsigned int p_count = 0, i = 0; i < obj->count_polygons; i++) {
    std::memcpy(polygons + p_count, obj->polygons[i].vertex,
                obj->polygons[i].value * sizeof(int));
    p_count += obj->polygons[i].value;
  }
}

void Viewer::reload_object(object_t *obj) {
  // очищаем память предыдущих объектов
  free_data();
  // преобразование данных в одномерный массив
  convert_objects(obj);
  // подсчет новых граничных точек объекта
  calc_objects_borders();
}

QString Viewer::update_count_info(QString fileName) {
  return QString("Кол-во вершин: %1; кол-во ребер: %2\nФайл: %4")
      .arg(verts->count)
      .arg(verts->count + polygons_count - 2)
      .arg(fileName);
}

void Viewer::calc_objects_borders() {
  min_x = -1;
  max_x = 1;
  min_y = -1;
  max_y = 1;
  min_z = -1;
  max_z = 1;

  for (int i = 0; i < verts->count; i++) {
    min_x = dmin(min_x, verts->vertex[3 * i]);
    max_x = dmax(max_x, verts->vertex[3 * i]);
    min_y = dmin(min_y, verts->vertex[3 * i + 1]);
    max_y = dmax(max_y, verts->vertex[3 * i + 1]);
    min_z = dmin(min_z, verts->vertex[3 * i + 2]);
    max_z = dmax(max_z, verts->vertex[3 * i + 2]);
  }
}

double Viewer::dmin(double a, double b) { return (a < b) ? a : b; }

double Viewer::dmax(double a, double b) { return (a > b) ? a : b; }

void Viewer::mousePressEvent(QMouseEvent *mo) { mPos = mo->pos(); }

void Viewer::mouseMoveEvent(QMouseEvent *mo) {
  xRot = 1 / M_PI * (mo->pos().y() - mPos.y());
  yRot = 1 / M_PI * (mo->pos().x() - mPos.x());
  update();
}

// void Viewer::wheelEvent(QWheelEvent *mo) {
//   if (projection_type == 1)
//     max_z += mo->angleDelta().y() / 20;
//   else
//     scale_factor += mo->angleDelta().y() / 20;
// }
