#include <stdio.h>

int main(void) {
	int times[20];
	int pontos[20];
	int maior = 0;
	int menor = 0;
	int aux;

	int i;
	for (i = 0; i < 20; i++) {
		printf("Escolha um time: ");
		scanf("%d", &aux);
		//printf("%d\n", aux);
		times[i] = aux;

		printf("Insira o número de vitórias do time %d: ", times[i]);
		scanf("%d", &aux);
		//printf("%d\n", aux);
		pontos[i] = aux * 3;

		printf("Insira o número de empates do time %d: ", times[i]);
		scanf("%d", &aux);
		//printf("%d\n", aux);
		pontos[i] += aux * 1;

		printf("Insira o número de derrotas do time %d: ", times[i]);
		scanf("%d", &aux);
		//printf("%d\n", aux);
		//pontos[i] += aux * 0;

		//printf("%d\n", pontos[i]);

		if (pontos[i] > pontos[maior]) {
			maior = i;
		}

		if (pontos[i] < pontos[menor]) {
			menor = i;
		}
	}

	printf("Mais pontos: Time %d.\n", times[maior]);
	printf("Menos pontos: Time %d.\n", times[menor]);
}