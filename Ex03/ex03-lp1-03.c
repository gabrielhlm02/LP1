#include <stdio.h>

int main(void) {
    char temps[50];
    float media = 0;
    char acima = 0;
    char aux;

    printf("Insira as temperaturas: ");

    for (char i = 0; i < 50; i++) {
        scanf("%hhd", &aux);
        if ((aux < -100) || (aux > 100)) {
            printf("%hhdª temperatura fora dos limites!\n", i+1);
            i--;
        }
        else {
            temps[i] = aux;
            media += aux;
        }
    }

    media /= 50;
    printf("A média é %.2f!\n", media);

    for (char i = 0; i < 50; i++) {
        if (temps[i] > media) {
            acima += 1;
        }
    }

    printf("%hhd temperaturas acima da média.\n", acima);
}
