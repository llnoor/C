#ifndef GRAPH_H
#define GRAPH_H

#include <QChart>
#include <QChartView>
#include <QLineSeries>
#include <QLogValueAxis>
#include <QValueAxis>
#include <QWidget>
#include <QtWidgets>

#define MAX_BUTTON 40

class QPushButton;
class QLineEdit;
class QLabel;
class QComboBox;

QT_BEGIN_NAMESPACE
class QGroupBox;
QT_END_NAMESPACE

extern "C" {
#include "../stack.h"
#include "../string.h"
}

class Graph : public QWidget {
  Q_OBJECT

 public:
  Graph(QWidget *parent = nullptr);
  ~Graph();

 Q_SIGNALS:
  void openCalc();
  void openCredit();
  void closeAll();

 private slots:
  void handleButton();

 private:
  QLabel *label1;
  QLineEdit *xFromLineEdit;
  QLineEdit *xFromToLineEdit;
  QLineEdit *xToLineEdit;
  QLineEdit *mainLineEdit;
  QLineEdit *xLineEdit;
  QPushButton *pushButtonCalc[4];
  QPushButton *digitPushButton[MAX_BUTTON];
  QString someString;
  QComboBox *comboBox;
  QGroupBox *groupBox();

  QChartView *chartView;
  QLineSeries *series;
  QChart *chart;
  QValueAxis *axisX;
  QValueAxis *axisY;

  bool is_result = 1;
};
#endif  // GRAPH_H
