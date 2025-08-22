#include <stdio.h>

int main(void) {
	int times[20] = {0};
	int pontos[20] = {0};
	int menor = 0;
	int maior = 0;
	int aux;

	for (int i=0; i < 5; i++) {
		printf("Insira o número de identificação do time: ");
		scanf("%d", &times[i]);

		printf("Insira o número de vitórias: ");
		scanf("%d", &aux);
		pontos[i] += aux*3;

		printf("Insira o número de empates: ");
		scanf("%d", &aux);
		pontos[i] += aux*1;

		printf("Insira o número de derrotas: ");
		scanf("%d", &aux);
		pontos[i] += aux*0;

		if (pontos[i] >= pontos[maior]) {
			maior = i;
		}

		else if (pontos[i] <= pontos[menor]) {
			menor = i;
		}
	}

	printf("O time %d obteve o maior número de pontos (%d)!\n", times[maior], pontos[maior]);
	printf("O time %d obteve o menor número de pontos (%d)!\n", times[menor], pontos[menor]);
}