#ifndef _ARRAYSTACK_H_
#define _ARRAYSTACK_H_

#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include <float.h>

typedef struct {
    size_t* Array;
    size_t Count;
    size_t MaxSize;
} ArrayStack;

typedef struct {
    double* Array;
    size_t Count;
    size_t MaxSize;
} ArrayStackDouble;

ArrayStack InitializeArrayStack(size_t* dataArray, size_t maxSize);
void Push(size_t element, ArrayStack* stack);
size_t Pop(ArrayStack* stack);
size_t Top(ArrayStack* stack);
bool IsStackEmpty(ArrayStack* stack);
bool IsStackFull(ArrayStack* stack);

ArrayStackDouble InitializeArrayStackDouble(double* dataArray, size_t maxSize);
void PushDouble(double element, ArrayStackDouble* stack);
double PopDouble(ArrayStackDouble* stack);
double TopDouble(ArrayStackDouble* stack);
bool IsStackEmptyDouble(ArrayStackDouble* stack);
bool IsStackFullDouble(ArrayStackDouble* stack);

#endif
