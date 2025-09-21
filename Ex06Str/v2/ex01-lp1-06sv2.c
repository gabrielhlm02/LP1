#include <stdio.h>

int tamanho (char* str) {
	int qtd = 0;
	for (int id = 0; str[id] != '\0'; id++) {
		qtd++;
	}
	return qtd;
}

int main(void) {
	int tamn = tamanho("Batata assada...");
	printf("%d\n", tamn);
}