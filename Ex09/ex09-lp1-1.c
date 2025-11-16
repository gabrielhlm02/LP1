#include <stdio.h>

struct Caixa {
	int valor;
	struct Caixa * prox;
};

int main() {
	struct Caixa c1 = {1, NULL};
	struct Caixa c2 = {3, NULL};
	struct Caixa c3 = {9, NULL};
	struct Caixa c4 = {7, NULL};
	struct Caixa c5 = {5, NULL};

	c1.prox = &c2;
	c2.prox = &c3;
	c3.prox = &c4;
	c4.prox = &c5;
}