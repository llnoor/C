#ifndef CREDIT_H
#define CREDIT_H

#include <QWidget>

class QPushButton;
class QLineEdit;
class QLabel;
class QComboBox;
class QTextEdit;

QT_BEGIN_NAMESPACE
class QGroupBox;
QT_END_NAMESPACE

extern "C" {
#include "../bank.h"
}

class Credit : public QWidget {
  Q_OBJECT

 public:
  Credit(QWidget *parent = nullptr);
  ~Credit();

 Q_SIGNALS:
  void openCalc();
  void openGraph();
  void closeAll();

 private slots:
  void handleButton();

 private:
  QLabel *label1;
  QLineEdit *mainLineEdit;
  QLineEdit *xLineEdit;
  QPushButton *pushButtonCalc[4];
  QString someString;
  QComboBox *comboBox;
  QGroupBox *groupBox();

  QLabel *loanAmountQLabel;
  QLabel *periodQLabel;
  QLabel *interestRateQLabel;
  QLabel *typeQLabel;
  QLabel *monthlyPaymentQLabel;
  QLabel *overPaymentQLabel;
  QLabel *totalPaymentQLabel;

  QLineEdit *loanAmountQLineEdit;
  QLineEdit *periodQLineEdit;
  QLineEdit *interestRateQLineEdit;
  QComboBox *typeQComboBox;
  QLineEdit *monthlyPaymentQLineEdit;
  QLineEdit *overPaymentQLineEdit;
  QLineEdit *totalPaymentQLineEdit;

  QTextEdit *editQTextEdit;

  QPushButton *creditQPushButton;

  bool is_result = 1;
};
#endif  // CREDIT_H
