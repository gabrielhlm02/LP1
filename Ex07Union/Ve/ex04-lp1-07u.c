#include <stdio.h>

struct Preco {
	enum sub {PR_real, PR_euro, PR_dola} tipo;
	union {
		float real;
		float euro;
		float dola;
	};
};

void exibe(struct Preco paux) {
	switch (paux.tipo) {
	case PR_real:
		printf("Real: R$");
		printf("%.2f\n", paux.real);
		break;
	case PR_euro:
		printf("Euro: €");
		printf("%.2f\n", paux.euro);
		break;
	case PR_dola:
		printf("Dólar: $");
		printf("%.2f\n", paux.dola);
		break;
	}
	//printf("%.2f\n", paux.real);
}

void altera(struct Preco * paux, enum sub tipo) {
	if (paux->tipo == tipo) {
		return;
	}

	if (paux->tipo == PR_real) {
		if (tipo == PR_euro) {
			paux->euro = paux->real / 6.27;
		}
		else {
			paux->dola = paux->real / 5.33;
		}
	}
	else if (paux->tipo == PR_euro) {
		if (tipo == PR_real) {
			paux->real = paux->euro * 6.27;
		}
		else {
			paux->dola = paux->euro * 1.17;
		}
	}
	else if (paux->tipo == PR_dola) {
		if (tipo == PR_real) {
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
	prec1.tipo = PR_real;
	prec1.real = 10.99;

	exibe(prec1);

	altera(&prec1, PR_dola);

	exibe(prec1);
}