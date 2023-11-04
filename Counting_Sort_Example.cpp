#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Counting Sort Fonksiyonu
void counting_sort(int A[], int k, int n, int B[]) 
{
    int C[100001];

    for (int i = 0; i <= k; i++)
        C[i] = 0;

    for (int j = 0; j < n; j++)
        C[A[j]] = C[A[j]] + 1;

    for (int i = 1; i <= k; i++)
        C[i] = C[i] + C[i - 1];

    for (int j = n - 1; j >= 0; j--) 
	{
        B[C[A[j]] - 1] = A[j];
        C[A[j]] = C[A[j]] - 1;
    }

    // De�i�iklik: S�ralanm�� diziyi main fonksiyonuna geri d�nd�rme
}

int main() {
    srand(time(0));
    int dizi[100000];
    int siralidizi[100000]; // De�i�iklik: S�ralanm�� diziyi saklamak i�in yeni bir dizi

    int k = 0;

    // Rastgele elemanl� dizi olu�turma
    for (int i = 0; i < 100000; i++) 
	{
        dizi[i] = rand() % 100001; // 0-99999

        if (dizi[i] > k) {
            k = dizi[i];
        }
    }

    counting_sort(dizi, k, 100000, siralidizi);


    printf("\nS�ral� Dizi: ");
    for (int i = 0; i < 100000; i++)
        printf("%d ", siralidizi[i]);

    printf("\n");

    return 0;
}

