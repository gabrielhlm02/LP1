#include <stdio.h>

void preenche(int * xs, int n) {
	for (int i = 0; i < n; i++) {
		printf("Insira o %dº valor: ", i+1);
		scanf("%d", xs+i);
	}
}

float media(int * xs, int n) {
	float soma = 0;
	for (int i = 0; i < n; i++) {
		soma += *(xs+i);
	}
	soma = soma / n;
	return soma;
}

int main(void) {
	int vec[100];

	int n;
	printf("Quantos valores deseja inserir? ");
	scanf("%d", &n);

	preenche(vec, n);

	float ava = media(vec, n);

	printf("%.2f\n", ava);
}