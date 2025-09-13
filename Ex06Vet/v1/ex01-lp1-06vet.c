#include <stdio.h>

void preenche (int* xs, int n) {
	for (int i = 0; i < n; i++) {
		printf("Insira o %dº valor: ", i+1);
		scanf("%d", xs + i); //  &xs[i]
	}
}

float media(int* xs, int n) {
	float ava = 0;
	for (int i = 0; i < n; i++) {
		ava += *(xs + i); // xs[i]
	}

	ava /= n;

	return ava;
}

int main(void) {
	int vec[100];
	float ava;
	int n;

	printf("Escolha a quantidade de elementos a ser inserida [<=100]: ");
	scanf("%d", &n);

	preenche(vec, n);

	for (int i = 0; i < 100; i++) {
		printf("%d\n", *(vec + i));
	}

	ava = media(vec, n);
	printf("A média dos valores inseridos é: %.2f\n", ava);
}