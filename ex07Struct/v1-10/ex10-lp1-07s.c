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

struct Ponto ptmax (struct Ponto pt1, struct Ponto pt2) {
	struct Ponto mai = {pt1.x, pt1.y};
	if (mai.x < pt2.x) {
		mai.x = pt2.x;
	}
	if (mai.y < pt2.y) {
		mai.y = pt2.y;
	}
	return mai;
}

void defmapa (struct Personagem pers[], int tamn, int xf, int yf, char mapa[xf][yf]) {
	for (int i = 0; i < tamn; i++) {
		mapa[pers[i].pos.x][pers[i].pos.y] = pers[i].id;
	}
}

void desenhamapa(int xf, int yf, char mapa[xf][yf]) {
	for (int i = 0; i < xf; i++) {
		printf("%d ", i);
	}
	printf("\n");

	for (int i = 0; i < yf; i++) {
		for (int j = 0; j < xf; j++) {
			if (mapa[j][i] == ' ') {
				printf("%c", mapa[j][i]);
			}
			else {
				printf("%hhu", mapa[j][i]);
			}
			printf(" ");
		}
		printf("%d", i);
		printf("\n");
	}
}

int main(void) {
	struct Personagem pers[JOGADORES];
	struct Ponto limite;
	for (int i = 0; i < JOGADORES; i++) {
		char c;
		
		lepers(&pers[i]);
		if (i == 0) {
			limite = pers[i].pos;
		}
		else {
			limite = ptmax(limite, pers[i].pos);
		}
		do {
			c = getchar();
		} while (c != EOF && c != '\n');
	}

	limite.x += 1;
	limite.y += 1;

	char mapa[limite.x][limite.y];
	memset(mapa, ' ', limite.x*limite.y);
	defmapa(pers, JOGADORES, limite.x, limite.y, mapa);

	desenhamapa(limite.x, limite.y, mapa);

}