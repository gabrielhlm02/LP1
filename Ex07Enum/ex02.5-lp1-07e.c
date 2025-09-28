#include <stdio.h>

struct Animal {
	enum sub {Anfi, Aves, Mami, Rept} tipo;
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

int main(void) {
	struct Animal cachorro = {Mami, 42, 60, 134.0};
	struct Animal gato = {Mami, 30, 49, 48.6};
	struct Animal pinguim = {Aves, 0, 2625, 121.2};
	struct Animal beija_flor = {Aves, 6300, 4000, 5.8};
	struct Animal sapo = {Anfi, 4, 0, 0.75};
	struct Animal sucuri = {Rept, 0, 30, 0.1};

	printf("%d, %d, %d, %.2f\n",
			cachorro.tipo, cachorro.dentes, cachorro.velt, cachorro.cerebro);
	printf("%d, %d, %d, %.2f\n",
			gato.tipo, gato.dentes, gato.velt, gato.cerebro);
	printf("%d, %d, %d, %.2f\n",
			pinguim.tipo, pinguim.autovoo, pinguim.canto, pinguim.bicol);
	printf("%d, %d, %d, %.2f\n",
			beija_flor.tipo, beija_flor.autovoo, beija_flor.canto, beija_flor.bicol);
	printf("%d, %d, %d, %.2f\n",
			sapo.tipo, sapo.patas, sapo.cauda, sapo.espss);
	printf("%d, %d, %d, %.2f\n",
			sucuri.tipo, sucuri.veno, sucuri.cauda, sucuri.espss);
}