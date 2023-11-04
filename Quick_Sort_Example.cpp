#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//------QUICK SORT FONKSIYONU

// Dizi elemanlarýný yer deðiþtir.
void swap(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Quick Sort Fonksiyonu
int partition(int arr[], int low, int high) 
{
    int pivot = arr[high]; // Pivotu en saðdaki eleman olarak ayarlandý.

    // Pivotu doðru konuma getir
    int i = (low - 1); 

    for (int j = low; j <= high - 1; j++) 
	{

        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    // Pivot'u doðru konuma yerleþtir
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) 
{
    if (low < high) 
	{
        // arr[pivotIndex] þu anki diziyi ikiye bölen pivot'un doðru konumunu döndürür
        int pivotIndex = partition(arr, low, high);

        // Pivot'tan küçük ve büyük alt dizileri sýrala-recursive fonk. mantýðý
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main() 
{
    int dizi[10];
    srand(time(0));

    // Rastgele elemanlý dizi oluþturma
    for (int i = 0; i < 10; i++) 
	{
        dizi[i] = rand() % 100; // 0-100
    }

    // Dizi elemanlarýný sýrala
    quickSort(dizi, 0, 9);

    // Sýralanmýþ diziyi ekrana yazdýr
    printf("Sýralanmýþ Dizi: ");
    for (int i = 0; i < 10; i++) 
	{
        printf("%d ", dizi[i]);
    }

    return 0;
}

