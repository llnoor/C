#ifndef VIEWER_H
#define VIEWER_H

#include <QOpenGLWidget>
#include <QtOpenGL>
#include <QtWidgets>

extern "C" {
#include "../core/transforms.h"
}

class Viewer : public QOpenGLWidget, protected QOpenGLFunctions {
 public:
  Viewer(QWidget *parent);
  ~Viewer();

  void free_data();
  void reload_object(object_t *obj);
  QString update_count_info(QString fileName);
  void resetMouseRotate();

  // -------Переменные с настройками отображения-------
  QColor color_background = QColor(Qt::black);
  QColor color_line = QColor(Qt::white);
  QColor color_point = QColor(Qt::red);

  unsigned int projection_type = 0;  // параллельная
  unsigned int point_type = 0;       // квадрат
  unsigned int line_type = 0;        // сплошная

  double line_width = 2;
  double point_size = 4;
  double scale_factor = 1.75;

  // Граничные значения отображения
  double min_x = -1, max_x = 1;
  double min_y = -1, max_y = 1;
  double min_z = -1, max_z = 1;

  // Хранение массива точек и ребер
  vertices *verts = NULL;
  unsigned int *polygons = NULL;
  int polygons_count = 0;

  float wheelAngle = 0;
  float xRot, yRot, zRot;
  QPoint mPos;

 protected:
  void initializeGL() override;
  void resizeGL(int w, int h) override;
  void paintGL() override;

  void mousePressEvent(QMouseEvent *mo) override;
  void mouseMoveEvent(QMouseEvent *mo) override;
  //  void wheelEvent(QWheelEvent *mo) override;

  void drawObject();
  void drawPoints();
  void drawLines();

  void convert_objects(object_t *obj);
  void calc_objects_borders();

  double dmin(double a, double b);
  double dmax(double a, double b);
};

#endif  // VIEWER_H
