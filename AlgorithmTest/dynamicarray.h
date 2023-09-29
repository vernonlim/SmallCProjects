#ifndef _DYNAMICARRAY_H_
#define _DYNAMICARRAY_H_

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct {
    void *start;
    int elementSize;
    int count;
    int allocatedSize;
} DynamicArray;

DynamicArray *Initialize(int elementSize, int initialCount);
void FreeArray(DynamicArray *arr);
void EnsureSpace(int size, DynamicArray *arr);
void PushArray(void *element, DynamicArray *arr);
void PopArray(DynamicArray *arr);
int IsInBounds(int index, DynamicArray *arr);
int TrySetElement(int index, void *element, DynamicArray *arr);
void *TryGetElement(int index, DynamicArray *arr);
int TryInsertElement(int index, void *element, DynamicArray *arr);
int TryRemoveElement(int index, DynamicArray *arr);
int FirstIndexOf(void *element, DynamicArray *arr);
void Trim(DynamicArray *arr);
void PrintDynamicArray(DynamicArray *arr);
void *TopArray(DynamicArray *arr);

#endif
