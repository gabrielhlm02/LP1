#include <stdio.h>
#include <stdlib.h>

typedef struct Caixa {
	int valor;
	struct Caixa* prox;
} Caixa;

Caixa* remover(Caixa* lista, int valor) {
	Caixa * pAnt = NULL;
	Caixa * P = lista;
	while (P != NULL) {
		if (P->valor == valor) {
			if (pAnt == NULL) {
				lista = P->prox;
				free(P);
				P = lista;
			}
			else {
				pAnt->prox = P->prox;
				free(P);
				P = pAnt->prox;
			}
		}
		else {
			pAnt = P;
			P = P->prox;
		}
	}
	return lista;
} 

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

void exibe(Caixa* caixa) {
	printf("[");
	if (caixa != NULL) {
		Caixa * P = caixa;
		while (P->prox != NULL) {
			printf(" %d,", P->valor);
			P = P->prox;
		}

		printf(" %d", P->valor);
	}

	printf(" ]\n");
}

int main(void) {
	Caixa * c1 = (Caixa*) malloc(sizeof(Caixa));
	c1->valor = 1;
	c1->prox = (Caixa*) malloc(sizeof(Caixa));
	c1->prox->valor = 3;
	c1->prox->prox = (Caixa*) malloc(sizeof(Caixa));
	c1->prox->prox->valor = 9;
	c1->prox->prox->prox = (Caixa*) malloc(sizeof(Caixa));
	c1->prox->prox->prox->valor = 7;
	c1->prox->prox->prox->prox = (Caixa*) malloc(sizeof(Caixa));
	c1->prox->prox->prox->prox->valor = 5;
	c1->prox->prox->prox->prox->prox = NULL;

	exibe(c1);
	if (contem(c1, 9)) {
		printf("A lista contem 9\n");
	}
	else {
		printf("A lista NAO contem 9\n");
	}

	Caixa * cabeca = c1;

	cabeca = remover(cabeca, 9);

	exibe(cabeca);
	if (contem(cabeca, 9)) {
		printf("A lista contem 9\n");
	}
	else {
		printf("A lista NAO contem 9\n");
	}

	Caixa * novo = (Caixa *) malloc(sizeof(Caixa));
	novo->valor = 9; novo->prox = cabeca;

	cabeca = novo;

	exibe(cabeca);
	if (contem(cabeca, 9)) {
		printf("A lista contem 9\n");
	}
	else {
		printf("A lista NAO contem 9\n");
	}
}