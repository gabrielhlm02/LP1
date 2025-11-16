#include <stdio.h>

struct Caixa {
	int valor;
	struct Caixa * prox;
};

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

int main(void) {
	struct Caixa c1 = {1, NULL};
	struct Caixa c2 = {3, NULL};
	struct Caixa c3 = {9, NULL};
	struct Caixa c4 = {7, NULL};
	struct Caixa c5 = {5, NULL};

	c1.prox = &c2;
	c2.prox = &c3;
	c3.prox = &c4;
	c4.prox = &c5;

	exibe(&c1);

	
	struct Caixa* cabeca = &c1;

	
	if (contem(cabeca, 9)) {
		printf("9 está na lista!\n");
	}
	else {
		printf("9 não está na lista!\n");
	}


	

	c2.prox = c2.prox->prox;

	exibe(cabeca);

	if (contem(cabeca, 9)) {
		printf("9 está na lista!\n");
	}
	else {
		printf("9 não está na lista!\n");
	}

	c3.prox = c5.prox;
	c5.prox = &c3;

	exibe(cabeca);

	if (contem(cabeca, 9)) {
		printf("9 está na lista!\n");
	}
	else {
		printf("9 não está na lista!\n");
	}


}
