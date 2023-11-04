#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//------QUICK SORT FONKSIYONU

// Dizi elemanlar�n� yer de�i�tir.
void swap(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Quick Sort Fonksiyonu
int partition(int arr[], int low, int high) 
{
    int pivot = arr[high]; // Pivotu en sa�daki eleman olarak ayarland�.

    // Pivotu do�ru konuma getir
    int i = (low - 1); 

    for (int j = low; j <= high - 1; j++) 
	{

        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    // Pivot'u do�ru konuma yerle�tir
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) 
{
    if (low < high) 
	{
        // arr[pivotIndex] �u anki diziyi ikiye b�len pivot'un do�ru konumunu d�nd�r�r
        int pivotIndex = partition(arr, low, high);

        // Pivot'tan k���k ve b�y�k alt dizileri s�rala-recursive fonk. mant���
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main() 
{
    int dizi[10];
    srand(time(0));

    // Rastgele elemanl� dizi olu�turma
    for (int i = 0; i < 10; i++) 
	{
        dizi[i] = rand() % 100; // 0-100
    }

    // Dizi elemanlar�n� s�rala
    quickSort(dizi, 0, 9);

    // S�ralanm�� diziyi ekrana yazd�r
    printf("S�ralanm�� Dizi: ");
    for (int i = 0; i < 10; i++) 
	{
        printf("%d ", dizi[i]);
    }

    return 0;
}

