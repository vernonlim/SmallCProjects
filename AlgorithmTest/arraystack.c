#include "arraystack.h"

ArrayStack InitializeArrayStack(size_t* dataArray, size_t maxSize) {
    ArrayStack stack = { dataArray, 0, maxSize };
    return stack;
}

void Push(size_t element, ArrayStack* stack) {
    stack->Array[stack->Count] = element;
    stack->Count++;
}

size_t Pop(ArrayStack* stack) {
    if (stack->Count == 0) {
        fprintf(stderr, "Warning - Stack is empty! Returning the max value...\n");
        return SIZE_MAX;
    }
    stack->Count--;
    return stack->Array[stack->Count];
}

size_t Top(ArrayStack* stack) {
    if (stack->Count == 0) {
        fprintf(stderr, "Warning - Stack is empty! Returning the max value...\n");
        return SIZE_MAX;
    }
    return stack->Array[stack->Count - 1];
}

bool IsStackEmpty(ArrayStack* stack) {
    return stack->Count == 0;
}

ArrayStackDouble InitializeArrayStackDouble(double* dataArray, size_t maxSize) {
    ArrayStackDouble stack = { dataArray, 0, maxSize };
    return stack;
}

void PushDouble(double element, ArrayStackDouble* stack) {
    stack->Array[stack->Count] = element;
    stack->Count++;
}

double PopDouble(ArrayStackDouble* stack) {
    if (stack->Count == 0) {
        fprintf(stderr, "Warning - Stack is empty! Returning the max value...\n");
        return DBL_MAX;
    }
    stack->Count--;
    return stack->Array[stack->Count];
}

double TopDouble(ArrayStackDouble* stack) {
    if (stack->Count == 0) {
        fprintf(stderr, "Warning - Stack is empty! Returning the max value...\n");
        return DBL_MAX;
    }
    return stack->Array[stack->Count - 1];
}

bool IsStackEmptyDouble(ArrayStackDouble* stack) {
    return stack->Count == 0;
}

