#include <stdio.h>
#include <time.h>

//perform binary search using recursion
int binarySearchRecursive(int arr[], int low, int high, int key) {
    if (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
            return mid;

        if (arr[mid] < key)
            return binarySearchRecursive(arr, mid + 1, high, key);

        return binarySearchRecursive(arr, low, mid - 1, key);
    }

    return -1;
}

int main() {
    printf("Asa Gordon, zqi674\n");

    int size = 5;
    int arr[size];
    printf("Binary search (recursive approach)\n");
    printf("Enter %d elements:\n", size);

    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    int key;
    printf("Enter key element to search: ");
    scanf("%d", &key);
    printf("Key element: %d\n", key);
    clock_t start = clock();
    int recursiveResult = binarySearchRecursive(arr, 0, size - 1, key);
    clock_t end = clock();
    if (recursiveResult != -1) {
        printf("Key element found at index: %d\n", recursiveResult);
    } else {
        printf("Key element not found.\n");
    }
    double cpu_time_recursive = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Total time taken by CPU (End time - Start time) / clock per_sec: %lf\n", cpu_time_recursive);

    return 0;
}