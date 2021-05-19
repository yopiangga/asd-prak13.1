#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/time.h>
#define MAX 100000

void menu(int data[]);
void alokasi(int data2[]);
void cari();
void tampil(int data[]);

int n;
int pilihan, key;

struct timeval start, stop;

int main(){
	int data[MAX], data2[MAX];
	
	jumlahN();
	
	srand(time(NULL));
	alokasi(data2);
	tampil(data2);
	
	do {
		copyData(data2, data);
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
			gettimeofday(&start, NULL);
			sequential(data);
			sleep(1);
			gettimeofday(&stop, NULL);
			break;
		case 2:
			selection(data);
			gettimeofday(&start, NULL);
			sequential(data);
			sleep(1);
			gettimeofday(&stop, NULL);
			break;
		case 3:
			selection(data);
			gettimeofday(&start, NULL);
			binary(data);
			sleep(1);
			gettimeofday(&stop, NULL);
			break;
	}
	
	tampil(data);
	
	printf("\n");
	printf("%-25s", "Waktu Komputasi"); printf(": %f\n\n", (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec));
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

int selection(int data[]){
	
	int i,j, x, kondisi = 0;
    for(i=0; i<n-1; i++){
        x = i;
        for(j = i+1; j<n; j++){
			kondisi = data[j] < data[x];	

        	if(kondisi){
        		x = j;
			}
		}
        tukar(&data[i], &data[x]);
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
	printf("\n");
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
	printf("\n");
}

void tampil(int data[]){
	int i;
	for(i=0; i<n; i++){
		printf("%d ", data[i]);
	}
	printf("\n");
}
