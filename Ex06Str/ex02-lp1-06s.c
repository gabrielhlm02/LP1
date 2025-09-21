#include <stdio.h>

void concatena(char* d, char* o1, char* o2) {
	int id1 = 0;
	int id2 = 0;
	for (id1; o1[id1] != '\0'; id1++) {
		d[id1] = o1[id1];
	}
	for (id2; o2[id2] != '\0'; id2++) {
		d[id1 + id2] = o2[id2];
	}
}

int main(void) {
	char dd[100], oo1[50] = "banana ", oo2[50] = "frita";

	concatena(dd, oo1, oo2);
	printf("%s\n", dd);
}