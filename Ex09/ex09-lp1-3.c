#include <stdio.h>

struct Caixa {
	int valor;
	struct Caixa * prox;
};

void exibe (struct Caixa* caixa);

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

	c2.prox = c2.prox->prox;

	exibe(cabeca);

	c3.prox = cabeca;
	cabeca = &c3;

	exibe(cabeca);

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
