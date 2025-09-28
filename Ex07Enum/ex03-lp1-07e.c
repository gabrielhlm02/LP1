#include <stdio.h>

typedef enum {true=1, false=0} Boolean;

int main(void) {
	Boolean falso = true;

	if (falso) {
		printf("verdadeiro");
	}
	else {
		printf("falso");
	}

	printf("\n");

	falso = false;

	if (falso) {
		printf("verdadeiro");
	}
	else {
		printf("falso");
	}

	printf("\n");

	printf("%lu\n", sizeof(falso));
}