int BinarySearch(int *arr, int x, int low, int high) {
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == x) {
            return mid;
        }
        if (x < arr[mid])
        {
            high = mid - 1;
        }
        else {
            low = mid = 1;
        }
    }
    return -1;
}

