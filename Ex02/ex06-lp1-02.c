#include <stdio.h>

int main(void) {
	int soma = 0;
	int N;

	printf("Escolha um número: ");
	scanf("%d", &N);

	for(int i = 1; i <= N; i++) {
		soma += i * i;
	}

	printf("%d\n", soma);
}

/*
int main(void) {
	int soma = 0;
	int N;
	
	printf("Escolha um número: ");
	scanf("%d", &N);

	for (N; N >= 1; N--) {
		soma += N * N;
	}

	printf("%d\n", soma);
} */

/*
int main(void) {
	int soma;
	int N;

	printf("Escolha um número: ");
	scanf("%d", &N);

	soma = (N*(N+1)*((2*N)+1))/6;

	printf("%d\n", soma);
} */