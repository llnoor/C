#include "bank.h"

int annuity(double loan_amount, int months, double interest_rate,
                double *monthly_payment, double *over_payment,
                double *total_payment, char *string) {
  int flag = OK;
  if (loan_amount <= 0 || months <= 0 || interest_rate <= 0)
    flag = INCORRECT_STR;
  double monthly_interest_rate = interest_rate / 12 / 100;
  double temp_ar = pow(monthly_interest_rate + 1, months);
  double annuity_ratio = monthly_interest_rate * temp_ar / (temp_ar - 1);
  *monthly_payment = annuity_ratio * loan_amount;
  *total_payment = *monthly_payment * months;
  *over_payment = *total_payment - loan_amount;

  *string = '\0';
  char temp_char[255] = " ";
  sprintf(temp_char, "Month\t\tPayment\t\tInterest\tBalance owed\n");
  strcat(string, temp_char);
  double balance_owed = loan_amount;
  double interest_payment = balance_owed * monthly_interest_rate;
  int checker = 0;
  for (int current_month = 0; current_month < months; current_month++) {
    balance_owed = balance_owed - *monthly_payment + interest_payment;
    if (months > 25 && current_month == 11 && checker == 0) {
      strcat(string, "........\n");
      checker = 1;
    }
    if (months < 25 || (months > 25 && current_month < 10) ||
        (months > 25 && current_month > months - 11)) {
      char temp_char[255] = " ";
      sprintf(temp_char, "%d\t\t%.2lf\t\t%.2lf\t\t%.2lf\n", current_month + 1,
              *monthly_payment, interest_payment, fabs(balance_owed));
      strcat(string, temp_char);
    }
    interest_payment = balance_owed * monthly_interest_rate;
  }
  return flag;
}

int differentiated(double loan_amount, int months, double interest_rate,
                       double *monthly_payment_first,
                       double *monthly_payment_last, double *over_payment,
                       double *total_payment, char *string) {
  int flag = OK;
  if (loan_amount <= 0 || months <= 0 || interest_rate <= 0)
    flag = INCORRECT_STR;
  *total_payment = 0.0;

  double basic_payment = loan_amount / months;
  double balance_owed = loan_amount;
  double monthly_payment = 0;
  double interest_payment = 0;

  *monthly_payment_first =
      basic_payment + loan_amount * interest_rate / 12 / 100;
  *monthly_payment_last = 0.0;

  *string = '\0';
  char temp_char[255] = " ";
  sprintf(temp_char, "Month\t\tPayment\t\tInterest\tBalance owed\n");
  strcat(string, temp_char);
  int checker = 0;
  for (int current_month = 0; current_month < months; current_month++) {
    interest_payment = balance_owed * interest_rate / 12 / 100;
    monthly_payment = basic_payment + interest_payment;
    *total_payment = *total_payment + monthly_payment;
    balance_owed = loan_amount - basic_payment * (current_month + 1);
    if (months > 25 && current_month == 11 && checker == 0) {
      strcat(string, "........\n");
      checker = 1;
    }
    if (months < 25 || (months > 25 && current_month < 10) ||
        (months > 25 && current_month > months - 11)) {
      char temp_char[255] = " ";
      sprintf(temp_char, "%d\t\t%.2lf\t\t%.2lf\t\t%.2lf\n", current_month + 1,
              monthly_payment, interest_payment, fabs(balance_owed));
      strcat(string, temp_char);
    }
    *monthly_payment_last = monthly_payment;
  }
  *over_payment = *total_payment - loan_amount;
  return flag;
}
