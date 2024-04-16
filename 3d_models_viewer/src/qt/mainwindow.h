#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QOpenGLWidget>
#include <QPixmap>
#include <QScreen>
#include <QSpinBox>
#include <QTimer>
#include <QtOpenGL>
#include <fstream>

#include "qtgifimage/src/gifimage/qgifimage.h"

extern "C" {
#include "../core/transforms.h"
}

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();
  void saveSettings();
  void readSettings();
  double dmin(double a, double b);
  double dmax(double a, double b);
  void convert_objects(object_t *objects);
  void calc_objects_borders(vertices *vertices);

 private:
  Ui::MainWindow *ui;
  object_t *obj = NULL;

  QByteArray barr =
      (QCoreApplication::applicationDirPath() + "/.settings").toLocal8Bit();
  char *file_path = barr.data();

  QTimer *timer;
  QVector<QImage> imgQVector;
  double gifTime = 0;
  bool auto_rotate = false;
  void gifSave();

 private slots:
  void on_line_width_spinbox_valueChanged(double arg1);
  void on_point_size_spinbox_valueChanged(double arg1);

  void on_r_back_color_spinbox_valueChanged(int arg1);
  void on_g_back_color_spinbox_valueChanged(int arg1);
  void on_b_back_color_spinbox_valueChanged(int arg1);

  void on_r_point_color_spinbox_valueChanged(int arg1);
  void on_g_point_color_spinbox_valueChanged(int arg1);
  void on_b_point_color_spinbox_valueChanged(int arg1);

  void on_r_line_color_spinbox_valueChanged(int arg1);
  void on_g_line_color_spinbox_valueChanged(int arg1);
  void on_b_line_color_spinbox_valueChanged(int arg1);

  void on_projection_type_comboBox_currentIndexChanged(int index);
  void on_point_type_comboBox_currentIndexChanged(int index);
  void on_line_type_comboBox_currentIndexChanged(int index);

  void on_jpg_save_button_clicked();
  void on_gif_save_button_clicked();
  void on_open_file_button_clicked();
  void on_apply_transforms_button_clicked();
  void gifRecord();
  void on_reset_transforms_button_clicked();
};
#endif  // MAINWINDOW_H
