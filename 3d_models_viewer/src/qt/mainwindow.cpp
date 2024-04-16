#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  readSettings();
  timer = new QTimer(0);
  connect(timer, SIGNAL(timeout()), this, SLOT(gifRecord()));
}

MainWindow::~MainWindow() {
  saveSettings();
  if (obj != NULL) free_all(obj);
  delete ui;
  delete timer;
}

void MainWindow::saveSettings() {
  std::ofstream file(file_path, std::ios::binary);
  if (file.is_open()) {
    file.write((char *)&(ui->viewerWidget->projection_type),
               sizeof(ui->viewerWidget->projection_type));
    file.write((char *)&(ui->viewerWidget->line_type),
               sizeof(ui->viewerWidget->line_type));
    file.write((char *)&(ui->viewerWidget->point_type),
               sizeof(ui->viewerWidget->point_type));
    file.write((char *)&(ui->viewerWidget->line_width),
               sizeof(ui->viewerWidget->line_width));
    file.write((char *)&(ui->viewerWidget->point_size),
               sizeof(ui->viewerWidget->point_size));

    int r = ui->viewerWidget->color_line.red(),
        g = ui->viewerWidget->color_line.green(),
        b = ui->viewerWidget->color_line.blue();
    file.write((char *)&(r), sizeof(r));
    file.write((char *)&(g), sizeof(g));
    file.write((char *)&(b), sizeof(b));

    r = ui->viewerWidget->color_point.red(),
    g = ui->viewerWidget->color_point.green(),
    b = ui->viewerWidget->color_point.blue();
    file.write((char *)&(r), sizeof(r));
    file.write((char *)&(g), sizeof(g));
    file.write((char *)&(b), sizeof(b));

    r = ui->viewerWidget->color_background.red(),
    g = ui->viewerWidget->color_background.green(),
    b = ui->viewerWidget->color_background.blue();
    file.write((char *)&(r), sizeof(r));
    file.write((char *)&(g), sizeof(g));
    file.write((char *)&(b), sizeof(b));

    file.close();
  }
}

void MainWindow::readSettings() {
  std::ifstream file(file_path, std::ios::binary);
  if (file.is_open()) {
    file.read((char *)&(ui->viewerWidget->projection_type),
              sizeof(unsigned int));
    ui->projection_type_comboBox->setCurrentIndex(
        ui->viewerWidget->projection_type);
    file.read((char *)&(ui->viewerWidget->line_type), sizeof(unsigned int));
    ui->line_type_comboBox->setCurrentIndex(ui->viewerWidget->line_type);
    file.read((char *)&(ui->viewerWidget->point_type), sizeof(unsigned int));
    ui->point_type_comboBox->setCurrentIndex(ui->viewerWidget->point_type);
    file.read((char *)&(ui->viewerWidget->line_width), sizeof(double));
    ui->line_width_spinbox->setValue(ui->viewerWidget->line_width);
    file.read((char *)&(ui->viewerWidget->point_size), sizeof(double));
    ui->point_size_spinbox->setValue(ui->viewerWidget->point_size);

    int r, g, b;
    file.read((char *)&(r), sizeof(int));
    file.read((char *)&(g), sizeof(int));
    file.read((char *)&(b), sizeof(int));
    ui->viewerWidget->color_line.setRgb(r, g, b);
    ui->r_line_color_spinbox->setValue(r);
    ui->g_line_color_spinbox->setValue(g);
    ui->b_line_color_spinbox->setValue(b);

    file.read((char *)&(r), sizeof(int));
    file.read((char *)&(g), sizeof(int));
    file.read((char *)&(b), sizeof(int));
    ui->viewerWidget->color_point.setRgb(r, g, b);
    ui->r_point_color_spinbox->setValue(r);
    ui->g_point_color_spinbox->setValue(g);
    ui->b_point_color_spinbox->setValue(b);

    file.read((char *)&(r), sizeof(int));
    file.read((char *)&(g), sizeof(int));
    file.read((char *)&(b), sizeof(int));
    ui->viewerWidget->color_background.setRgb(r, g, b);
    ui->r_back_color_spinbox->setValue(r);
    ui->g_back_color_spinbox->setValue(g);
    ui->b_back_color_spinbox->setValue(b);

    file.close();
    ui->viewerWidget->update();
  }
}

