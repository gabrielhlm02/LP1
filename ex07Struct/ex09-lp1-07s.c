#include <stdio.h>

struct Ponto {
	int x;
	int y;
};

struct Personagem {
	int id;
	struct Ponto posxy;
	int pont;
};

void initchr(struct Personagem * px) {
	scanf("%d", &px->id);
	scanf("%d", &px->posxy.x);
	scanf("%d", &px->posxy.y);
	px->pont = 0;
}

int main(void) {
	struct Personagem jogo[10];
	for (int i = 0; i < 10; i++) {
		initchr(jogo + i);
	}
}