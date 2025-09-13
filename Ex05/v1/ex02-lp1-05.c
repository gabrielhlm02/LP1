#include <stdio.h>

void compra(int* conta, int valor) {
	*conta -= valor;
}



int main(void) {
	int minha_conta;
	printf("Insira o saldo da conta: ");
	scanf("%d", &minha_conta);

	int outra_conta;
	printf("Insira o saldo da outra conta: ");
	scanf("%d", &outra_conta);

	int* conta;

	if (minha_conta > outra_conta) {
		conta = &minha_conta;
	}
	else {
		conta = &outra_conta;
	}

	int valor;
	printf("Insira o valor do produto: ");
	scanf("%d", &valor);

	if (valor > *conta) {
		printf("SALDO INSUFICIENTE!\n");
	}
	else {
		compra(conta, valor);
	}

	printf("Saldo conta 1: %d\nSaldo conta 2: %d\n", minha_conta, outra_conta);
}