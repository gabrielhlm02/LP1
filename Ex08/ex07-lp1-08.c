#include <stdio.h>

struct Pessoa {
	int idade;
	char nome[64];
	int peso;
};


void Preenche_Pessoa (struct Pessoa * pess) {
	printf("Idade: ");
	scanf("%d", &(pess->idade));
	
	printf("Nome: ");
	scanf("%63s", pess->nome);
	pess->nome[63] = '\0';

	printf("Peso: ");
	scanf("%d", &(pess->peso));

}


void Imprime_Pessoa (struct Pessoa pess) {
	printf("Idade: %d\n", pess.idade);
	printf("Nome: %s\n", pess.nome);
	printf("Peso: %d\n", pess.peso);
}


void Escreve_Pessoa (FILE *f, struct Pessoa pess) {
	fwrite(&pess, sizeof(struct Pessoa), 1, f);
}


void Le_Pessoa (FILE *f, struct Pessoa * pess) {
	fread(pess, sizeof(struct Pessoa), 1, f);
}


int main(void) {
	struct Pessoa grupo[10];
	FILE * f;
	char opt;
	printf("1 escreve/2 le: ");
	scanf("%hhd", &opt);

	if (opt == 1) {
		f = fopen("ex07.bin", "wb");
		for (int i = 0; i < 10; i++) {
			Preenche_Pessoa(&grupo[i]);
			Escreve_Pessoa(f, grupo[i]);
			printf("\n");
		}
	}
	else {
		f = fopen("ex07.bin", "rb");
		for (int i = 0; i < 10; i++) {
			Le_Pessoa(f, &grupo[i]);
			Imprime_Pessoa(grupo[i]);
			printf("\n");
		}
	}
	fclose(f);
}