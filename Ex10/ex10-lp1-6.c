#include <stdio.h>
#include <stdlib.h>

typedef struct Caixa {
	int valor;
	struct Caixa* prox;
} Caixa;

Caixa* insere(Caixa* lista, int valor) {
	Caixa * novo = (Caixa *) malloc(sizeof(Caixa));
	novo->valor = valor;

	Caixa * pAnt = NULL;
	Caixa * P = lista;

	while (P != NULL && P->valor < valor) {
		pAnt = P;
		P = P->prox;
	}

	if (pAnt == NULL) {
		novo->prox = lista;
		lista = novo;
	}
	else {
		novo->prox = P;
		pAnt->prox = novo;
	}

	return lista;
}

Caixa* remover(Caixa* lista, int valor) {
	Caixa * pAnt = NULL;
	Caixa * P = lista;
	
	while (P != NULL && P->valor != valor) {
		pAnt = P;
		P = P->prox;
	}

	if (P != NULL) {
		if (pAnt == NULL) {
			lista = P->prox;
		}
		else {
			pAnt->prox = P->prox;
		}
		free(P);
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
	Caixa * cabeca = NULL;
	cabeca = insere(cabeca, 9);
	cabeca = insere(cabeca, 7);
	cabeca = insere(cabeca, 5);
	cabeca = insere(cabeca, 1);
	cabeca = insere(cabeca, 3);

	exibe(cabeca);
	if (contem(cabeca, 9)) {
		printf("A lista contem 9\n");
	}
	else {
		printf("A lista NAO contem 9\n");
	}

	cabeca = remover(cabeca, 9);

	exibe(cabeca);
	if (contem(cabeca, 9)) {
		printf("A lista contem 9\n");
	}
	else {
		printf("A lista NAO contem 9\n");
	}

	cabeca = insere(cabeca, 9);

	exibe(cabeca);
	if (contem(cabeca, 9)) {
		printf("A lista contem 9\n");
	}
	else {
		printf("A lista NAO contem 9\n");
	}
}