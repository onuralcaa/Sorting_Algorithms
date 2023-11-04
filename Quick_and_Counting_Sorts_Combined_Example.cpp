#include <stdlib.h>
#include <time.h>
#include <stdio.h>

//Yazýlýmcý : Onur ALACA  (KSÜ Bilgisayar Mühendisliði - Veri Yapýlarý Dersi)
//Öðrenci no : 23110131304

//Hafýza ölçüm iþlemi gerçekleþtirilemedi.

//----------------------------------------------------------------------
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

        if (arr[j] < pivot) 
		{
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    // Pivot'u doðru konuma yerleþtir
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low_item, int high_item) 
{
    if (low_item < high_item) 
	{
        // arr[pivotIndex] þu anki diziyi ikiye bölen pivot'un doðru konumunu döndürür
        int pivotIndex = partition(arr, low_item, high_item);

        // Pivot'tan küçük ve büyük alt dizileri sýrala-recursive fonk. mantýðý
        quickSort(arr, low_item, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high_item);
    }
}

//------------------------------------------------------------------------

//----------COUNTING SORT FONKSIYONU--------------

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

}

//-------------------------MAIN FONKSIYONU-----------------------------------------
int main()
{
	//-----------Rastgele sayi dizisi tanimlamalari----------------------
	srand(time(0));
	int dizi_1[10], dizi_2[100], dizi_3[1000], dizi_4[10000], dizi_5[100000];
	int dizi_a[10], dizi_b[100], dizi_c[1000], dizi_d[10000], dizi_e[100000];
	
	int n1 = 10;
	int n2 = 100;
	int n3 = 1000;
	int n4 = 10000;
	int n5 = 100000;
	
	int k1 = 0, k2 = 0, k3 = 0, k4 = 0, k5 = 0;
	
	int s_dizi_1[n1], s_dizi_2[n2], s_dizi_3[n3], s_dizi_4[n4], s_dizi_5[n5] ;
	
	//rastgele 100000 sayi-10 luk dizi
	for(int i = 0; i < n1; i++) 
	{
        dizi_1[i] = rand() % 100000; // 0 - 10
        dizi_a[i] = dizi_1[i];  //dizi kopyalama
		
		if (dizi_a[i] > k1) 
		{	
        	k1 = dizi_a[i];//counting sort için en büyük elemaný bulma
    	}  
    }
    
	/* 
    for (int i = 0; i < n1; i++) 
	{
        printf("%d ", dizi_a[i]);
    }
    printf("\n");
	*/
	    
    //rastgele 100000 sayi-100 luk dizi
    for(int i = 0; i < n2; i++) 
	{
        dizi_2[i] = rand() % 100001; // 0 - 100
        dizi_b[i] = dizi_2[i];  //dizi kopyalama 
        
        if (dizi_b[i] > k2) 
		{	
        	k2 = dizi_b[i];//counting sort için en büyük elemaný bulma
    	}  
    }
    
    //rastgele 100000 sayi-1000 lik dizi
    for(int i = 0; i < n3; i++) 
	{
        dizi_3[i] = rand() % 100001; // 0 - 1000
        dizi_c[i] = dizi_3[i];  //dizi kopyalama 
        
        if (dizi_c[i] > k3) 
		{	
        	k3 = dizi_c[i]; //counting sort için en büyük elemaný bulma
    	}  
    }
    
    //rastgele 100000 sayi-10000 lik dizi
    for(int i = 0; i < n4; i++) 
	{
        dizi_4[i] = rand() % 100001; // 0 - 10000
        dizi_d[i] = dizi_4[i];  //dizi kopyalama 
        
        if (dizi_d[i] > k4) 
		{	
        	k4 = dizi_d[i];//counting sort için en büyük elemaný bulma
    	}  
    }
    
    //rastgele 100000 sayi-100000 lik dizi
    for(int i = 0; i < n5; i++) 
	{
        dizi_5[i] = rand() % 100001; // 0 - 100000
        dizi_e[i] = dizi_5[i];  //dizi kopyalama 
        
        if (dizi_e[i] > k5) 
		{	
        	k5 = dizi_e[i];//counting sort için en büyük elemaný bulma
    	}  
    }
    

	/*

	//-----SÝRALANMAMÝS DÝZÝLERÝ EKRANA YAZDÝRMA KONTROLU----  

    // 10 luk Diziyi ekrana yazdir
    printf("Siralanmamis dizi (10 sayi):\n");
    for (int i = 0; i < n1; i++) 
	{
        printf("%d ", dizi_1[i]);
    }
    
    printf("\n\n");
    
    // 100 luk Diziyi ekrana yazdir
    printf("Siralanmamis dizi (100 sayi):\n");
    for (int i = 0; i < n2; i++) 
	{
        printf("%d ", dizi_2[i]);
    }
    
    printf("\n\n");
    
    // 1000 lik Diziyi ekrana yazdir
    printf("Siralanmamis dizi (1000 sayi):\n");
    for (int i = 0; i < n3; i++) 
	{
        printf("%d ", dizi_3[i]);
    }
    
    printf("\n\n");
    
    // 10000 lik Diziyi ekrana yazdir
    printf("Siralanmamis dizi (10000 sayi):\n");
    for (int i = 0; i < n4; i++) 
	{
        printf("%d ", dizi_4[i]);
    }
    
    printf("\n\n");
    
    // 100000 lik Diziyi ekrana yazdir
    printf("Siralanmamis dizi (100000 sayi):\n");
    for (int i = 0; i < n5; i++) 
	{
        printf("%d ", dizi_5[i]);
    }
    
    printf("\n\n");
    
    */
   
   //-----------------------------------------------------------
   
   //*********** QUICK SORT ICIN 10 ELEMEANLI DIZI CALISMA SURESI HESAPLAMA ***********************
   
    // 10 luk dizi siralama oncesi zaman olcumu
    struct timespec start1, end1;
    clock_gettime(CLOCK_MONOTONIC, &start1);

    // QUICK SORT 
	quickSort(dizi_1, 0, n1-1);
    // 10 luk dizi diralama sonrasi zaman olcumu
    clock_gettime(CLOCK_MONOTONIC, &end1);
    
    
    // Çalýþma süresini hesapla
    double elapsed_time1 = (end1.tv_sec - start1.tv_sec) +
                          (end1.tv_nsec - start1.tv_nsec) / 1e9;
                          
    //*****************************************************************************
    
    //*********** QUICK SORT ICIN 100 ELEMEANLI DIZI CALISMA SURESI HESAPLAMA ***********************
    // 100 luk dizi siralama oncesi zaman olcumu
    struct timespec start2, end2;
    clock_gettime(CLOCK_MONOTONIC, &start2);

    // QUICK SORT 
	quickSort(dizi_2, 0, n2-1);

    // 100 luk dizi diralama sonrasi zaman olcumu
    clock_gettime(CLOCK_MONOTONIC, &end2);
    
    
    // Çalýþma süresini hesapla
    double elapsed_time2 = (end2.tv_sec - start2.tv_sec) +
                          (end2.tv_nsec - start2.tv_nsec) / 1e9;
                          
    //*****************************************************************************
    
    //*********** QUICK SORT ICIN 1000 ELEMEANLI DIZI CALISMA SURESI HESAPLAMA ***********************
    // 1000 luk dizi siralama oncesi zaman olcumu
    struct timespec start3, end3;
    clock_gettime(CLOCK_MONOTONIC, &start3);

    // QUICK SORT 
	quickSort(dizi_3, 0, n3-1);

    // 1000 luk dizi diralama sonrasi zaman olcumu
    clock_gettime(CLOCK_MONOTONIC, &end3);
    
    
    // Çalýþma süresini hesapla
    double elapsed_time3 = (end3.tv_sec - start3.tv_sec) +
                          (end3.tv_nsec - start3.tv_nsec) / 1e9;
                          
    //*****************************************************************************
    
    
    //*********** QUICK SORT ICIN 10000 ELEMEANLI DIZI CALISMA SURESI HESAPLAMA ***********************
    // 10000 luk dizi siralama oncesi zaman olcumu
    struct timespec start4, end4;
    clock_gettime(CLOCK_MONOTONIC, &start4);

    // MERGE SORT 
	quickSort(dizi_4, 0, n4-1);

    // 10000 luk dizi diralama sonrasi zaman olcumu
    clock_gettime(CLOCK_MONOTONIC, &end4);
    
    
    // Çalýþma süresini hesapla
    double elapsed_time4 = (end4.tv_sec - start4.tv_sec) +
                          (end4.tv_nsec - start4.tv_nsec) / 1e9;
                          
    //*****************************************************************************
    
    //*********** QUICK SORT ICIN 100000 ELEMEANLI DIZI CALISMA SURESI HESAPLAMA ***********************
    // 100000 lik dizi siralama oncesi zaman olcumu
    struct timespec start5, end5;
    clock_gettime(CLOCK_MONOTONIC, &start5);

    // MERGE SORT 
	quickSort(dizi_5, 0, n5-1);

    // 10000 luk dizi diralama sonrasi zaman olcumu
    clock_gettime(CLOCK_MONOTONIC, &end5);
    
    
    // Çalýþma süresini hesapla
    double elapsed_time5 = (end5.tv_sec - start5.tv_sec) +
                          (end5.tv_nsec - start5.tv_nsec) / 1e9;
                          
    //*****************************************************************************
    

    /*
    
    //SIRALANMIS QUICK SORT DÝZÝLERÝNÝ EKRANA YAZDIRMA KONTROLU--------------------

    // Sýralanmýþ dizileri ekrana yazdýr
	//10 elemanli
    printf("\nSirali (10) dizi:\n");
    for (int i = 0; i < n1; i++) 
	{
        printf("%d ", dizi_1[i]);
    }
    printf("\n");
    //100 elemanli
    printf("\nSirali (100) dizi:\n");
    for (int i = 0; i < n2 ; i++) 
	{
        printf("%d ", dizi_2[i]);
    }
    printf("\n");
    //1000 elemanli
    printf("\nSirali (1000) dizi:\n");
    for (int i = 0; i < n3 ; i++) 
	{
        printf("%d ", dizi_3[i]);
    }
    printf("\n");
    //10000 elemanli
    printf("\nSirali (10000) dizi:\n");
    for (int i = 0; i < n4 ; i++) 
	{
        printf("%d ", dizi_4[i]);
    }
    printf("\n");
    
    //100000 elemanli
    printf("\nSirali (100000) dizi:\n");
    for (int i = 0; i < n5 ; i++) 
	{
        printf("%d ", dizi_5[i]);
    }
    printf("\n");
    
   */
    
//**************************************************************************************************
    
 
    
    //*********** COUNTING SORT ICIN 10 ELEMEANLI DIZI CALISMA SURESI HESAPLAMA ***********************
   
    // 10 luk dizi siralama oncesi zaman olcumu
    struct timespec start6, end6;
    clock_gettime(CLOCK_MONOTONIC, &start6);

    // COUNTING SORT 
    counting_sort(dizi_a, k1, 10, s_dizi_1);
    // 10 luk dizi diralama sonrasi zaman olcumu
    clock_gettime(CLOCK_MONOTONIC, &end6);
    
    
    // Çalýþma süresini hesapla
    double elapsed_time6 = (end6.tv_sec - start6.tv_sec) +
                          (end6.tv_nsec - start6.tv_nsec) / 1e9;
                          
    //*****************************************************************************
    
    
    //*********** COUNTING SORT ICIN 100 ELEMEANLI DIZI CALISMA SURESI HESAPLAMA ***********************
   
    // 10 luk dizi siralama oncesi zaman olcumu
    struct timespec start7, end7;
    clock_gettime(CLOCK_MONOTONIC, &start7);

    // COUNTING SORT 
    counting_sort(dizi_b, k2, 100, s_dizi_2);
    // 10 luk dizi diralama sonrasi zaman olcumu
    clock_gettime(CLOCK_MONOTONIC, &end7);
    
    
    // Çalýþma süresini hesapla
    double elapsed_time7 = (end7.tv_sec - start7.tv_sec) +
                          (end7.tv_nsec - start7.tv_nsec) / 1e9;
                          
    //*****************************************************************************
    
    //*********** COUNTING SORT ICIN 1000 ELEMEANLI DIZI CALISMA SURESI HESAPLAMA ***********************
   
    // 10 luk dizi siralama oncesi zaman olcumu
    struct timespec start8, end8;
    clock_gettime(CLOCK_MONOTONIC, &start8);

    // COUNTING SORT 
    counting_sort(dizi_c, k3, 1000, s_dizi_3);
    // 10 luk dizi diralama sonrasi zaman olcumu
    clock_gettime(CLOCK_MONOTONIC, &end8);
    
    
    // Çalýþma süresini hesapla
    double elapsed_time8 = (end8.tv_sec - start8.tv_sec) +
                          (end8.tv_nsec - start8.tv_nsec) / 1e9;
                          
    //*****************************************************************************
    
    //*********** COUNTING SORT ICIN 10000 ELEMEANLI DIZI CALISMA SURESI HESAPLAMA ***********************
   
    // 10 luk dizi siralama oncesi zaman olcumu
    struct timespec start9, end9;
    clock_gettime(CLOCK_MONOTONIC, &start9);

    // COUNTING SORT 
    counting_sort(dizi_d, k4, 10000, s_dizi_4);
    // 10 luk dizi diralama sonrasi zaman olcumu
    clock_gettime(CLOCK_MONOTONIC, &end9);
    
    
    // Çalýþma süresini hesapla
    double elapsed_time9 = (end9.tv_sec - start9.tv_sec) +
                          (end9.tv_nsec - start9.tv_nsec) / 1e9;
                          
    //*****************************************************************************

	//*********** COUNTING SORT ICIN 100000 ELEMEANLI DIZI CALISMA SURESI HESAPLAMA ***********************
   
    // 10 luk dizi siralama oncesi zaman olcumu
    struct timespec start10, end10;
    clock_gettime(CLOCK_MONOTONIC, &start10);

    // COUNTING SORT 
    counting_sort(dizi_e, k5, 100000, s_dizi_5);
    // 10 luk dizi diralama sonrasi zaman olcumu
    clock_gettime(CLOCK_MONOTONIC, &end10);
    
    
    // Çalýþma süresini hesapla
    double elapsed_time10 = (end10.tv_sec - start10.tv_sec) +
                          (end10.tv_nsec - start10.tv_nsec) / 1e9;
                          
    //*****************************************************************************
    
    
    /*
    //SIRALANMIS COUNTING SORT DÝZÝLERÝNÝ EKRANA YAZDIRMA KONTROLU----------------------------

    // Sýralanmýþ dizileri ekrana yazdýr
    
	//10 elemanli
    printf("\nSirali (10) dizi:\n");
    for (int i = 0; i < n1; i++) 
	{
        printf("%d ", s_dizi_1[i]);
    }
    printf("\n");
   
    //100 elemanli
    printf("\nSirali (100) dizi:\n");
    for (int i = 0; i < n2 ; i++) 
	{
        printf("%d ", s_dizi_2[i]);
    }
    printf("\n");
    
    //1000 elemanli
    printf("\nSirali (1000) dizi:\n");
    for (int i = 0; i < n3 ; i++) 
	{
        printf("%d ", s_dizi_3[i]);
    }
    printf("\n");
    
    //10000 elemanli
    printf("\nSirali (10000) dizi:\n");
    for (int i = 0; i < n4 ; i++) 
	{
        printf("%d ", s_dizi_4[i]);
    }
    printf("\n");
    
    //100000 elemanli
    printf("\nSirali (100000) dizi:\n");
    for (int i = 0; i < n5 ; i++) 
	{
        printf("%d ", s_dizi_5[i]);
    }
    printf("\n");
    
    */
                        
	//================QUICK SORT ALGORITMASI ÇALISMA SURELERI================================================== 
	printf("-------------------------------------------------------------------------------");                    
    printf("\n Quick Sort Algoritmasi (10^1 elemanli dizi icin) calisma suresi: %f saniye", elapsed_time1);
  
    printf("\n Quick Sort Algoritmasi (10^2 elemanli dizi icin) calisma suresi: %f saniye", elapsed_time2);
    
    printf("\n Quick Sort Algoritmasi (10^3 elemanli dizi icin) calisma suresi: %f saniye" , elapsed_time3);
    
    printf("\n Quick Sort Algoritmasi (10^4 elemanli dizi icin) calisma suresi: %f saniye" , elapsed_time4);
    
    printf("\n Quick Sort Algoritmasi (10^5 elemanli dizi icin) calisma suresi: %f saniye\n" , elapsed_time5);
    printf("--------------------------------------------------------------------------------\n");                    

    //======================================================================================================
    
    //================COUNTING SORT ALGORITMASI ÇALISMA SURELERI==================================================
	printf("-------------------------------------------------------------------------------");                    
 	                    
    printf("\n Counting Sort Algoritmasi (10^1 elemanli dizi icin) calisma suresi: %f saniye", elapsed_time6);
    
    printf("\n Counting Sort Algoritmasi (10^2 elemanli dizi icin) calisma suresi: %f saniye", elapsed_time7);
    
    printf("\n Counting Sort Algoritmasi (10^3 elemanli dizi icin) calisma suresi: %f saniye" , elapsed_time8);
    
    printf("\n Counting Sort Algoritmasi (10^4 elemanli dizi icin) calisma suresi: %f saniye" , elapsed_time9);
    
    printf("\n Counting Sort Algoritmasi (10^5 elemanli dizi icin) calisma suresi: %f saniye\n" , elapsed_time10);
    printf("--------------------------------------------------------------------------------\n");     
    //======================================================================================================
    
    	
	return 0;
}





