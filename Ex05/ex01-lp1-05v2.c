#include <stdio.h>

int main(void) {
	int a;
	int b;
	printf("Insira o primeiro valor: ");
	scanf("%d", &a);
	printf("Insira o segundo valor: ");
	scanf("%d", &b);

	printf("a: %d\nb: %d\n\n", a, b);

	int * p;

	if (a > b) {
		p = &a;
	}
	else {
		p = &b;
	}

	*p -= 50;

	printf("a: %d\nb: %d\n", a, b);
}