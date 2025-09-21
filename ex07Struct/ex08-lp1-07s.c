#include <stdio.h>
#define QTDP 10


struct ponto {
	int x;
	int y;
};

void ppreenche(struct ponto * paux) {
	printf("Insira X: ");
	scanf("%d", &paux->x);
	printf("Insira Y: ");
	scanf("%d", &paux->y);
}

void ptsp(struct ponto * pts, int tamn) {
	for (int i = 0; i < tamn; i++) {
		ppreenche(&pts[i]);
	}
}

int distancia(struct ponto pto) {
	return (pto.x * pto.x) + (pto.y * pto.y);
}

struct ponto maidist(struct ponto * pnts, int tamn) {
	struct ponto mai = pnts[0];
	int dist, distmai = distancia(mai);
	for (int i = 1; i < tamn; i++) {
		dist = distancia(pnts[i]); 
		if (dist > distmai) {
			mai = pnts[i];
			distmai = dist;
		}
	}
	return mai;
}

int main(void) {
	struct ponto pnts[QTDP];

	ptsp(pnts, QTDP);

	for (int i = 0; i < 10; i++) {
		printf("Ponto %d: (%d, %d)\n", i, pnts[i].x, pnts[i].y);
	}

	struct ponto mai = maidist(pnts, QTDP);
	printf("Ponto mais distante: (%d, %d)\n", mai.x, mai.y);
}