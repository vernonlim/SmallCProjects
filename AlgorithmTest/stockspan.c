#include "stockspan.h"

void StockSpanNaiveSolution(size_t* quotes, size_t len, size_t* resultArray) {
    for (size_t i = 0; i < len; i++) {
        size_t k = 0;
        for (; i - k > 0 && quotes[i - (k + 1)] <= quotes[i]; k++);

        resultArray[i] = k + 1;
    }
}

void StockSpanStackSolution(size_t* quotes, size_t len, size_t* resultArray) {
    size_t* data = malloc(sizeof(size_t) * len);
    ArrayStack stack = InitializeArrayStack(data, len);
    Push(0, &stack);
    resultArray[0] = 1;
    for (size_t i = 1; i < len; i++) {
        for (; !IsStackEmpty(&stack) && quotes[i] >= quotes[Top(&stack)]; Pop(&stack));
        if (IsStackEmpty(&stack)) {
            resultArray[i] = i + 1;
        } else {
            resultArray[i] = i - Top(&stack);
        }
        Push(i, &stack);
    }
    free(data);
}
