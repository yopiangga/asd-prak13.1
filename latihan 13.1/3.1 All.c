#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu(int data[]);
void cari();
int pilihan, key, length;

time_t t1, t2;
long int waktukomputasi;

int main(){
	int data[] = {2, 5, 6, 9, 10, 12, 15, 18, 20, 22};
	length = sizeof(data) / sizeof(int);
//	printf("%d", length);
	do {
		cari();
		menu(data);
	} while(pilihan != 3);
	
}

void cari(){
	printf("%-15s", "Input Key"); printf(": ");
	scanf("%d", &key);
	fflush(stdin);
}

void menu(int data[]){
	printf("========================\n");
	printf(" MENU METODE SEARCHING\n");
	printf("========================\n");
	printf("1. Sequential\n");
	printf("2. Binary\n");
	printf("3. Keluar\n");
	printf("%-25s", "Pilih Menu"); printf(": ");
	scanf("%d", &pilihan);
	fflush(stdin);
	
	if(pilihan == 3)
		exit(0);
		
	switch(pilihan){
		case 1:
			time(&t1);
			sequential(data);
			time(&t2);
			waktukomputasi= difftime(t2,t1);
			break;
		case 2:
			time(&t1);
			binary(data);
			time(&t2);
			waktukomputasi= difftime(t2,t1);
			break;
	}
	
	printf("\n");
	printf("%-25s", "Waktu Komputasi"); printf(": %d\n\n", waktukomputasi);
}

int sequential(int data[]) {
	
	int i, ketemu = 0;
	
	for(i=0; i<length; i++){
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
	R = length - 1;
	
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



