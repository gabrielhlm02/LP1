#include <stdio.h>

void compra(int* conta, int valor) {
	if (*conta < valor) {
		printf("SALDO INSUFICIENTE!\n");
	}
	else {
		*conta -= valor;	
	}
}

int main(void) {
	int minha_conta;
	int outra_conta;
	
	int * contadeb;
	int valordeb = 500;

	printf("Insira a quantia na primeira conta: ");
	scanf("%d", &minha_conta);

	printf("Insira a quantia na segunda conta: ");
	scanf("%d", &outra_conta);

	if (minha_conta > outra_conta) {
		contadeb = &minha_conta;
	}
	else {
		contadeb = &outra_conta;
	}

	compra(contadeb, valordeb);

	printf("Conta 1: %d\nConta 2: %d\n", minha_conta, outra_conta);
}