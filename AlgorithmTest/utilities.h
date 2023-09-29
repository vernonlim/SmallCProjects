#ifndef _UTILITIES_H_
#define _UTILITIES_H_

#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// utilities.c
void PrintIntArray(int *arr, int min, int max);
void PrintSizeArray(size_t* arr, size_t min, size_t max);
void FillArrayWithRandom(int *arr, int arrLen, int min, int max);
int IsSorted(int *arr, int min, int max);
void PrintSuccessOrFailure(bool b);
int SortTest(void (*sortFunc)(int *, int, int), int arrLen, int repetitions);
int SortTestWorkArray(void (*sortFunc)(int *, int *, int, int), int arrLen, int repetitions);
bool SpanTest(void (*func)(size_t*, size_t, size_t*), size_t arrLen, size_t repetitions);
bool IsCharIn(char input, char* arr, size_t len);

#endif // _UTILITIES_H_
