#include <stdio.h>
#include <stdlib.h>

struct Caixa {
	int valor;
	struct Caixa * prox;
};

struct Caixa* insere (struct Caixa** lista, int valor) {
	struct Caixa* novo = (struct Caixa *) malloc(sizeof(struct Caixa));
	novo->valor = valor;

	struct Caixa * p = *lista, * pant = NULL;

	while (p != NULL && p->valor < valor) {
		pant = p;
		p = p->prox;
	}

	novo->prox = p;

	if (pant == NULL) {
		*lista = novo;
	}
	else {
		pant->prox = novo;
	}

	return *lista;
}

struct Caixa* Remove (struct Caixa* lista, int valor);

int contem (struct Caixa* lista, int valor);

void exibe (struct Caixa* caixa);

int main(void) {
	struct Caixa* cabeca = NULL;

	cabeca = insere(&cabeca, 3);
	cabeca = insere(&cabeca, 1);
	cabeca = insere(&cabeca, 9);
	cabeca = insere(&cabeca, 7);
	cabeca = insere(&cabeca, 5);

	exibe(cabeca);

	if (contem(cabeca, 9)) {
		printf("9 está na lista!\n");
	}
	else {
		printf("9 não está na lista!\n");
	}

	cabeca = Remove(cabeca, 9);

	exibe(cabeca);

	if (contem(cabeca, 9)) {
		printf("9 está na lista!\n");
	}
	else {
		printf("9 não está na lista!\n");
	}

	cabeca = insere(&cabeca, 9);

	exibe(cabeca);

	if (contem(cabeca, 9)) {
		printf("9 está na lista!\n");
	}
	else {
		printf("9 não está na lista!\n");
	}


	cabeca = Remove(cabeca, 1);
	exibe(cabeca);

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