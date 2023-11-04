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

int main() {
    srand(time(NULL));
    int dizi[10000];

    // Rastgele elemanlarla diziye deðer ata
    for (int i = 0; i < 10000; i++) {
        dizi[i] = rand() % 1000000; // 0 ile 99 arasýnda rastgele sayýlar
    }

    // Hafýza kullanýmýný ölçmek için baþlangýç noktasýný kaydet
    clock_t start_memory = clock();

    // QuickSort'u uygula
    quickSort(dizi, 0, 9999);

    // Hafýza kullanýmýný ölçmek için bitiþ noktasýný kaydet
    clock_t end_memory = clock();

    // Hafýza kullanýmýný ekrana yazdýr
    printf("Hafiza Kullanimi: %ld bytes\n", (long)sizeof(dizi));

    // Zamaný ekrana yazdýr
    double cpu_time_used = ((double)(end_memory - start_memory)) / CLOCKS_PER_SEC;
    printf("Zaman: %f seconds\n", cpu_time_used);

    // Sýralanmýþ diziyi ekrana yazdýr
    printf("Sýralanmýþ Dizi: ");
    for (int i = 0; i < 10000; i++) {
        printf("%d ", dizi[i]);
    }

    return 0;
}

