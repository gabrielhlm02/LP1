#include <stdio.h>

int main(void) {
	FILE * f = fopen("ex06.1.txt", "rb");
	char c;
	char str[26];

	for (int i = 0; i < 25; i++) {
		c = fgetc(f);

		if (c == EOF) {
			break;
		}
		else {
			str[i] = c;
		}
	}

	str[25] = '\0';

	fclose(f);

	printf("%s\n", str);
}