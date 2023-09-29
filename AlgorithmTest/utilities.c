#include "utilities.h"
#include "stockspan.h"
#include <stdlib.h>

#define TEST_RAND_MAX 100000
#define SPAN_RAND_MAX 100000

void PrintIntArray(int *arr, int min, int max) {
    for (int i = min; i <= max; i++) {
        printf("%d\n", arr[i]);
    }
}

void PrintSizeArray(size_t* arr, size_t min, size_t max) {
    for (size_t i = min; i <= max; i++) {
        printf("%zu\n", arr[i]);
    }
}

void FillArrayWithRandom(int *arr, int arrLen, int min, int max) {
    for (int i = 0; i < arrLen; i++) {
        arr[i] = (rand() % (max - min + 1) + min);
    }
}

void FillSizeArrayWithRandom(size_t* arr, size_t arrLen, size_t min, size_t max) {
    for (size_t i = 0; i < arrLen; i++) {
        arr[i] = (rand() % (max - min + 1) + min);
    }
}

int IsSorted(int *arr, int min, int max) {
    for (int i = min; i < max; i++) {
        if (arr[i] > arr[i + 1]) {
            return 0;
        }
    }

    return 1;
}

void PrintSuccessOrFailure(bool b) {
    if (b) {
        printf("Success!\n");
    } else {
        printf("Failure.\n");
    }
}

int SortTest(void (*sortFunc)(int *arr, int min, int max), int arrLen, int repetitions) {
    double totalTime = 0;

    for (int r = 0; r < repetitions; r++) {
        int arr[arrLen];
        FillArrayWithRandom(arr, arrLen, 0, TEST_RAND_MAX);

        /*
            printf("Repetition %d:\n", r);
            printf("Before:\n");
            PrintIntArray(arr, 0, arrLen - 1);
        */

        double startTime = (double)clock()/CLOCKS_PER_SEC;

        sortFunc(arr, 0, arrLen - 1);

        double endTime = (double)clock()/CLOCKS_PER_SEC;
        double timeElapsed = endTime - startTime;
        totalTime += timeElapsed;

        /*
            printf("Sorted:\n");
            PrintIntArray(arr, 0, arrLen - 1);
        */

        if (!IsSorted(arr, 0, arrLen - 1)) {
            return 0;
        }
    }

    printf("Total Time Taken: %f\n", totalTime);
    printf("Average Time Taken: %f\n", totalTime/repetitions);

    return 1;
}

int SortTestWorkArray(void (*sortFunc)(int *sourceArr, int *workArr, int min, int max), int arrLen, int repetitions) {
    double totalTime = 0;

    for (int r = 0; r < repetitions; r++) {
        int arr[arrLen];
        int arrW[arrLen];

        /*
            printf("Repetition %d:\n", r);
            printf("Before:\n");
            PrintIntArray(arr, 0, arrLen - 1);
        */

        double startTime = (double)clock()/CLOCKS_PER_SEC;

        sortFunc(arr, arrW, 0, arrLen - 1);

        double endTime = (double)clock()/CLOCKS_PER_SEC;
        double timeElapsed = endTime - startTime;
        totalTime += timeElapsed;

        /*
            printf("Sorted:\n");
            PrintIntArray(arr, 0, arrLen - 1);
        */

        if (!IsSorted(arr, 0, arrLen - 1)) {
            return 0;
        }
    }

    printf("Total Time Taken: %f\n", totalTime);
    printf("Average Time Taken: %f\n", totalTime/repetitions);

    return 1;
}

bool SpanTest(void (*func)(size_t*, size_t, size_t*), size_t arrLen, size_t repetitions) {
    double totalTime = 0;

    // bool IsEqualOverall = true;
    for (size_t r = 0; r < repetitions; r++) {
        size_t* arr = malloc(sizeof(size_t) * arrLen);
        FillSizeArrayWithRandom(arr, arrLen, 0, SPAN_RAND_MAX);
        size_t* arrR = malloc(sizeof(size_t) * arrLen);

            // printf("Repetition %zu:\n", r);
            // printf("Before:\n");
            // PrintSizeArray(arr, 0, arrLen - 1);

        double startTime = (double)clock()/CLOCKS_PER_SEC;

        func(arr, arrLen, arrR);

        double endTime = (double)clock()/CLOCKS_PER_SEC;
        double timeElapsed = endTime - startTime;
        totalTime += timeElapsed;

        //     printf("After:\n");
        //     PrintSizeArray(arrR, 0, arrLen - 1);

        // size_t arrRO[arrLen];
        // StockSpanStackSolution(arr, arrLen, arrRO);      
        // bool IsEqual = true;
        // for (size_t i = 0; i < arrLen; i++) {
        //     if (arrR[i] != arrRO[i]) {
        //         IsEqual = false;
        //         IsEqualOverall = false;
        //     }
        // }
        // IsEqual ? printf("Equal!\n") : printf("Not Equal!\n");
        free(arr);
        free(arrR);
    }

    printf("Total Time Taken: %f\n", totalTime);
    printf("Average Time Taken: %f\n", totalTime/repetitions);
    // IsEqualOverall ? printf("Equal Overall!\n") : printf("Not Equal Overall!\n");

    return true;
}

bool IsCharIn(char input, char* arr, size_t len) {
    for (size_t i = 0; i < len; i++) {
        if (input == arr[i]) {
            return true;
        }
    }
    return false;
}