void MainWindow::on_open_file_button_clicked() {
  QString qFileName = QFileDialog::getOpenFileName(
      this, tr("Open OBJ File"), "", tr("OBJ Files(*.obj *.hue)"));
  // преобразуем в char строку
  QByteArray fn_bytes = qFileName.toLocal8Bit();
  if (fn_bytes.length() == 0) return;
  char *file_name = fn_bytes.data();

  // чистим пред. объект и парсим новый
  if (obj != NULL) free_all(obj);
  obj = parseObj(file_name);

  // загрузка данных объекта
  ui->viewerWidget->reload_object(obj);
  // обновление инфы о кол-ве элементов
  ui->plainTextEdit->setPlainText(
      ui->viewerWidget->update_count_info(qFileName));
}

void MainWindow::on_line_width_spinbox_valueChanged(double arg1) {
  ui->viewerWidget->line_width = arg1;
}

void MainWindow::on_point_size_spinbox_valueChanged(double arg1) {
  ui->viewerWidget->point_size = arg1;
}

void MainWindow::on_r_back_color_spinbox_valueChanged(int arg1) {
  ui->viewerWidget->color_background =
      QColor(arg1, ui->g_back_color_spinbox->value(),
             ui->b_back_color_spinbox->value());
}

void MainWindow::on_g_back_color_spinbox_valueChanged(int arg1) {
  ui->viewerWidget->color_background =
      QColor(ui->r_back_color_spinbox->value(), arg1,
             ui->b_back_color_spinbox->value());
}

void MainWindow::on_b_back_color_spinbox_valueChanged(int arg1) {
  ui->viewerWidget->color_background =
      QColor(ui->r_back_color_spinbox->value(),
             ui->g_back_color_spinbox->value(), arg1);
}

void MainWindow::on_r_point_color_spinbox_valueChanged(int arg1) {
  ui->viewerWidget->color_point =
      QColor(arg1, ui->g_point_color_spinbox->value(),
             ui->b_point_color_spinbox->value());
}

void MainWindow::on_g_point_color_spinbox_valueChanged(int arg1) {
  ui->viewerWidget->color_point =
      QColor(ui->r_point_color_spinbox->value(), arg1,
             ui->b_point_color_spinbox->value());
}

void MainWindow::on_b_point_color_spinbox_valueChanged(int arg1) {
  ui->viewerWidget->color_point =
      QColor(ui->r_point_color_spinbox->value(),
             ui->g_point_color_spinbox->value(), arg1);
}

void MainWindow::on_r_line_color_spinbox_valueChanged(int arg1) {
  ui->viewerWidget->color_line = QColor(arg1, ui->g_line_color_spinbox->value(),
                                        ui->b_line_color_spinbox->value());
}

void MainWindow::on_g_line_color_spinbox_valueChanged(int arg1) {
  ui->viewerWidget->color_line = QColor(ui->r_line_color_spinbox->value(), arg1,
                                        ui->b_line_color_spinbox->value());
}

void MainWindow::on_b_line_color_spinbox_valueChanged(int arg1) {
  ui->viewerWidget->color_line =
      QColor(ui->r_line_color_spinbox->value(),
             ui->g_line_color_spinbox->value(), arg1);
}

void MainWindow::on_projection_type_comboBox_currentIndexChanged(int index) {
  ui->viewerWidget->projection_type = index;
}

void MainWindow::on_point_type_comboBox_currentIndexChanged(int index) {
  ui->viewerWidget->point_type = index;
}

