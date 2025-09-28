#include <stdio.h>

struct Preco {
	int tipo;
	union {
		float real;
		float euro;
		float dola;
	};
};

void exibe(struct Preco paux) {
	switch (paux.tipo) {
	case 0:
		printf("Real: R$");
		printf("%.2f\n", paux.real);
		break;
	case 1:
		printf("Euro: €");
		printf("%.2f\n", paux.euro);
		break;
	case 2:
		printf("Dólar: $");
		printf("%.2f\n", paux.dola);
		break;
	}
	//printf("%.2f\n", paux.real);
}

void altera(struct Preco * paux, int tipo) {
	if (paux->tipo == tipo) {
		return;
	}

	if (paux->tipo == 0) {
		if (tipo == 1) {
			paux->euro = paux->real / 6.27;
		}
		else {
			paux->dola = paux->real / 5.33;
		}
	}

	else if (paux->tipo == 1) {
		if (tipo == 0) {
			paux->real = paux->euro * 6.27;
		}
		else {
			paux->dola = paux->euro * 1.17;
		}
	}

	else if (paux->tipo == 2) {
		if (tipo == 0) {
			paux->real = paux->dola * 5.33;
		}
		else {
			paux->euro = paux->dola / 1.17;
		}
	}

	paux->tipo = tipo;
}

int main(void) {
	struct Preco prec1;
	prec1.tipo = 0;
	prec1.real = 10.99;

	exibe(prec1);

	altera(&prec1, 2);

	exibe(prec1);
}