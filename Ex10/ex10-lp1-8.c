#include <stdio.h>
#include <stdlib.h>

typedef struct Caixa {
	int valor;
	struct Caixa* prox;
} Caixa;

Caixa* insereFim(Caixa* lista, int valor);

Caixa* remover(Caixa* lista, int valor);

int contem (Caixa* lista, int valor);

void exibe(Caixa* caixa);

Caixa* concatena(Caixa* l1, Caixa* l2) {
	Caixa * R = NULL;


	Caixa * p = l1;

	while (p != NULL) {
		if (!contem(R, p->valor)) {
			R = insereFim(R, p->valor);
		}
		p = p->prox;
	}

	p = l2;

	while (p != NULL) {
		if (!contem(R, p->valor)) {
			R = insereFim(R, p->valor);
		}
		p = p->prox;
	}

	return R;
}

int main(void) {
	Caixa * cabeca1 = NULL;
	Caixa * cabeca2 = NULL;

	for (int i = 0; i < 10; i++) {
		cabeca1 = insereFim(cabeca1, i);
	}
	exibe(cabeca1);

	for (int i = 5; i < 16; i++) {
		cabeca2 = insereFim(cabeca2, i);
	}
	exibe(cabeca2);

	Caixa * concat = concatena(cabeca1, cabeca2);

	exibe(concat);
}



Caixa* insereFim(Caixa* lista, int valor) {
	Caixa* novo = (Caixa *) malloc(sizeof(Caixa));
	novo->valor = valor; novo->prox = NULL;

	Caixa* P = lista;
	Caixa* pAnt = NULL;

	while (P != NULL) {
		pAnt = P;
		P = P->prox;
	}

	if (pAnt == NULL) {
		lista = novo;
	}
	else {
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
