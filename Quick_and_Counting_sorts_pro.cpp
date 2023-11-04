#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

void countingSort(int arr[], int n) {
    int max = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    int* count = (int*)malloc((max + 1) * sizeof(int));
    for (int i = 0; i <= max; i++) {
        count[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    int index = 0;
    for (int i = 0; i <= max; i++) {
        while (count[i] > 0) {
            arr[index] = i;
            index++;
            count[i]--;
        }
    }

    free(count);
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    int sizes[] = {10, 100, 1000, 10000, 100000};

    for (int k = 0; k < 5; k++) {
        int size = sizes[k];

        int* arr1 = (int*)malloc(size * sizeof(int));
        int* arr2 = (int*)malloc(size * sizeof(int));

        // Rastgele elemanlarla diziyi doldur
        for (int i = 0; i < size; i++) {
            arr1[i] = rand() % 100001; // 0 ile 100000 arasýnda rastgele sayýlar
            arr2[i] = arr1[i];
        }

        // QuickSort
        clock_t start_time = clock();
        quickSort(arr1, 0, size - 1);
        clock_t end_time = clock();
        double cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

        printf("QuickSort - Size: %d, Time: %f seconds\n", size, cpu_time_used);

        // CountingSort
        start_time = clock();
        countingSort(arr2, size);
        end_time = clock();
        cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

        printf("CountingSort - Size: %d, Time: %f seconds\n", size, cpu_time_used);

        free(arr1);
        free(arr2);
    }

    return 0;
}

