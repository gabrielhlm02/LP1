#include <stdio.h>

int main(void) {
	float price;
	printf("Qual o preço do celular em dólares: U$");
	scanf("%f", &price);
	price = price * 3.17;
	if (price <= 1000) {
		printf("BOM NEGÓCIO (%f)\n", price);
	}

	else {
		printf("MAU NEGÓCIO (%f)\n", price);
	}
}