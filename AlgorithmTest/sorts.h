#ifndef _SORTS_H_
#define _SORTS_H_

#include <stdio.h>
#include <stdbool.h>

// sorting utilities
void CopyArray(int *a, int *b, int min, int max);
void Swap(int *a, int *b);
void TopDownMerge(int *arrB, int min, int mid, int max, int *arrA);
int Partition(int *arr, int min, int max);

// actual sorts
void BubbleSort(int *arr, int min, int max);
void InsertionSort(int *arr, int min, int max);
// void insertionSort2(int *arr, int min, int max);
// void insertionSort3(int *arr, int min, int max);
void SelectionSort(int *arr, int min, int max);
void TopDownMergeSort(int *sourceArr, int *workArr, int min, int max);
void QuickSort(int *arr, int min, int max);
void ShittySort(int *arr, int min, int max);

#endif // _SORTS_H_
