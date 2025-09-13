#include <stdio.h>
#define SIZE 5

void compra(int* conta, int valor) {
	*conta -= valor;
}

int main(void) {
	const int compras[SIZE] = { 100, 50, 80, 30, 20 };

	int minha_conta;
	printf("Insira o saldo da conta: ");
	scanf("%d", &minha_conta);

	int outra_conta;
	printf("Insira o saldo da outra conta: ");
	scanf("%d", &outra_conta);

	int* conta;

	for (int i = 0; i < SIZE; i++) {
		if (minha_conta > outra_conta) {
			conta = &minha_conta;
		}
		else {
			conta = &outra_conta;
		}

		compra(conta, compras[i]);

		printf("%dº Item\n", i+1);
		printf("Saldo conta 1: %d\nSaldo conta 2: %d\n\n", minha_conta, outra_conta);
	}
}