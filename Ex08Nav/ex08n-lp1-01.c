#include <stdio.h>
#include <assert.h>

int main(void) {
	FILE * f = fopen("01.txt", "r");

	int linha;

	char idade[4];
	char UF[3];

	printf("Qual linha deseja visualizar: ");
	scanf("%d", &linha);
	linha = (linha-1)*22;

	if(linha < 0){
		printf("registro nao encontrado\n");
		return 0;
	}

	/*fseek(f, 0, SEEK_END);
	if(linha < 0 || linha > ftell(f)){
		printf("registro nao encontrado\n");
		return 0;
	}*/

	fseek(f, linha, SEEK_SET);

	fseek(f, 9, SEEK_CUR);
	int err = fread(idade, sizeof(char), 3, f);
	idade[3] = '\0';

	if(err != 3){
		printf("registro nao encontrado\n");
		return 0;
	}

	fseek(f, 7, SEEK_CUR);
	err = fread(UF, sizeof(char), 2, f);
	UF[2] = '\0';

	if(err != 2){
		printf("registro nao encontrado\n");
		return 0;
	}

	printf("Idade: %s\nEstado: %s\n", idade, UF);


	fseek(f, linha, SEEK_SET);
	for(int i = 0; i < 22; i++) {
		printf("%c", fgetc(f));
	}
}
