#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define N1 10
#define N2 10

struct Caixa {
	int valor;
	struct Caixa * prox;
};

struct Caixa* insereFim (struct Caixa** lista, int valor);
struct Caixa* Remove (struct Caixa* lista, int valor);
int contem (struct Caixa* lista, int valor);
void exibe (struct Caixa* caixa);


struct Caixa * concatena (struct Caixa * l1, struct Caixa * l2); //alternativa no final
/*{
	struct Caixa * C = NULL;
	struct Caixa * p = l1;

	while (p != NULL) {
		insereFim(&C, p->valor);
		p = p->prox;
	}

	p = l2;

	while (p != NULL) {
		if (!contem(C, p->valor)) {
			insereFim(&C, p->valor);
		}
		p = p->prox;
	}

	return C;
}*/


int main(void) {
	struct Caixa * cabeca1 = NULL;
	for (int i = 0; i < N1; i++) {
		insereFim(&cabeca1, i);
	}

	exibe(cabeca1);

	struct Caixa * cabeca2 = NULL;
	for (int j = 5; j < N2+N1-5; j++) {
		insereFim(&cabeca2, j);
	}

	exibe(cabeca2);

	struct Caixa * Concat = concatena(cabeca1, cabeca2);

	exibe(Concat);
}



struct Caixa* insereFim (struct Caixa** lista, int valor) {
	assert(lista != NULL);
	struct Caixa* novo = (struct Caixa *) malloc(sizeof(struct Caixa));
	novo->valor = valor; novo->prox = NULL;

	if (*lista == NULL) {
		*lista = novo;
		return novo;
	}

	struct Caixa * p = *lista;

	while (p->prox != NULL) {
		p = p->prox;
	}

	p->prox = novo;

	return *lista;
}

struct Caixa* Remove (struct Caixa* lista, int valor) {
	struct Caixa * p  = lista;
	struct Caixa * pant = NULL;

	while (p != NULL) {
		if (p->valor == valor) {
			if (pant != NULL) {
				pant->prox = p->prox;
				free(p);
				p = pant->prox;
			}
			else {
				lista = p->prox;
				free(p);
				p = lista;
			}
		}
		else {
			pant = p;
			p = p->prox;
		}
	}

	return lista;
}

int contem (struct Caixa* lista, int valor) {
	struct Caixa * p = lista;

	while (p != NULL) {
		if (p->valor == valor) {
			return 1;
		}

		p = p->prox;
	}

	return 0;
}

void exibe (struct Caixa* caixa) {
	struct Caixa * p = caixa;
	
	if (p == NULL) {
		printf("[]\n");
		return;
	}

	printf("[ %d", p->valor);

	while (p->prox != NULL) {
		printf(",");
		p = p->prox;
		printf(" %d", p->valor);
	}

	printf(" ]\n");
}

struct Caixa * concatena (struct Caixa * l1, struct Caixa * l2) {
	struct Caixa * p = l1;

	if (l1 == NULL) {
		return l2;
	}

	while (p->prox != NULL) {
		p = p->prox;
	}

	while (l2 != NULL) {
		if (!contem(l1, l2->valor)) {
			p->prox = l2;
			p = p->prox;
		}
		l2 = l2->prox;
	}

	return l1;
}
