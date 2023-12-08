#include <stdio.h>

// Heapify fonksiyonu: Bir alt a�ac� heap yap�s�na �evirir
void heapify(int arr[], int n, int i) {
    int largest = i;  // En b�y�k eleman� k�k olarak kabul et
    int left = 2 * i + 1;  // Sol �ocuk
    int right = 2 * i + 2; // Sa� �ocuk

    // Sol �ocuk k�kten daha b�y�kse
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Sa� �ocuk k�kten daha b�y�kse
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // En b�y�k eleman k�k de�ilse, yer de�i�tir ve tekrar heapify yap
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

// Heap sort algoritmas�
void heapSort(int arr[], int n) {
    // Heap olu�tur
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Heap yap�s�n� s�ral� bir diziye d�n��t�r
    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Heapify ile k�k� yeniden olu�tur
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

    printf("\n\nHeap sort sonras�:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}

