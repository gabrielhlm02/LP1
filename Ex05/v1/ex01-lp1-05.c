#include <stdio.h>

int main(void) {
	int a;
	int b;

	scanf("%d %d", &a, &b);
	printf("a:%d, b:%d\n", a, b);

	int* p;

	if (a > b) {
		p = &a;
	}
	else {
		p = &b;
	}

	*p -= 50;

	printf("a:%d, b:%d\n", a, b);
}