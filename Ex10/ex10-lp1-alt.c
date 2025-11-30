#include <stdio.h>
#include <stdlib.h>

typedef struct Caixa {
	int valor;
	struct Caixa* prox;
} Caixa;

void insereFim(Caixa** lista, int valor, Caixa** Ult) {
	if (lista == NULL || Ult == NULL) {return;}
	Caixa * novo = (Caixa *) malloc(sizeof(Caixa));
	novo->valor = valor; novo->prox = NULL;

	if (*Ult == NULL) {
		*lista = novo;
		*Ult = *lista;
	}
	else {
		(*Ult)->prox = novo;
		*Ult = novo;
	}
}

void remover(Caixa** lista, int valor, Caixa ** Ult) {
	Caixa * pAnt = NULL;
	Caixa * P = *lista;
	
	while (P != NULL && P->valor != valor) {
		pAnt = P;
		P = P->prox;
	}

	if (P != NULL) {
		if (pAnt == NULL) {
			*lista = P->prox;
			pAnt = *lista;
		}
		else {
			pAnt->prox = P->prox;
			pAnt = pAnt->prox;
		}

		if (P == *Ult) {
			*Ult = pAnt;
		}

		free(P);
	}
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
	Caixa * cUlt = NULL;
	insereFim(&cabeca, 9, &cUlt);
	insereFim(&cabeca, 7, &cUlt);
	insereFim(&cabeca, 5, &cUlt);
	insereFim(&cabeca, 1, &cUlt);
	insereFim(&cabeca, 3, &cUlt);

	exibe(cabeca);
	if (contem(cabeca, 9)) {
		printf("A lista contem 9\n");
	}
	else {
		printf("A lista NAO contem 9\n");
	}

	remover(&cabeca, 9, &cUlt);

	exibe(cabeca);
	if (contem(cabeca, 9)) {
		printf("A lista contem 9\n");
	}
	else {
		printf("A lista NAO contem 9\n");
	}

	insereFim(&cabeca, 9, &cUlt);

	exibe(cabeca);
	if (contem(cabeca, 9)) {
		printf("A lista contem 9\n");
	}
	else {
		printf("A lista NAO contem 9\n");
	}
}