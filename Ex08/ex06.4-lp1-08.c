#include <stdio.h>
#include <string.h>

int main(void) {
	char strs[10][26];
	FILE * f = fopen("/tmp/ex06.4.txt", "wb");

	for (int k = 0; k < 10; k++) {
		scanf("%25s", strs[k]);
		strs[k][25] = '\0';
	}

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < strlen(strs[i]); j++) {
			fputc(strs[i][j], f);
		}
		//fputc('\n', f);
	}

	fclose(f);
}