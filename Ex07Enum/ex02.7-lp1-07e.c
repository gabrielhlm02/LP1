#include <stdio.h>

struct contato {
	enum {tel, ema, cor} tipo;
	union {
		struct {
			int ddd;
			int num;
		};
		struct {
			char email[64];
		};
		struct {
			char estado[16];
			char cidade[32];
			char rua[64];
			short int numero;
		};
	};
};

void preenche(struct contato * pess, int tipo) {
	switch (tipo) {
	case tel:
		printf("Telefone: ");
		scanf("%2d %9d", &pess->ddd, &pess->num);
		getchar();
		break;
	case ema:
		printf("Email: ");
		fgets(pess->email, 64, stdin);
		break;
	case cor:
		printf("Estado: ");
		fgets(pess->estado, 16, stdin);
		printf("Cidade: ");
		fgets(pess->cidade, 32, stdin);
		printf("Rua: ");
		fgets(pess->rua, 64, stdin);
		printf("Número: ");
		scanf("%hu", &pess->numero);
		getchar();
		break;
	}
	pess->tipo = tipo;
}

void exibe(struct contato pess) {
	switch(pess.tipo) {
	case tel:
		printf("(%d) %d\n", pess.ddd, pess.num);
		break;
	case ema:
		printf("%s", pess.email);
		break;
	case cor:
		printf("%s%s%s%d\n", pess.estado, pess.cidade, pess.rua, pess.numero);
		break;
	}
}

int main(void) {
	struct contato jorge;
	preenche(&jorge, tel);
	exibe(jorge);
	preenche(&jorge, ema);
	exibe(jorge);
	preenche(&jorge, cor);
	exibe(jorge);
}