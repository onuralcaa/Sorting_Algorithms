#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Sýralý kýsmýn sonundan baþlayarak key'in doðru konumunu bul
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    srand(time(NULL));
    int dizi[1000];

    // Rastgele elemanlarla diziye deðer ata
    for (int i = 0; i < 1000; i++) {
        dizi[i] = rand() % 100; // 0 ile 99 arasýnda rastgele sayýlar
    }

    // Hafýza kullanýmýný ölçmek için baþlangýç noktasýný kaydet
    clock_t start_memory = clock();

    // InsertionSort'u uygula
    insertionSort(dizi, 1000);

    // Hafýza kullanýmýný ölçmek için bitiþ noktasýný kaydet
    clock_t end_memory = clock();

    // Hafýza kullanýmýný ekrana yazdýr
    printf("Hafiza Kullanimi: %ld bytes\n", (long)(100 * sizeof(int)));

    // Zamaný ekrana yazdýr
    double cpu_time_used = ((double)(end_memory - start_memory)) / CLOCKS_PER_SEC;
    printf("Zaman: %f seconds\n", cpu_time_used);

    // Sýralanmýþ diziyi ekrana yazdýr
    printf("Sýralanmýþ Dizi: ");
    for (int i = 0; i < 1000; i++) {
        printf("%d ", dizi[i]);
    }

    return 0;
}

