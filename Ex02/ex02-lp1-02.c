#include <stdio.h>

int main(void) {
	int in1;
	int in2;
	int maior;

	printf("Insira um número: ");
	scanf("%d", &in1);

	printf("Insira outro número: ");
	scanf("%d", &in2);

	if (in1 > in2) {
		maior = in1;
	} 

	else {
		maior = in2;
	}

	printf("%d foi o maior número!\n", maior);
}

/*
int main(void) {
	int in1;
	int in2;

	printf("Insira um número: ");
	scanf("%d", &in1);
	
	printf("Insira outro número: ");
	scanf("%d", &in2);

	if (in1 > in2) {
		printf("%d foi o maior número!\n", in1);
	}

	else {
		printf("%d foi o maior número!\n", in2);
	}

} */