#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

void swap(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) 
{
    int pivot = arr[high];
    int i = (low - 1); 

    for (int j = low; j <= high - 1; j++) 
    {
        if (arr[j] < pivot) 
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) 
{
    if (low < high) 
    {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

void printMemoryUsage(const char *algorithmName, int arraySize) {
    struct timeval t;
    gettimeofday(&t, NULL);

    printf("%s Algoritmasý (%d elemanlý dizi için) Hafýza Kullanýmý: %ld KB\n", algorithmName, arraySize, t.tv_usec);
}

int main() 
{
    int dizi[1000];
    srand(time(0));

    for (int i = 0; i < 1000; i++) 
    {
        dizi[i] = rand() % 100000;
    }

    // Bellek kullanýmýný ölçmek için baþlangýç noktasýný kaydet
    printMemoryUsage("Baþlangýç", 1000);

    quickSort(dizi, 0, 999);

    // Bellek kullanýmýný ölçmek için bitiþ noktasýný kaydet
    printMemoryUsage("Quick Sort", 1000);

    printf("Sýralanmýþ Dizi: ");
    for (int i = 0; i < 1000; i++) 
    {
        printf("%d ", dizi[i]);
    }

    return 0;
}

