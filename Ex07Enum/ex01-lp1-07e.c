#include <stdio.h>

enum Dia {
	Domingo = 1,
	Segunda,
	Terca,
	Quarta,
	Quinta,
	Sexta,
	Sabado,
};

char* nome(enum Dia Dia) {
	switch (Dia) {
	case Domingo:
		return "Domingo";

	case Segunda:
		return "Segunda";

	case Terca:
		return "Terca";

	case Quarta:
		return "Quarta";

	case Quinta:
		return "Quinta";

	case Sexta:
		return "Sexta";

	case Sabado:
		return "Sabado";
	default:
		return "ERRO!";
	}
}

int main(void) {
	int d;
	scanf("%d", &d);
	char * dds = nome(d);
	printf("%s\n", nome(d));
	printf("%s\n", dds);
}