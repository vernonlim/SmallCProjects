#include "sorts.h"

// sorting utilities
void CopyArray(int *a, int *b, int min, int max) {
    for (int k = min; k <= max; k++) {
        b[k] = a[k];
    }
}

void Swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void TopDownMerge(int *arrB, int min, int mid, int max, int *arrA) {
    int i = min;
    int j = mid + 1;

    for (int k = min; k <= max; k++) {
        if (i <= mid && (j > max || arrA[i] <= arrA[j])) {
            arrB[k] = arrA[i];
            i++;
        } else {
            arrB[k] = arrA[j];
            j++;
        }
    }
}

void TopDownSplitMerge(int *arrB, int min, int max, int *arrA) {
    if (max - min <= 0) {
        return;
    }

    int mid = (max + min) / 2;

    TopDownSplitMerge(arrA, min, mid, arrB);
    TopDownSplitMerge(arrA, mid + 1, max, arrB);

    TopDownMerge(arrB, min, mid, max, arrA);
}

int Partition(int *arr, int min, int max) {
    int pivot = arr[(max - min)/2 + min];
    int i = min - 1;
    int j = max + 1;

    while (true) {
        do {
            i++;
        } while (arr[i] < pivot);

        do {
            j--;
        } while (arr[j] > pivot);

        if (i >= j) {
            return j;
        }        
        Swap(arr + i, arr + j);
    }
}

// sorts
void BubbleSort(int *arr, int min, int max) {
    while (min < max) {
        for (int i = min; i < max; i++) {
            if (arr[i] > arr[i + 1]) {
                Swap(arr + i, arr + (i + 1));
            }
        }
        max--;
    }
}

void InsertionSort(int *arr, int min, int max) {
    for (int sortedIndex = min; sortedIndex < max; sortedIndex++) {
        int insertValue = arr[sortedIndex + 1];
        int workingIndex = sortedIndex;

        for (; workingIndex >= 0 && arr[workingIndex] > insertValue; workingIndex--) {
            arr[workingIndex + 1] = arr[workingIndex];
        }
        arr[workingIndex + 1] = insertValue;
    }
}

void InsertionSortWiki(int *arr, int arrLen) {
    int i = 1;
    while (i < arrLen) {
        int x = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > x) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = x;
        i = i + 1;
    }
}

/*
void insertionSort2(int *arr, int min, int max) {
    if (min < max && arr[min] > arr[min + 1]) {
        swap(arr + min, arr + min + 1);
    }
    for (int sortedIndex = min + 1; sortedIndex < max; sortedIndex++) {
        int insertValue = arr[sortedIndex + 1];
        int workingIndex = sortedIndex;
        for (; workingIndex >= min && arr[workingIndex] > insertValue; workingIndex--) {
            arr[workingIndex + 1] = arr[workingIndex];
        }
        arr[workingIndex + 1] = insertValue;
    }
}

void insertionSort3(int *arr, int min, int max) {
    if (min < max && arr[min] > arr[min + 1]) {
        int insertValue = arr[min + 1];
        arr[min + 1] = arr[min];
        arr[min] = insertValue;
    }
    for (int sortedIndex = min + 1; sortedIndex < max; sortedIndex++) {
        int insertValue = arr[sortedIndex + 1];
        int workingIndex = sortedIndex;
        for (; workingIndex >= min && arr[workingIndex] > insertValue; workingIndex--) {
            arr[workingIndex + 1] = arr[workingIndex];
        }
        arr[workingIndex + 1] = insertValue;
    }
}
*/

void SelectionSort(int *arr, int min, int max) {
    for (int i = min; i < max; i++) {
        int *smallest = arr + i;
        for (int j = i + 1; j <= max; j++) {
            if (arr[j] < *smallest) {
                smallest = arr + j;
            }
        }
        Swap(arr + i, smallest);
    }
}

void TopDownMergeSort(int *sourceArr, int *workArr, int min, int max) {
    CopyArray(sourceArr, workArr, min, max);
    TopDownSplitMerge(sourceArr, min, max, workArr);
}

void QuickSort(int *arr, int min, int max) {
    if (min < max) {
        int p = Partition(arr, min, max);
        QuickSort(arr, min, p);
        QuickSort(arr, p + 1, max);
    }    
}

void ShittySort(int *arr, int min, int max) {
    
}
