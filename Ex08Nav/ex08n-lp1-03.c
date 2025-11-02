#include <stdio.h>

int main(void) {
	char arq[128] = {0};
	scanf("%128s", arq);
	FILE * f = fopen(arq, "r+");
	
	fseek(f, 0, SEEK_END);

	long int fim = ftell(f);

	long meio = fim/2;

	char dir[fim-meio];

	fseek(f, meio, SEEK_SET);

	fread(dir, sizeof(char), sizeof(dir), f);

	fseek(f, meio, SEEK_SET);

	fwrite("|meio|", 1, 6, f);

	fwrite(dir, sizeof(char), sizeof(dir), f);
}
