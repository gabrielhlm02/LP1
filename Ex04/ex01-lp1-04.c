#if 1


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

int main(void) {
	int n;
	printf("Insira um inteiro: ");
	scanf("%d", &n);

	char primo = eh_primo(n);
	
	printf("%d\n", primo);

	if (primo) {
		printf("%d é primo!\n", n);
	}
	else {
		printf("%d não é primo!\n", n);	
	}
}


#else


#include <stdio.h>

char eh_primo(int n) {
	if (n < 0) {
		n = -n;
	}

	if (n <= 1) {
		return 0;
	}

	for (int i = 2; i < n; i++) {
		if (n % i == 0) {
			return 0;
		}
	}

	return 1;
}

int main(void) {
	int n;
	printf("Insira um inteiro: ");
	scanf("%d", &n);

	char primo = eh_primo(n);

	printf("%d\n", primo);

	if (primo) {
		printf("%d é primo!\n", n);
	}
	else {
		printf("%d não é primo!\n", n);
	}
}


#endif