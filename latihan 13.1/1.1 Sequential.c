#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#define MAX 100

int main(){
	int data[] = {10, 1, 2, 11, 8, 7, 5, 4, 15, 16};
	int key;
	
	printf("%-15s", "Input Key"); printf(": ");
	scanf("%d", &key);
	fflush(stdin);
	
	sequential(data, key, 10);
}

int sequential(int data[], int key, int length) {
	
	int i, ketemu = 0;
	
	for(i=0; i<length; i++){
		if(data[i] == key){
			ketemu = 1;
			break;
		}	
	}
	
	if(ketemu)
		printf("%d adalah index dari data yang dicari", i);
	else 
		printf("Data tidak ditemukan");
}
