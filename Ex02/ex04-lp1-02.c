#include <stdio.h>

int main(void) {
	float kph;
	float mph;

	printf("Idique a velocidade atual em milhas por hora: ");
	scanf("%f", &mph);

	kph = mph * 1.6;

	if (kph < 80) {
		printf("ACELERE!");
	}
	else if (kph > 100) {
		printf("DESACELERE!");
	}
	else {
		printf("MANTENHA!");
	}
	printf(" (%.2f)\n", kph);
}