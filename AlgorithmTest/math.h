#ifndef _MATH_H_
#define _MATH_H_

#include <stdbool.h>
#include <complex.h>

double NumericalDerivative(double (*func)(double x), double a);
double complex ComplexNumericalDerivative(double complex (*func)(double complex x), double complex a);
char* CalculatePiBBP(int n);
void CalculatePiSpigot(char* pi, int n);

#endif
