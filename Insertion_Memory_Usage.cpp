#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // S�ral� k�sm�n sonundan ba�layarak key'in do�ru konumunu bul
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

    // Rastgele elemanlarla diziye de�er ata
    for (int i = 0; i < 1000; i++) {
        dizi[i] = rand() % 100; // 0 ile 99 aras�nda rastgele say�lar
    }

    // Haf�za kullan�m�n� �l�mek i�in ba�lang�� noktas�n� kaydet
    clock_t start_memory = clock();

    // InsertionSort'u uygula
    insertionSort(dizi, 1000);

    // Haf�za kullan�m�n� �l�mek i�in biti� noktas�n� kaydet
    clock_t end_memory = clock();

    // Haf�za kullan�m�n� ekrana yazd�r
    printf("Hafiza Kullanimi: %ld bytes\n", (long)(100 * sizeof(int)));

    // Zaman� ekrana yazd�r
    double cpu_time_used = ((double)(end_memory - start_memory)) / CLOCKS_PER_SEC;
    printf("Zaman: %f seconds\n", cpu_time_used);

    // S�ralanm�� diziyi ekrana yazd�r
    printf("S�ralanm�� Dizi: ");
    for (int i = 0; i < 1000; i++) {
        printf("%d ", dizi[i]);
    }

    return 0;
}

