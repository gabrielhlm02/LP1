#include <stdio.h>

int tamanho(char * str) {
	int qtd = 0;
	int id = 0;
	for (id; str[id] != '\0'; id++) {
		qtd++;
	}
	return qtd;
}

int main(void) {
	int size = tamanho("bananinha frita!!!!");
	printf("%d\n", size);
}