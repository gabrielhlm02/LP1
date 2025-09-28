#include <stdio.h>

void prnchstr (char * str, int n) {
	if (!fgets(str, n, stdin)) {
		str[0] = '\0';
	}
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == '\n' || str[i] == '\r') {
			str[i] = '\0';
			break;
		}
	}
}

struct textos {
	// enum sub {liv, jor, qua} tipo;
	int tipo;
	union {
		struct {		// Livro
			char ltitulo[32];
			char autor[32];
			int publ;
			char resumo[128];
		};
		struct {		// Jornal
			char manchete[32];
			int noticias;
		};
		struct {		// Quadrinhos?
			char qtitulo[32];
			int paginas;
			char personagens[256];
		};
	};
};

void preenche (struct textos * txt, int tipo) {
	switch (tipo) {
	case 0:
		printf("titulo: ");
		prnchstr(txt->ltitulo, 32);

		printf("autor: ");
		prnchstr(txt->autor, 32);

		printf("ano de publicação: ");
		scanf("%d", &txt->publ);
		getchar();

		printf("resumo: ");
		prnchstr(txt->resumo, 128);
		break;
	case 1:
		printf("manchete: ");
		prnchstr(txt->manchete, 32);

		printf("qtd de noticias: ");
		scanf("%d", &txt->noticias);
		getchar();
		break;
	case 2:
		printf("titulo: ");
		prnchstr(txt->qtitulo, 32);

		printf("qtd de paginas: ");
		scanf("%d", &txt->paginas);
		getchar();

		printf("personagens presentes: ");
		prnchstr(txt->personagens, 265);
		break;
	}
	txt->tipo = tipo;
}

void exibe(struct textos txt) {
	switch (txt.tipo) {
	case 0:
		printf("%s\n%s\n%d\n%s\n", 
			txt.ltitulo, txt.autor, txt.publ, txt.resumo);
		break;
	case 1:
		printf("%s\n%d\n", 
			txt.manchete, txt.noticias);
		break;
	case 2:
		printf("%s\n%d\n%s\n", 
			txt.qtitulo, txt.paginas, txt.personagens);
		break;
	}
}

int main(void) {
	struct textos Livro;

	preenche(&Livro, 2);
	exibe(Livro);
}