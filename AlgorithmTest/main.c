#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "utilities.h"
#include "sorts.h"
#include "searches.h"
#include "math.h"
#include <complex.h>
#include "stockspan.h"
#include "rpncalc.h"

double function(double x) {
    return x*x;
}

double complex ComplexFunction(double complex x) {
    return x*x;
}

int main() {
    srand(time(NULL));

    // PrintSuccessOrFailure(SortTest(QuickSort, 1000, 10000));
    // PrintSuccessOrFailure(SortTestWorkArray(TopDownMergeSort, 1000, 10000));
    // PrintSuccessOrFailure(SortTest(InsertionSort, 1000, 10000));
    
    // printf("%f\n", NumericalDerivative(function, 3));
    // double complex value = 2 + 3*I;
    // double complex derivative = ComplexNumericalDerivative(ComplexFunction, value);
    // printf("%f%+fi\n", crealf(derivative), cimagf(derivative));
    // printf("%d\n", 0b11000011);
    // printf("%d\n", 0b11110011);
    // printf("%d\n", 0b11000011 - 0b11110011);
    // printf("%0.100f\n", 1.0E-13 + 1.0E-13);
    // printf("%0.100f\n", 1.0E-13);
    // printf("%0.100f\n", (1.0E-13 + (1.0E-13 + 1.0)) - 1.0);
    // size_t quotes[] = { 1, 2, 8, 6, 3, 8, 9, };
    // size_t spans[7];
    // StockSpanStackSolution(quotes, 7, spans);
    // for (size_t i = 0; i < 7; i++) {
    //     printf("%zu\n", spans[i]);
    // }
    // printf("Tests with 1M elements in array, 100 repetitions\n");
    // SpanTest(StockSpanNaiveSolution, 1000000, 100);
    // SpanTest(StockSpanStackSolution, 1000000, 100);

    // printf("Tests with 5M elements in array, 100 repetitions\n");
    // SpanTest(StockSpanNaiveSolution, 5000000, 100);
    // SpanTest(StockSpanStackSolution, 5000000, 100);

    CalculateInputRPN();
}
