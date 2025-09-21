#include <stdio.h>

void concatena (char* d, char* o1, char*o2) {
	int aid = 0;
	for (aid; o1[aid] != '\0'; aid++) {
		d[aid] = o1[aid];
	}
	int bid = 0;
	for (bid; o2[bid] != '\0'; bid++) {
		d[aid+bid] = o2[bid];
	}
}

int main(void) {
	char a[50] = "Hello";
	char b[50] = "World";
	char d[100];

	concatena(d, a, b);

	printf("%s\n", d);
}