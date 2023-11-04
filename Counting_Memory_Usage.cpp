#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void countingSort(int arr[], int n) {
    int max = 0;

    // Dizideki en b�y�k eleman� bul
    for (int i = 0; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // Count array olu�tur ve s�f�rla
    int* count = (int*)malloc((max + 1) * sizeof(int));
    for (int i = 0; i <= max; i++) {
        count[i] = 0;
    }

    // Dizideki elemanlar�n frekanslar�n� say
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // S�ralanm�� diziyi olu�tur
    int* sorted = (int*)malloc(n * sizeof(int));
    for (int i = n - 1; i >= 0; i--) {
        sorted[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Bellekten ayr�lan alanlar� serbest b�rak
    free(count);
    free(sorted);
}

int main() {
    srand(time(NULL));
    int dizi[10];

    // Rastgele elemanlarla diziye de�er ata
    for (int i = 0; i < 10; i++) {
        dizi[i] = rand() % 100; // 0 ile 99 aras�nda rastgele say�lar
    }

    // Haf�za kullan�m�n� �l�mek i�in ba�lang�� noktas�n� kaydet
    clock_t start_memory = clock();

    // CountingSort'u uygula
    countingSort(dizi, 10);

    // Haf�za kullan�m�n� �l�mek i�in biti� noktas�n� kaydet
    clock_t end_memory = clock();

    // Haf�za kullan�m�n� ekrana yazd�r
    printf("Hafiza Kullanimi: %ld bytes\n", (long)(10 * sizeof(int)));

    // Zaman� ekrana yazd�r
    double cpu_time_used = ((double)(end_memory - start_memory)) / CLOCKS_PER_SEC;
    printf("Zaman: %f seconds\n", cpu_time_used);

    // S�ralanm�� diziyi ekrana yazd�r
    printf("S�ralanm�� Dizi: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", dizi[i]);
    }

    return 0;
}

