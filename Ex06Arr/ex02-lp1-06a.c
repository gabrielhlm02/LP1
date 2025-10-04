#include <stdio.h>
#define L 5
#define C 4

float media (int arr[L][C], int l, int c) {
	float media = 0; 
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < c; j++) {
			media += arr[i][j];
		}
	}
	media /= l*c;
	return media;
}

int main(void) {
	int aray[L][C];

	int lin = 3;
	int col = 3;

	for (int i = 0; i < lin; i++) {
		for (int j = 0; j < col; j++) {
			scanf("%d", &aray[i][j]);
		}
	}

	printf("%f\n", media(aray, lin, col));
}