#include <stdio.h>
#include <math.h>

char eh_primo(int n) {
	if (n < 0) {
		n = -n;
	}

	if (n < 2) {
		return 0;
	}

	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			return 0;
		}
	}

	return 1;
}


void todos_os_primos(int max) {
	for (int i = 1; i <= max; i++) {
		if (eh_primo(i)) {
			printf("%d\n", i);
		}
	}
}

int main(void) {
	int n;
	printf("Insira um inteiro: ");
	scanf("%d", &n);

	printf("Os primos entre 1 e %d são:\n", n);
	todos_os_primos(n);
}