#include <stdio.h>
#define L 5
#define C 3

void preenche(int arr[L][C], int l, int c) {
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < c; j++) {
			printf("Insira o valor para a posição [%d][%d]: ", i, j);
			scanf("%d", &arr[i][j]);
		}
	}
}

float media(int arr[L][C], int l, int c) {
	float soma = 0;

	for (int i = 0; i < l; i++) {
		for (int j = 0; j < c; j++) {
			soma += arr[i][j];
		}
	} 

	soma = soma / (l*c);
	return soma;
}

int main(void) {
	int aray[L][C];
	
	/*for (int i = 0; i < L*C; i++) {
		printf("%d\n", aray[i/C][i%C]);
	}*/

	preenche(aray, 5, 3);

	float ava = media(aray, 5, 3);

	printf("Média: %.2f\n", ava);

	/*for (int i = 0; i < L*C; i++) {
		printf("%d\n", aray[i/C][i%C]);
	}*/
}