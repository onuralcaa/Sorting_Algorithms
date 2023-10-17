#include <stdlib.h>
#include <time.h>
#include <stdio.h>

//Programlayýcý : Onur ALACA  (Bilgisayar Mühendisliði - Veri Yapýlarý)

//----------------------------------------------------------------------
// INSERTION FONK.
void insertionSort(int arrI[], int n)
 {
    int i, dat, j;
    for (i = 1; i < n; i++) 
	{
        dat = arrI[i];
        j = i - 1;

        // Diziyi sýralý hale getir
        while (j >= 0 && arrI[j] > dat) 
		{
            arrI[j + 1] = arrI[j];
            j = j - 1;
        }
        arrI[j + 1] = dat;
    }
    
}

//------------------------------------------------------------------------

// MERGE SORT FONK.
void merge(int arrM[], int l, int m, int r) 
{	
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    // verilerin kopyalanamasi
    for (i = 0; i < n1; i++)
        L[i] = arrM[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arrM[m + 1 + j];

    // gecici dizilerin birlestirilmesi
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) 
	{
        if (L[i] <= R[j]) {
            arrM[k] = L[i];
            i++;
        } else {
            arrM[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) 
	{
        arrM[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) 
	{
        arrM[k] = R[j];
        j++;
        k++;
    }
}

//--------------------------------------------------------------------------------
void mergeSort(int arrS[], int l, int r) 
{
    if (l < r) {
       
        int m = l + (r - l) / 2;
 
        mergeSort(arrS, l, m);
        mergeSort(arrS, m + 1, r);

        merge(arrS, l, m, r);
    }
}

//-------------------------MAIN FONKSIYONU-----------------------------------------
int main()
{
	//-----------Rastgele sayilar olusturuldu.----------------------
	srand(time(0));
	int dizi10[10], dizi100[100], dizi1000[1000], dizi10000[10000];
	int dizia[10], dizib[100], dizic[1000], dizid[10000];
	int dizionur[10];
	
	int n1 = 10;
	int n2 = 100;
	int n3 = 1000;
	int n4 = 10000;
	
	//rastgele 10 sayi 
	for(int i = 0; i < n1; i++) 
	{
        dizi10[i] = rand() % 10; // 0 - 10
        dizia[i] = dizi10[i];  //dizi kopyalama  
    }
     
    for (int i = 0; i < n1; i++) 
	{
        printf("%d ", dizia[i]);
    }
    printf("\n");
    
    //rastgele 100 sayi
    for(int i = 0; i < n2; i++) 
	{
        dizi100[i] = rand() % 100; // 0 - 100
        dizib[i] = dizi100[i];  //dizi kopyalama 
        
    }
    
    //rastgele 1000 sayi
    for(int i = 0; i < n3; i++) 
	{
        dizi1000[i] = rand() % 1000; // 0 - 1000
        dizic[i] = dizi1000[i];  //dizi kopyalama 
    }
    
    //rastgele 100 sayi
    for(int i = 0; i < n4; i++) 
	{
        dizi10000[i] = rand() % 10000; // 0 - 10000
        dizid[i] = dizi10000[i];  //dizi kopyalama 
    }
    

   
    
    // 10 luk Diziyi ekrana yazdir
    printf("Siralanmamis dizi (10 sayi):\n");
    for (int i = 0; i < n1; i++) 
	{
        printf("%d ", dizi10[i]);
    }
    
    printf("\n\n");
    
    // 100 luk Diziyi ekrana yazdir
    printf("Siralanmamis dizi (100 sayi):\n");
    for (int i = 0; i < n2; i++) 
	{
        printf("%d ", dizi100[i]);
    }
    
    printf("\n\n");
    
    // 1000 lik Diziyi ekrana yazdir
    printf("Siralanmamis dizi (1000 sayi):\n");
    for (int i = 0; i < n3; i++) 
	{
        printf("%d ", dizi1000[i]);
    }
    
    printf("\n\n");
    
    // 10000 lik Diziyi ekrana yazdir
    printf("Siralanmamis dizi (10000 sayi):\n");
    for (int i = 0; i < n4; i++) 
	{
        printf("%d ", dizi10000[i]);
    }
    
    printf("\n\n");
   
   //-----------------------------------------------------------
   
   //*********** MERGE ICIN 10 ELEMEANLI DIZI CALISMA SURESI HESAPLAMA ***********************
   
    // 10 luk dizi siralama oncesi zaman olcumu
    struct timespec start1, end1;
    clock_gettime(CLOCK_MONOTONIC, &start1);

    // MERGE SORT 
    mergeSort(dizi10, 0, n1 - 1);

    // 10 luk dizi diralama sonrasi zaman olcumu
    clock_gettime(CLOCK_MONOTONIC, &end1);
    
    
    // Çalýþma süresini hesapla
    double elapsed_time1 = (end1.tv_sec - start1.tv_sec) +
                          (end1.tv_nsec - start1.tv_nsec) / 1e9;
                          
    //*****************************************************************************
    
    //*********** MERGE ICIN 100 ELEMEANLI DIZI CALISMA SURESI HESAPLAMA ***********************
    // 100 luk dizi siralama oncesi zaman olcumu
    struct timespec start2, end2;
    clock_gettime(CLOCK_MONOTONIC, &start2);

    // MERGE SORT 
    mergeSort(dizi100, 0, n2 - 1);

    // 100 luk dizi diralama sonrasi zaman olcumu
    clock_gettime(CLOCK_MONOTONIC, &end2);
    
    
    // Çalýþma süresini hesapla
    double elapsed_time2 = (end2.tv_sec - start2.tv_sec) +
                          (end2.tv_nsec - start2.tv_nsec) / 1e9;
                          
    //*****************************************************************************
    
    //*********** MERGE ICIN 1000 ELEMEANLI DIZI CALISMA SURESI HESAPLAMA ***********************
    // 1000 luk dizi siralama oncesi zaman olcumu
    struct timespec start3, end3;
    clock_gettime(CLOCK_MONOTONIC, &start3);

    // MERGE SORT 
    mergeSort(dizi1000, 0, n3 - 1);

    // 1000 luk dizi diralama sonrasi zaman olcumu
    clock_gettime(CLOCK_MONOTONIC, &end3);
    
    
    // Çalýþma süresini hesapla
    double elapsed_time3 = (end3.tv_sec - start3.tv_sec) +
                          (end3.tv_nsec - start3.tv_nsec) / 1e9;
                          
    //*****************************************************************************
    
    //*********** MERGE ICIN 10000 ELEMEANLI DIZI CALISMA SURESI HESAPLAMA ***********************
    // 10000 luk dizi siralama oncesi zaman olcumu
    struct timespec start4, end4;
    clock_gettime(CLOCK_MONOTONIC, &start4);

    // MERGE SORT 
    mergeSort(dizi10000, 0, n4 - 1);

    // 10000 luk dizi diralama sonrasi zaman olcumu
    clock_gettime(CLOCK_MONOTONIC, &end4);
    
    
    // Çalýþma süresini hesapla
    double elapsed_time4 = (end4.tv_sec - start4.tv_sec) +
                          (end4.tv_nsec - start4.tv_nsec) / 1e9;
                          
    //*****************************************************************************
    
    
    // Sýralanmýþ dizileri ekrana yazdýr
	//10 elemanli
    printf("\nSirali (10) dizi:\n");
    for (int i = 0; i < n1; i++) 
	{
        printf("%d ", dizi10[i]);
    }
    printf("\n");
    //100 elemanli
    printf("\nSirali (100) dizi:\n");
    for (int i = 0; i < n2 ; i++) 
	{
        printf("%d ", dizi100[i]);
    }
    printf("\n");
    //1000 elemanli
    printf("\nSirali (1000) dizi:\n");
    for (int i = 0; i < n3 ; i++) 
	{
        printf("%d ", dizi1000[i]);
    }
    printf("\n");
    //10000 elemanli
    printf("\nSirali (10000) dizi:\n");
    for (int i = 0; i < n4 ; i++) 
	{
        printf("%d ", dizi10000[i]);
    }
    printf("\n");
    
    
//????????????????????????????????????????????????????????????????????????????????????????????????????????????????????
    
    
    //*********** INSERTÝON ICIN 10 ELEMEANLI DIZI CALISMA SURESI HESAPLAMA ***********************
   
    // 10 luk dizi siralama oncesi zaman olcumu
    struct timespec start5, end5;
    clock_gettime(CLOCK_MONOTONIC, &start5);

    // MERGE SORT 
    insertionSort( dizia, 10);
    // 10 luk dizi diralama sonrasi zaman olcumu
    clock_gettime(CLOCK_MONOTONIC, &end5);
    
    
    // Çalýþma süresini hesapla
    double elapsed_time5 = (end5.tv_sec - start5.tv_sec) +
                          (end5.tv_nsec - start5.tv_nsec) / 1e9;
                          
    //*****************************************************************************
    
    //*********** INSERTÝON ICIN 100 ELEMEANLI DIZI CALISMA SURESI HESAPLAMA ***********************
   
    // 10 luk dizi siralama oncesi zaman olcumu
    struct timespec start6, end6;
    clock_gettime(CLOCK_MONOTONIC, &start6);

    // MERGE SORT 
    insertionSort( dizib, 100);
    // 10 luk dizi diralama sonrasi zaman olcumu
    clock_gettime(CLOCK_MONOTONIC, &end6);
    
    
    // Çalýþma süresini hesapla
    double elapsed_time6 = (end6.tv_sec - start6.tv_sec) +
                          (end6.tv_nsec - start6.tv_nsec) / 1e9;
                          
    //*****************************************************************************
    
    //*********** INSERTÝON ICIN 1000 ELEMEANLI DIZI CALISMA SURESI HESAPLAMA ***********************
   
    // 10 luk dizi siralama oncesi zaman olcumu
    struct timespec start7, end7;
    clock_gettime(CLOCK_MONOTONIC, &start7);

    // MERGE SORT 
    insertionSort( dizic, 1000);
    // 10 luk dizi diralama sonrasi zaman olcumu
    clock_gettime(CLOCK_MONOTONIC, &end7);
    
    
    // Çalýþma süresini hesapla
    double elapsed_time7 = (end7.tv_sec - start7.tv_sec) +
                          (end7.tv_nsec - start7.tv_nsec) / 1e9;
                          
    //*****************************************************************************
    
    //*********** INSERTÝON ICIN 10000 ELEMEANLI DIZI CALISMA SURESI HESAPLAMA ***********************
   
    // 10 luk dizi siralama oncesi zaman olcumu
    struct timespec start8, end8;
    clock_gettime(CLOCK_MONOTONIC, &start8);

    // MERGE SORT 
    insertionSort( dizid, 10000);
    // 10 luk dizi diralama sonrasi zaman olcumu
    clock_gettime(CLOCK_MONOTONIC, &end8);
    
    
    // Çalýþma süresini hesapla
    double elapsed_time8 = (end8.tv_sec - start8.tv_sec) +
                          (end8.tv_nsec - start8.tv_nsec) / 1e9;
                          
    //*****************************************************************************
                       
                          
	//================MERGE ALGORITMASI ÇALISMA SURELERI================================================== 
	printf("-------------------------------------------------------------------------------");                    
    printf("\n Merge Algoritmasi (10 elemanli dizi icin) calisma suresi: %f saniye", elapsed_time1);
  
    printf("\n Merge Algoritmasi (100 elemanli dizi icin) calisma suresi: %f saniye", elapsed_time2);
    
    printf("\n Merge Algoritmasi (1000 elemanli dizi icin) calisma suresi: %f saniye" , elapsed_time3);
    
    printf("\n Merge Algoritmasi (10000 elemanli dizi icin) calisma suresi: %f saniye\n" , elapsed_time4);
    printf("--------------------------------------------------------------------------------\n");                    

    //======================================================================================================
    
    //================INSERTION ALGORITMASI ÇALISMA SURELERI==================================================
	printf("-------------------------------------------------------------------------------");                    
 	                    
    printf("\n Insertion Algoritmasi (10 elemanli dizi icin) calisma suresi: %f saniye", elapsed_time5);
    
    printf("\n Insertion Algoritmasi (100 elemanli dizi icin) calisma suresi: %f saniye", elapsed_time6);
    
    printf("\n Insertion Algoritmasi (1000 elemanli dizi icin) calisma suresi: %f saniye" , elapsed_time7);
    
    printf("\n Insertion Algoritmasi (10000 elemanli dizi icin) calisma suresi: %f saniye\n" , elapsed_time8);
    printf("--------------------------------------------------------------------------------\n");     
    //======================================================================================================
    	
	return 0;
}





