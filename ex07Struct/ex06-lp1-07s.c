#include <stdio.h>

// "esporte favorito" => jogo genérico de kart...
struct rcKart {
	char nome[15];
	float vel;		// VELocidade
	float acc;		// ACeleraÇão
	int sorte;		// para itens
	char peso[10];	// resistêcia a itens
	float rank;		// nivel do jogador com personagem
};

void mkBar(float limite) {		// barra para apresentar status de vel e acc
	float bar = (int) limite; // arredonda limite para baixo (assume limite positivo)
	int it = 0;
	//printf("%f", bar);
	for (it; it < bar; it++) {
		if (it % 2 == 0) {
			printf("oOoOo");
		}
		else {
			printf("OoOoO");
		}

	}
	while (bar < limite) {
		if (it%2==1) {
			printf("O");
		}
		else {
			printf("o");
		}
		it++;
		bar += 0.2f;
	}
	printf("\n");
}

void showStats(struct rcKart * pup) {
	printf("--o--o--o--o--o--o--o--o--o--o--o--o--o--o--o--o--o--o--o--o--o--\n\n");
	printf("%s	%.1f\n\n", pup->nome, pup->rank);
	printf("Velocidade:\n");
	mkBar(pup->vel);
	printf("\nAceleração:\n");
	mkBar(pup->acc);
	printf("\nPeso:\n%s\n", pup->peso);
	printf("\nSorte:\n");
	for (int i =0; i < pup->sorte; i++) {
		printf("*");
	}
	printf("\n");
}

int main(void) {
	struct rcKart p1 = {"X", 1.2, 0.8, 2, "Médio", 7.8};
	struct rcKart p2 = {"Y", 2, 0.5, 1, "Pesado", 5.6};
	struct rcKart p3 = {"Z", 1.7, 1, 3, "Leve", 9.1};
	showStats(&p1);
	printf("\n");
	showStats(&p2);
	printf("\n");
	showStats(&p3);
	printf("\n");
}