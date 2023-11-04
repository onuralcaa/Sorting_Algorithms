#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void countingSort(int arr[], int n) {
    int max = 0;

    // Dizideki en büyük elemaný bul
    for (int i = 0; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // Count array oluþtur ve sýfýrla
    int* count = (int*)malloc((max + 1) * sizeof(int));
    for (int i = 0; i <= max; i++) {
        count[i] = 0;
    }

    // Dizideki elemanlarýn frekanslarýný say
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // Sýralanmýþ diziyi oluþtur
    int* sorted = (int*)malloc(n * sizeof(int));
    for (int i = n - 1; i >= 0; i--) {
        sorted[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Bellekten ayrýlan alanlarý serbest býrak
    free(count);
    free(sorted);
}

int main() {
    srand(time(NULL));
    int dizi[10];

    // Rastgele elemanlarla diziye deðer ata
    for (int i = 0; i < 10; i++) {
        dizi[i] = rand() % 100; // 0 ile 99 arasýnda rastgele sayýlar
    }

    // Hafýza kullanýmýný ölçmek için baþlangýç noktasýný kaydet
    clock_t start_memory = clock();

    // CountingSort'u uygula
    countingSort(dizi, 10);

    // Hafýza kullanýmýný ölçmek için bitiþ noktasýný kaydet
    clock_t end_memory = clock();

    // Hafýza kullanýmýný ekrana yazdýr
    printf("Hafiza Kullanimi: %ld bytes\n", (long)(10 * sizeof(int)));

    // Zamaný ekrana yazdýr
    double cpu_time_used = ((double)(end_memory - start_memory)) / CLOCKS_PER_SEC;
    printf("Zaman: %f seconds\n", cpu_time_used);

    // Sýralanmýþ diziyi ekrana yazdýr
    printf("Sýralanmýþ Dizi: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", dizi[i]);
    }

    return 0;
}

