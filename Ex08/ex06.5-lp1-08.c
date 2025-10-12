#include <stdio.h>
#include <string.h>

void escreva_string (FILE *f, char *str) {
	for (int i = 0; i < strlen(str); i++) {
		fputc(str[i], f);
	}
}

int main(void) {
	FILE * f = fopen("/tmp/ex06.5.txt", "wb");

	escreva_string (f, "O rato roeu a roupa do rei de Roma.");

	fclose(f);
}