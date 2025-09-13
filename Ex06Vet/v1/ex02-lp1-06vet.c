#include <stdio.h>

#define SIZE 5

int main(void) {
	int vet[SIZE];
	int I;

	for (int i = 0; i < SIZE; i++) {
		printf("Insira um número para o vetor: ");
		scanf("%d", vet + i);
	}

	for (int i = 0; i < 5; i++) {
		printf("%d\n", *(vet + i));
	}

	printf("Insira um índice a ser removido: ");
	scanf("%d", &I);

	if ((I >= 0) && (I < SIZE)) { 		// mantem ordem O(n) 
		while (I < SIZE - 1) {
			*(vet + I) = *(vet + I + 1);
			I++;
		}

		*(vet + I) = 0;
	}

	for (int i = 0; i < SIZE; i++) {
		printf("%d\n", *(vet + i));
	}


/*
	if ((I >= 0) && (I < 4)) { 			// muda a ordem theta 1
		*(vet + I) = *(vet + 4);
		*(vet + 4) = 0;
	}
	else if (I == 4) {
		*(vet + I) = 0;
	}
*/
}