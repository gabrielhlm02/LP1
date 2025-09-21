#include <stdio.h>
struct Personagem {
	int forca;
	int energia;
	int experiencia;
};

struct Personagem preencheA (void) {
	struct Personagem paux;
	printf("Insira a força: ");
	scanf("%d", &paux.forca);
	printf("Insira a energia: ");
	scanf("%d", &paux.energia);
	printf("Insira a experiência: ");
	scanf("%d", &paux.experiencia);

	return paux;
}

int main(void) {
	struct Personagem p1 = preencheA();
	struct Personagem p2 = preencheA();
	printf("(%d, %d, %d) vs (%d, %d, %d)\n",
			p1.forca, p1.energia, p1.experiencia,
			p2.forca, p2.energia, p2.experiencia);
}