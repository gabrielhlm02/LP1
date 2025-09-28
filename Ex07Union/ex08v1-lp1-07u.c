#include <stdio.h>
#include <string.h>

struct Animal {
	char nome[32];
	char cor[16];
	// enum sub {Anfi, Aves, Mami, Rept} tipo;
	int tipo;
	union {
		struct {
			int patas;
			int cauda;
			float espss;
		};
		struct {
			int autovoo;
			int canto;
			float bicol;
		};
		struct {
			int dentes;
			int velt;
			float cerebro;
		};
		struct {
			int veno;
			int autoagu;
			float ovespss;
		};
	};
};

void exibe(struct Animal aaux) {
	printf("%s:\n%s\n", aaux.nome, aaux.cor);
	if (aaux.tipo == 0) {
		printf("%d patas,\nPele: %.2fmm,\nCauda: %dcm\n",
				aaux.patas, aaux.espss, aaux.cauda);
	}
	else if (aaux.tipo == 1) {
		printf("Bico: %.2fcm,\nVôo: %dkm,\nCanto: %dHz\n",
				aaux.bicol, aaux.autovoo, aaux.canto);
	}
	else if (aaux.tipo == 2) {
		printf("%d dentes,\nCérebro: %.2fcm³,\nVelocidade: %dkm/h\n",
				aaux.dentes, aaux.cerebro, aaux.velt);
	}
	else if (aaux.tipo == 3) {
		char veno[6] = "V";
		if (!aaux.veno) {
			strncpy(veno, "Nao v", 6);
		}

		printf("%senenoso,\nNado: %dmin,\nOvo: %.2fmm\n",
				veno, aaux.autoagu, aaux.ovespss);
	}
}

int main(void) {
	struct Animal cachorro = {"Canis lupus familiaris", "Marrom", 2, 42, 60, 134};

	struct Animal gato = {"Felis catus", "Cinza", 2, 30, 49, 48.6};

	struct Animal pinguim = {"Aptenodytes forsteri", "Preto", 1, 0, 2625, 121.2};

	struct Animal beija_flor = {"Colibri serrirostris", "Ciano", 1, 6300, 4000, 5.8};

	struct Animal sapo = {"Rhinella marina", "Marrom", 0, 4, 0, 0.75};

	struct Animal sucuri = {"Eunectes murinus", "Verde", 3, 0, 30, 0.1};

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