#include <stdio.h>

int main(void) {
	int vet[5];
	unsigned int I;
	for (int i = 0; i < 5; i++) {
		printf("Insira o %dº valor: ", i+1);
		scanf("%d", vet+i);
	}

	for (int i = 0; i < 5; i++) {
		printf("| %d ", *(vet+i));
	}
	printf("|\n");


	printf("Insira um índice a ser removido: ");
	scanf("%u", &I);

	if (I >= 4) {
		vet[4] = 0;
	}
	else {
		while (I < 4) {
			vet[I] = vet[I+1];
			I++;
		}
		vet[I] = 0;
	}

	for (int i = 0; i < 5; i++) {
		printf("| %d ", *(vet+i));
	}
	printf("|\n");
}