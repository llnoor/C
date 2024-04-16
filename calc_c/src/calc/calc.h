#ifndef CALC_H
#define CALC_H

#include <QWidget>

#include "credit.h"
#include "graph.h"

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

class Calc : public QWidget {
  Q_OBJECT

 public:
  Calc(QWidget *parent = nullptr);
  ~Calc();

 private slots:
  void handleButton();
  void openCalc();
  void openGraph();
  void openCredit();
  void openDeposit();

 private:
  Graph *g;
  Credit *c;
  QLabel *label1;
  QLineEdit *mainLineEdit;
  QLineEdit *xLineEdit;
  QPushButton *pushButtonCalc[4];
  QPushButton *digitPushButton[MAX_BUTTON];
  QString someString;
  QComboBox *comboBox;
  QGroupBox *groupBox();
  bool is_result = 1;
};
#endif  // CALC_H
