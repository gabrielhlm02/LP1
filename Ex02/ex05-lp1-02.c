#include <stdio.h>

int main(void) {
	int soma;
	int n;
	
	printf("Escolha um número: ");
	scanf("%d", &n);
	soma += n;

	while (n != 0) {
		printf("Escolha um número: ");
		scanf("%d", &n);
		soma += n;
	} 
	
	printf("A soma dos números escolhidos é %d!\n", soma);
}