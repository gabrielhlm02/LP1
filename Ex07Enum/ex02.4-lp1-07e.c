#include <stdio.h>

struct Preco {
	enum {rea, eur, dol} tipo;
	union {
		float real;
		float euro;
		float dolar;
	};
};

void exibe(struct Preco aux) {
	switch (aux.tipo) {
	case rea:
		printf("R$%.2f\n", aux.real);
		break;
	case eur:
		printf("€%.2f\n", aux.euro);
		break;
	case dol:
		printf("$%.2f\n", aux.dolar);
		break;
	default:
		return;
	}
}

void altera(struct Preco * aux, int moeda) {
	switch (aux->tipo) {
	case rea:
		if (moeda == dol) {
			aux->dolar = aux->real / 5.33;
		}
		else {
			aux->euro = aux->real / 6.27;
		}
		break;

	case eur:
		if (moeda == rea) {
			aux->real = aux->euro * 6.27;
		}
		else {
			aux->dolar = aux->euro * 1.17;
		}
		break;

	case dol:
		if (moeda == rea) {
			aux->real = aux->dolar * 5.33;
		}
		else {
			aux->euro = aux->dolar / 1.17; 
		}
		break;
	default:
		return;
	}

	aux->tipo = moeda;
}

int main(void) {
	struct Preco p1 = {rea, 10.99};
	exibe(p1);
	altera(&p1, eur);
	exibe(p1);
}