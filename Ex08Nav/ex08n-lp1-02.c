#include <stdio.h>

long tamanho(char nome[]) {
	FILE * f = fopen(nome, "rb");
	long tamn = 0;
	for(tamn; fgetc(f) != EOF; tamn++);
	return tamn;
}

int main(void) {
	char arq[64];
	scanf("%64s", arq);
	printf("%ld Bytes\n", tamanho(arq));
}
