#include <stdio.h>

void troca(int * a, int * b) {
	int aux = *a;
	*a = *b;
	*b = aux;
}

int main(void) {
	int x=10, y=20;

	troca(&x, &y);

	printf("%d %d\n", x, y);
}