#include <stdio.h>

struct Personagem {
	int força;
	int energia;
	int experiencia;
};

void PrintPersonagem (struct Personagem * pp) {
	printf("Força: %d\nEnergia: %d\nExperiência: %d\n", pp->força, pp->energia, pp->experiencia);
}

int main(void) {
	struct Personagem pChaves = {18, 20, 25};

	struct Personagem pNomes;
	pNomes.força = 10;
	pNomes.energia = 50;
	pNomes.experiencia = 30;

	PrintPersonagem(&pChaves);
	printf("\n");
	PrintPersonagem(&pNomes);
}