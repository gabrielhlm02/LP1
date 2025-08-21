#include <stdio.h>

int main(void) {
	int n1;
	int n2;
	printf("Digite um número: ");
	scanf("%d", &n1);
	printf("Digite outro número: ");
	scanf("%d", &n2);

	int strt;
	int *end;
	if (n1 > n2) {
		strt = n2;
		end = &n1;

	}

	else {
		strt = n1;
		end = &n2;
	}

	while (strt <= *end) {
		printf("%d\n", strt);
		strt++;
	}
}