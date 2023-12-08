#include <stdio.h>

// Heapify fonksiyonu: Bir alt aðacý heap yapýsýna çevirir
void heapify(int arr[], int n, int i) {
    int largest = i;  // En büyük elemaný kök olarak kabul et
    int left = 2 * i + 1;  // Sol çocuk
    int right = 2 * i + 2; // Sað çocuk

    // Sol çocuk kökten daha büyükse
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Sað çocuk kökten daha büyükse
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // En büyük eleman kök deðilse, yer deðiþtir ve tekrar heapify yap
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

// Heap sort algoritmasý
void heapSort(int arr[], int n) {
    // Heap oluþtur
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Heap yapýsýný sýralý bir diziye dönüþtür
    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Heapify ile kökü yeniden oluþtur
        heapify(arr, i, 0);
    }
}

int main() {
    int arr[10] = {9, 4, 2, 7, 5, 1, 8, 3, 6, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Dizinin ilk hali:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    // Heap sort uygula
    heapSort(arr, n);

    printf("\n\nHeap sort sonrasý:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}

