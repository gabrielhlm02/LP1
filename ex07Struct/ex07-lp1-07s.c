#include <stdio.h>

void spnrplc(char * str, int tamn) {		// SPaN & RePLaCe : função para remover '\n' ou '\r' incluídos pela função fgets
	for (int i = 0; i < tamn && str[i] != '\0'; i++) {
		if (str[i] == '\n' || str[i] == '\r') {
			str[i] = '\0';
			break;
		}
	}
}

void prnchestr(char * str, int tamn) {		// PReeNCHE STRing : usa fgets para receber string do usuario de forma segura(?)
	if (!(fgets(str, tamn, stdin))) {
		str[0] = '\0';
	}
	
	spnrplc(str, tamn);
}

struct Livro {
	char titu[16];
	char autor[32];
	int anoL;
	float nota;
	char resumo[256];
};

void preenche(struct Livro * laux) {
	char chr;
	printf("Insira o título do livro: ");
	prnchestr(laux->titu, 16);

	printf("Insira o nome do autor: ");
	prnchestr(laux->autor, 32);

	printf("Insira o ano de publicação: ");
	scanf("%d", &laux->anoL);				// scanf deixa '\n' no buffer, o que causa conflito com o fgets de prnchestr
	do {									// getchar lê o tudo que ainda estiver no buffer, solução do stackoverflow...
		chr = getchar();	
	} while(chr != EOF && chr != '\n');

	printf("[OPCIONAL] Dê uma nota para o livro: ");
	scanf("%f", &laux->nota);
	do {
		chr = getchar();	
	} while(chr != EOF && chr != '\n');
	printf("[OPCIONAL] Escreva um resumo de uma linha: ");
	prnchestr(laux->resumo, 256);
}

int main(void) {
	struct Livro l1;
	preenche(&l1);
	printf("%s\n", l1.titu);
	printf("%s\n", l1.autor);
	printf("%d\n", l1.anoL);
	printf("%.2f\n", l1.nota);
	printf("%s\n", l1.resumo);
}