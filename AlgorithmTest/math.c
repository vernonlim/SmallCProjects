#include "math.h"

#define EPSILON 0.00000001

double complex ComplexNumericalDerivative(double complex (*func)(double complex x), double complex a) {
    double complex high = func(a + EPSILON + EPSILON*I);
    double complex point = func(a);
    return (high - point) / (EPSILON + EPSILON*I);
}

double NumericalDerivative(double (*func)(double x), double a) {
    double high = func(a + EPSILON);
    double point = func(a);
    return (high - point) / EPSILON;
}

// void CalculatePiSpigot(char* pi, int n) {
//     int numDigits = 0;

//     // the array for predigits 
//     int piArr[n];
//     int heldDigits = 0;
    
//     // the total number of digits in the multi-base form needed to get n decimal digits
//     int digits = ((10 * n)/3) + 1; 

//     // initialize array
//     int a[digits];
//     for (int i = 0; i < digits; i++) {
//         a[i] = 2;
//     }    

//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < digits; j++) {
//             a[j] *= 10;
//         }
//         for (int k = digits - 1; k > 0; k--) {
//             int q = a[k] / (2*k - 1);
//             int r = a[k] % (2*k - 1); 
//             a[k] = r;
//             a[k-1] = a[k-1] + q*(k-1); 
//         }

//         int pq = a[0] / 10;
//         int pr = a[0] % 10;

//         if (pq != 9 && pq != 10) {
//             for (int l = 0; l < heldDigits; l++) {
//                 pi[l + numDigits] = (char) piArr[l];
//             }
//             numDigits += heldDigits;
//             heldDigits = 1;
//             piArr[0] = pq;
//         }
//         if (pq == 9) {
//             piArr[heldDigits] = pq;
//             heldDigits++;
//         }
//         if (pq == 10) {
//             piArr[heldDigits] = 0;
//             heldDigits++;
//             for (int l = 0; l < heldDigits; l++) {
//                 if (piArr[l] == 9) {
//                     piArr[l] = 0;
//                 } else { 
//                     piArr[l] += 1;
//                 }
//             }

//             for (int l = 0; l < heldDigits - 1; l++) {
//                 pi[l + numDigits] = (char) piArr[l];
//             }
//             numDigits += heldDigits - 1;
//             heldDigits = 1;
//             piArr[0] = piArr[heldDigits];
//         }
//     }

// }

