#ifndef BANK_H
#define BANK_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int annuity(double loan_amount, int months, double interest_rate,
                double *monthly_payment, double *over_payment,
                double *total_payment, char *string);

int differentiated(double loan_amount, int months, double interest_rate,
                       double *monthly_payment_first,
                       double *monthly_payment_last, double *over_payment,
                       double *total_payment, char *string);

#define OK 0
#define INCORRECT_STR 1
#define EPS 0.0000001

#endif /* BANK_H */
