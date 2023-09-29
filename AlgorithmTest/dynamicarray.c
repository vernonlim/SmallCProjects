#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include "dynamicarray.h"

DynamicArray *Initialize(int elementSize, int initialCount) {
    int initialSize = elementSize * initialCount;

    DynamicArray *arr = malloc(sizeof(DynamicArray));
    arr->start = malloc(initialSize);
    arr->elementSize = elementSize;
    arr->count = 0;
    arr->allocatedSize = initialSize;

    return arr;
}

void FreeArray(DynamicArray *arr) {
    free(arr->start);
    free(arr);
}

void EnsureSpace(int size, DynamicArray *arr) {
    int remainingSpace = arr->allocatedSize - (arr->count * arr->elementSize);
    if (remainingSpace < size) {
        arr->start = realloc(arr->start, arr->allocatedSize * 2);
        arr->allocatedSize *= 2;
    }    
}

void PushArray(void *element, DynamicArray *arr) {
    EnsureSpace(arr->elementSize, arr);
    memcpy((char*)arr->start + (arr->count * arr->elementSize), element, arr->elementSize); 
    arr->count++;
}

void PopArray(DynamicArray *arr) {
    memset((char*)arr->start + (arr->count * arr->elementSize), 0, arr->elementSize);
    arr->count--;
}

int IsInBounds(int index, DynamicArray *arr) {
    if (index < 0 || index > arr->count - 1) {
        return false;
    }

    return true;
}

int TrySetElement(int index, void *element, DynamicArray *arr) {
    if (IsInBounds(index, arr)) {
        memcpy((char*)arr->start + (index * arr->elementSize), element, arr->elementSize);
        return true;
    }
    
    return false;
}

void *TryGetElement(int index, DynamicArray *arr) {
    if (IsInBounds(index, arr)) {
        return ((char*)arr->start + (index * arr->elementSize));
    }

    return NULL;
}

int TryInsertElement(int index, void *element, DynamicArray *arr) {
    EnsureSpace(arr->elementSize, arr);
    if (IsInBounds(index, arr)) {
        for (int i = arr->count; i >= index; i--) {
            memcpy(((char*)arr->start + ((i + 1) * arr->elementSize)), ((char*)arr->start + (i * arr->elementSize)), arr->elementSize);
        }
        memcpy((char*)arr->start + (index * arr->elementSize), element, arr->elementSize);
        arr->count++;
        return true;
    }

    return false;
}

int TryRemoveElement(int index, DynamicArray *arr) {
    if (IsInBounds(index, arr)) {
        memset((char*)arr->start + (index * arr->elementSize), 0, arr->elementSize);
        for (int i = index + 1; i <= arr->count; i++) {
            memcpy(((char*)arr->start + ((i - 1) * arr->elementSize)), ((char*)arr->start + (i * arr->elementSize)), arr->elementSize);
        }
        arr->count--;
        return true;
    }

    return false;
}

int FirstIndexOf(void *element, DynamicArray *arr) {
    for (int i = 0; i < arr->count; i++) {
        if (memcmp((char*)arr->start + (i * arr->elementSize), element, arr->elementSize) == 0) {
            return i;
        }
    }

    return -1;
}

void Trim(DynamicArray *arr) {
    int trimmedSize = arr->count * arr->elementSize;
    arr->start = realloc(arr->start, trimmedSize);    
    arr->allocatedSize = trimmedSize;
}

void PrintDynamicArray(DynamicArray *arr) {
    for (int i = 0; i < arr->count; i++) {
        printf("%d\n", *(int*)TryGetElement(i, arr));
    }
}

void *TopArray(DynamicArray *arr) {
    return TryGetElement(arr->count - 1, arr);
}
