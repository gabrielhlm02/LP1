#include <stdio.h>
#include <string.h>


union cidadao {
	long int CPF;
	int RG;
	char nome[256];
};

int main(void) {
	union cidadao cida;

	cida.CPF = 75441137444;
	printf("CPF: %ld\n", cida.CPF);

	cida.RG = 399487372;
	printf("RG: %d\n", cida.RG);
	
	strncpy(cida.nome, "Cida dos Santos Silva", 256); // strNcpy mais segura que strcpy, copia um máximo de n caracteres, contando com o '\0'
	printf("Nome: %s\n", cida.nome);
}