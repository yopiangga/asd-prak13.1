#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#define MAX 100

int main(){
//	int data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int data[] = {2, 5, 6, 9, 10, 12, 15, 18, 20, 22};
	int key;
	
	printf("%-15s", "Input Key"); printf(": ");
	scanf("%d", &key);
	fflush(stdin);
	
	binary(data, key, 10);
}

int binary(int data[], int key, int length) {
	
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
	
	if(ketemu)
		printf("%d adalah index dari data yang dicari", M);
	else 
		printf("Data tidak ditemukan");
}
