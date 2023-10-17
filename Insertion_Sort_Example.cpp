#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Insertion algoritmas� fonk.
void insertionSort(int arr[], int n)
 {
    int i, dat, j;
    for (i = 1; i < n; i++) {
        dat = arr[i];
        j = i - 1;

        // Diziyi s�ral� hale getir
        while (j >= 0 && arr[j] > dat) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = dat;
    }
}

int main() 
{
	
	
    // 0-100 aras� say� dizisi olu�turma
    srand(time(0));
    int dizi[100];
    printf("Siralanmamis Dizi:\n");
    for (int i = 0; i < 100; i++) {
        dizi[i] = rand() % 101;
        printf("%d ", dizi[i]);
    }


    // Insertion Sort fonksiyonunu �a��r
    insertionSort(dizi, 100);

    printf("\n\nSiralanmis Dizi:\n");
    for (int i = 0; i < 100; i++) {
        printf("%d ", dizi[i]);
    }

    return 0;
}

