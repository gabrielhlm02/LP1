#include <stdio.h>
#include <string.h>

int main(void) {
	FILE * f = fopen("ex01.txt", "w");
	
	char str[26];
	scanf("%25s", str);
	str[25] = '\0';
	
	for (int i = 0; i < strlen(str); i++) {
		fputc(str[i], f);
	}

	fclose(f);
}