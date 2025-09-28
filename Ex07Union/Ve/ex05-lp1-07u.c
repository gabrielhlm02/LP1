#include <stdio.h>

struct Animal {
	enum sub {Anfi, Aves, Mami, Rept} tipo;
	union {
		struct {		// Anfíbios
			int patas;
			float espss;
			int cauda;
		};
		struct {		// Aves
			float bicol;
			int autovoo;
			int canto;
		};
		struct {		// Mamíferos
			int dentes;
			float cerebro;
			int velt;
		};
		struct {		// Répteis
			int veno;
			int autoagu;
			float ovespss;
		};
	};
};

void exibe(struct Animal aaux) {
	if (aaux.tipo == Anfi) {
		printf("%d patas,\nPele: %.2fmm,\nCauda: %dcm\n",
				aaux.patas, aaux.espss, aaux.cauda);
	}
	else if (aaux.tipo == Aves) {
		printf("Bico: %.2fcm,\nVôo: %dkm,\nCanto: %dHz\n",
				aaux.bicol, aaux.autovoo, aaux.canto);
	}
	else if (aaux.tipo == Mami) {
		printf("%d dentes,\nCérebro: %.2fcm³,\nVelocidade: %dkm/h\n",
				aaux.dentes, aaux.cerebro, aaux.velt);
	}
	else if (aaux.tipo == Rept) {
		char veno[6] = "V";		// "Venenoso"
		if (!aaux.veno) {		// "Nao venenoso"
			veno[0] = 'N';
			veno[1] = 'a';
			veno[2] = 'o';
			veno[3] = ' ';
			veno[4] = 'v';
			veno[5] = '\0';
		}

		printf("%senenoso,\nNado: %dmin,\nOvo: %.2fmm\n",
				veno, aaux.autoagu, aaux.ovespss);
	}
}

int main(void) {
	struct Animal cachorro;
	cachorro.tipo = Mami;
	cachorro.dentes = 42;
	cachorro.cerebro = 134;
	cachorro.velt = 60;

	struct Animal gato;
	gato.tipo = Mami;
	gato.dentes = 30;
	gato.cerebro = 48.6;
	gato.velt = 49;

	struct Animal pinguim;
	pinguim.tipo = Aves;
	pinguim.bicol = 121.2;
	pinguim.autovoo = 0;
	pinguim.canto = 2625;

	struct Animal beija_flor;
	beija_flor.tipo = Aves;
	beija_flor.bicol = 5.8;
	beija_flor.autovoo = 6300;
	beija_flor.canto = 4000;

	struct Animal sapo;
	sapo.tipo = Anfi;
	sapo.patas = 4;
	sapo.espss = 0.75;
	sapo.cauda = 0;

	struct Animal sucuri;
	sucuri.tipo = Rept;
	sucuri.veno = 0;
	sucuri.autoagu = 30;
	sucuri.ovespss = 0.1;

	exibe(cachorro);
	printf("\n");

	exibe(gato);
	printf("\n");

	exibe(pinguim);
	printf("\n");

	exibe(beija_flor);
	printf("\n");

	exibe(sapo);
	printf("\n");

	exibe(sucuri);
}