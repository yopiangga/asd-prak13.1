#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 200000

void menu(int data[]);
void alokasi(int data2[]);
void cari();

void MergeSortRekursif(int data[], int l, int r);
void Merge(int data[], int left, int median, int right); 

int n;
int pilihan, key;

time_t t1, t2;
long int waktukomputasi;

int main(){
	int data[MAX], data2[MAX];
	
	jumlahN();
	
	srand(time(NULL));
	alokasi(data2);
	
	do {
		cari();
		menu(data);
	} while(pilihan != 4);
	
}

int jumlahN(){
	printf("%-25s", "Jumlah data "); printf(": ");
	scanf("%d", &n);
	fflush(stdin);
}

void menu(int data[]){
	printf("========================\n");
	printf(" MENU METODE SEARCHING\n");
	printf("========================\n");
	printf("1. Sequential Unsorted\n");
	printf("2. Sequential Sorted\n");
	printf("3. Binary\n");
	printf("4. Keluar\n");
	printf("%-25s", "Pilih Menu"); printf(": ");
	scanf("%d", &pilihan);
	fflush(stdin);
	
	if(pilihan == 4)
		exit(0);
		
	switch(pilihan){
		case 1:
			time(&t1);
			sequential(data);
			time(&t2);
			waktukomputasi= difftime(t2,t1);
			break;
		case 2:
			MergeSortRekursif(data, 0, n-1);
			time(&t1);
			sequential(data);
			time(&t2);
			waktukomputasi= difftime(t2,t1);
			break;
		case 3:
			MergeSortRekursif(data, 0, n-1);
			time(&t1);
			binary(data);
			time(&t2);
			waktukomputasi= difftime(t2,t1);
			break;
	}
	
	printf("\n");
	printf("%-25s", "Waktu Komputasi"); printf(": %d\n\n", waktukomputasi);
}

void alokasi(int data2[]){
	int i;
	
	for(i=0; i<n; i++){
		data2[i] = rand()/1000;
	}
}

int copyData(int data2[], int data[]){
	int i;
	
	for(i=0; i<n; i++)
		data[i] = data2[i];
}

void MergeSortRekursif(int data[], int l, int r){
	int med;
	
	if(l<r){
		med = (l+r) / 2;
		MergeSortRekursif(data, l, med);
		MergeSortRekursif(data, med+1, r);
		Merge(data, l, med, r);
	}
}

void Merge(int data[], int left, int median, int right){
	int kiri1, kanan1, kiri2, kanan2;
	int i, j, hasil[n], kondisi;
	
	kiri1 = left;
	kanan1 = median;
	kiri2 = median + 1;
	kanan2 = right;
	i = left;
	
	while(kiri1 <= kanan1 && kiri2<=kanan2){
		kondisi = data[kiri1] <= data[kiri2];
			
		if(kondisi){
			hasil[i] = data[kiri1];
			kiri1++;
		} else {
			hasil[i] = data[kiri2];
			kiri2++;
		}
		i++;
	}
	
	while(kiri1<=kanan1){
		hasil[i] = data[kiri1];
		kiri1++;
		i++;
	}
	
	while(kiri2<=kanan2){
		hasil[i] = data[kiri2];
		i++;
		kiri2++;
	}
	
	j=left;
	
	while(j<=right){
		data[j] = hasil[j];
		j++;
	}
}

int tukar(int *a, int *b){
	int temp;
	
    temp = *a;
    *a = *b;
    *b = temp;
}

void cari(){
	printf("%-15s", "Input Key"); printf(": ");
	scanf("%d", &key);
	fflush(stdin);
}

int sequential(int data[]) {
	
	int i, ketemu = 0;
	
	for(i=0; i<n; i++){
		if(data[i] == key){
			ketemu = 1;
			break;
		}	
	}
	
	if(ketemu){
		printf("%-25s", "Data pada index"); printf(": %d", i);
	} else {
		printf("%-25s", "Data key"); printf(": Tidak ditemukan");
	}
		
}

int binary(int data[]) {
	
	int ketemu = 0, L, R, M;
	
	L = 0;
	R = n - 1;
	
	while(L <= R){
		M = (L+R) / 2;
		if(data[M] == key){
			ketemu = 1;
			break;
		}
		if(key < data[M])
			R = M - 1;
		else if(key > data[M])
			L = M + 1;
	}
	
	if(ketemu){
		printf("%-25s", "Data pada index"); printf(": %d", M);
	} else {
		printf("%-25s", "Data key"); printf(": Tidak ditemukan");
	}
}

