#include <stdio.h>
#include <stdlib.h>

typedef struct Caixa {
	int valor;
	struct Caixa* prox;
} Caixa;

Caixa* insereFim(Caixa* lista, int valor);
Caixa* remover(Caixa* lista, int valor);
int contem (Caixa* lista, int valor);
void exibe(Caixa* caixa);
Caixa* concatena(Caixa* l1, Caixa* l2);



int main(void) {
	Caixa * l = NULL;
	int input;

	while (1) {
		printf("Insira inteiros [-1 para parar]: ");
		scanf("%d", &input);

		if (input == -1) {
			break;
		}

		l = insereFim(l, input);
	}

	exibe(l);
}



Caixa* insereFim(Caixa* lista, int valor) {
	Caixa* novo = (Caixa *) malloc(sizeof(Caixa));
	novo->valor = valor; novo->prox = NULL;

	Caixa* P = lista;
	Caixa* pAnt = NULL;

	while (P != NULL) {
		pAnt = P;
		P = P->prox;
	}

	if (pAnt == NULL) {
		lista = novo;
	}
	else {
		pAnt->prox = novo;
	}

	return lista;
}


Caixa* remover(Caixa* lista, int valor) {
	Caixa * pAnt = NULL;
	Caixa * P = lista;
	
	while (P != NULL && P->valor != valor) {
		pAnt = P;
		P = P->prox;
	}

	if (P != NULL) {
		if (pAnt == NULL) {
			lista = P->prox;
		}
		else {
			pAnt->prox = P->prox;
		}
		free(P);
	}
	
	return lista;
} 


int contem (Caixa* lista, int valor) {
	Caixa * P = lista;
	while (P != NULL) {
		if (P->valor == valor) {
			return 1;
		}
		P = P->prox;
	}
	return 0;
}


void exibe(Caixa* caixa) {
	printf("[");
	if (caixa != NULL) {
		Caixa * P = caixa;
		while (P->prox != NULL) {
			printf(" %d,", P->valor);
			P = P->prox;
		}

		printf(" %d", P->valor);
	}

	printf(" ]\n");
}


Caixa* concatena(Caixa* l1, Caixa* l2) {
	Caixa * R = NULL;


	Caixa * p = l1;

	while (p != NULL) {
		if (!contem(R, p->valor)) {
			R = insereFim(R, p->valor);
		}
		p = p->prox;
	}

	p = l2;

	while (p != NULL) {
		if (!contem(R, p->valor)) {
			R = insereFim(R, p->valor);
		}
		p = p->prox;
	}

	return R;
}