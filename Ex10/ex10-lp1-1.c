#include <stdio.h>
#include <stdlib.h>

typedef struct Caixa {
	int valor;
	struct Caixa* prox;
} Caixa;

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
}