void MainWindow::on_line_type_comboBox_currentIndexChanged(int index) {
  ui->viewerWidget->line_type = index;
}

void MainWindow::on_apply_transforms_button_clicked() {
  if (ui->viewerWidget->verts != NULL) {
    scale_matrix(ui->viewerWidget->verts, ui->x_scale_spinbox->value(),
                     ui->y_scale_spinbox->value(),
                     ui->z_scale_spinbox->value());
    move_matrix(ui->viewerWidget->verts, ui->x_move_spinbox->value(),
                    ui->y_move_spinbox->value(), ui->z_move_spinbox->value());
    rotate_matrix(ui->viewerWidget->verts, ui->x_rotate_spinbox->value(),
                      ui->y_rotate_spinbox->value(),
                      ui->z_rotate_spinbox->value());

    ui->x_move_spinbox->setValue(0.0);
    ui->y_move_spinbox->setValue(0.0);
    ui->z_move_spinbox->setValue(0.0);

    ui->x_scale_spinbox->setValue(1.0);
    ui->y_scale_spinbox->setValue(1.0);
    ui->z_scale_spinbox->setValue(1.0);

    ui->x_rotate_spinbox->setValue(0.0);
    ui->y_rotate_spinbox->setValue(0.0);
    ui->z_rotate_spinbox->setValue(0.0);
  }
}

void MainWindow::on_reset_transforms_button_clicked() {
  ui->viewerWidget->resetMouseRotate();
  ui->viewerWidget->reload_object(obj);
}

void MainWindow::on_jpg_save_button_clicked() {
  QFileDialog dialog(this);
  QString desktopQString =
      QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
  QString jpgQString =
      dialog.getSaveFileName(this, "Save screenshot as...", desktopQString,
                             "BMP (*.bmp);; JPEG (*.jpeg)");
  ui->viewerWidget->grabFramebuffer().save(jpgQString);
}

void MainWindow::on_gif_save_button_clicked() {
  if (ui->x_rotate_spinbox->value() != 0.0 ||
      ui->y_rotate_spinbox->value() != 0.0 ||
      ui->z_rotate_spinbox->value() != 0.0) {
    auto_rotate = true;
  }
  timer->start(100);
}

void MainWindow::gifRecord() {
  if (gifTime < 4.9) {
    imgQVector.push_back(ui->viewerWidget->grabFramebuffer());
    gifTime += 0.1;
    if (auto_rotate) {
      rotate_matrix(ui->viewerWidget->verts, ui->x_rotate_spinbox->value(),
                        ui->y_rotate_spinbox->value(),
                        ui->z_rotate_spinbox->value());
      ui->viewerWidget->update();
    }
    ui->gif_save_button->setEnabled(false);
    ui->gif_save_button->setText(QString::number(gifTime, 'f', 2));
    ui->gif_save_button->setStyleSheet("color: rgb(255, 10, 10);");

  } else {
    auto_rotate = false;
    gifSave();
    timer->stop();
  }
}

void MainWindow::gifSave() {
  QFileDialog dialog(this);
  QString desktopQString =
      QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
  QString gifQString = dialog.getSaveFileName(this, "Save gif as...",
                                              desktopQString, "GIF (*.gif);;");
  QGifImage gif;
  gif.setDefaultTransparentColor(Qt::black);
  gif.setDefaultDelay(100);
  for (QVector<QImage>::Iterator img = imgQVector.begin();
       img != imgQVector.end(); ++img) {
    QImage imgScaled = img->scaled(640, 480);
    gif.addFrame(imgScaled);
  }
  gif.save(gifQString);
  imgQVector.clear();
  ui->gif_save_button->setEnabled(true);
  ui->gif_save_button->setText(tr("*.gif"));
  ui->gif_save_button->setStyleSheet("color: rgb(255, 255, 255);");
  gifTime = 0.0;
}
