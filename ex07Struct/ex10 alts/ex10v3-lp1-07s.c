#include <stdio.h>
#include <string.h>
#define JOGADORES 10

struct Ponto {
	int x;
	int y;
};

struct Personagem {
	char id;
	struct Ponto pos;
	int pont;
};

void lepnt (struct Ponto * pnt) {
	printf("Insira X: ");
	scanf("%d", &pnt->x);
	printf("Insira Y: ");
	scanf("%d", &pnt->y);
}

void lepers (struct Personagem * pers) {
	printf("Insira Id: ");
	scanf("%hhu", &pers->id);
	lepnt(&pers->pos);
	pers->pont = 0;
}

struct Ponto ptmax (struct Ponto pt1, struct Ponto pt2) {			// cria um ponto com os maiores x e y entre os dois pontos; usado para determinar o tamanho do mapa
	struct Ponto mai = {pt1.x, pt1.y};
	if (mai.x < pt2.x) {
		mai.x = pt2.x;
	}
	if (mai.y < pt2.y) {
		mai.y = pt2.y;
	}
	return mai;
}

void defmapa (int tamn, struct Personagem pers[], int xf, int yf, char mapa[xf][yf]) {
	// coloca os personagens no mapa; pers é um vetor com tamn personagens de tamnho tamn; mapa é um vetor bidimensional de dimensões xf por yf

	for (int i = 0; i < tamn; i++) {
		mapa[pers[i].pos.x][pers[i].pos.y] = pers[i].id;
	}
}

void desenhamapa(int tamn, struct Personagem pers[], int xf, int yf, char mapa[xf][yf]) {
	for (int i = 0; i < xf; i++) {
		printf("%3d ", i);				// indices verticais
	}
	printf("\n");

	char desenha;
	struct Personagem aux;

	for (int i = 0; i < yf; i++) {
		for (int j = 0; j < xf; j++) {
			desenha = 0;
			for (int k = 0; k < tamn; k++) {
				if (i == pers[k].pos.y && j == pers[k].pos.x) {
					desenha = 1;
					aux = pers[k];
					pers[k] = pers[tamn];
					pers[tamn] = pers[k];
				}
			}

			if (!desenha) {
				printf("   ");
			}
			else {
				printf("%3hhu", mapa[j][i]);
			}
			printf(" ");
		}
		printf("%-3d", i);				// indices horizontais
		printf("\n");
	}
}

int main(void) {
	struct Personagem pers[JOGADORES];
	struct Ponto limite;
	for (int i = 0; i < JOGADORES; i++) {

		lepers(&pers[i]);
		if (i == 0) {
			limite = pers[i].pos;
		}
		else {
			limite = ptmax(limite, pers[i].pos);
		}
	}

	limite.x += 1;
	limite.y += 1;

	char mapa[limite.x][limite.y];
	memset(mapa, 0, limite.x*limite.y);
	defmapa(JOGADORES, pers, limite.x, limite.y, mapa);

	desenhamapa(JOGADORES, pers, limite.x, limite.y, mapa);

}