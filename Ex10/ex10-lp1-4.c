#include <stdio.h>
#include <stdlib.h>

typedef struct Caixa {
	int valor;
	struct Caixa* prox;
} Caixa;

int contem (Caixa* lista, int valor) {
	Caixa * P = lista;
	while (P != NULL) {
		if (P->valor == valor) {
			return 1;
		}
		P = P->prox;
	}
	return 0;
}

void exibeAux(Caixa* caixa) {
	if (caixa != NULL) {
		if (caixa->prox == NULL) {
			printf(" %d ]\n", caixa->valor);
		}
		else {
			printf(" %d,", caixa->valor);
			exibeAux(caixa->prox);
		}
	}
}

void exibe(Caixa* caixa) {
	printf("[");
	exibeAux(caixa);
}

int main(void) {
	Caixa c1 = {1, NULL};
	c1.prox = (Caixa*) malloc(sizeof(Caixa));
	c1.prox->valor = 3;
	c1.prox->prox = (Caixa*) malloc(sizeof(Caixa));
	c1.prox->prox->valor = 9;
	c1.prox->prox->prox = (Caixa*) malloc(sizeof(Caixa));
	c1.prox->prox->prox->valor = 7;
	c1.prox->prox->prox->prox = (Caixa*) malloc(sizeof(Caixa));
	c1.prox->prox->prox->prox->valor = 5;
	c1.prox->prox->prox->prox->prox = NULL;

	exibe(&c1);
	if (contem(&c1, 9)) {
		printf("A lista contem 9\n");
	}
	else {
		printf("A lista NAO contem 9\n");
	}

	Caixa * cabeca = &c1;

	Caixa * Ant = NULL;
	Caixa * Rem = cabeca;

	for (int i = 0; i < 2; i++) {
		Ant = Rem;
		Rem = Rem->prox;
	}

	Ant->prox = Rem->prox;

	exibe(cabeca);
	if (contem(cabeca, 9)) {
		printf("A lista contem 9\n");
	}
	else {
		printf("A lista NAO contem 9\n");
	}

	Rem->prox = cabeca;
	cabeca = Rem;

	exibe(cabeca);
	if (contem(cabeca, 9)) {
		printf("A lista contem 9\n");
	}
	else {
		printf("A lista NAO contem 9\n");
	}
}