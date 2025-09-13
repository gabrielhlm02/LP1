#include <stdio.h>
#define L 4
#define C 3

float media(int arr[L][C], int l, int c) {
	float med = 0;
	for (int i = 0; i < l*c; i++) {
		med += arr[i/c][i%c];
	}
	med /= l*c;
	return med;
}

void preenche(int arr[L][C], int l, int c) {
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < c; i++)
			printf("%d\n", i);
			printf("%d\n", j);
			printf("Insira o valor para a posição [%d][%d]: ", i/c, i%c);
			scanf("%d", &arr[i][j]);
	}
} 

/*
float media(int arr[L][C], int l, int c) {
	float med = 0;
	for (int i = 0; i < l*c; i++) {
		med += arr[i/c][i%c];
	}
	med /= l*c;
	return med;
}

void preenche(int arr[L][C], int l, int c) {
	for (int i = 0; i < l*c; i++) {
		printf("%d\n", i/c);
		printf("%d\n", i%c);
		printf("Insira o valor para a posição [%d][%d]: ", i/c, i%c);
		scanf("%d", &arr[i/c][i%c]);
	}
} */

int main(void) {
	int aray[L][C];
	preenche(aray, 5, 4);
	printf("%.2f\n", media(aray, 5, 4));
}
