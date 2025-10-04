#include <stdio.h>
#define L 5
#define C 4

float cofator (int * arr, int lc, int i, int j);
float determinante (int * arr, int lc);


int main(void) {
	int lc;
	printf("Ordem: ");
	scanf("%d", &lc);
	int dd[lc][lc];
	for (int i = 0; i < lc; i++) {
		for (int j = 0; j < lc; j++) {
			printf("[%d][%d]: ", i, j);
			scanf("%d", &dd[i][j]);
		}
	}

	printf("%f\n", determinante((int *) dd, lc));
}


float cofator (int * arr, int lc, int i, int j) {
	int cofact[lc-1][lc-1];
	int a = 0, b = 0;

	for (int h = 0; h < lc; h++) {
		if (h == i) {
			continue;
		}

		b = 0;

		for (int k = 0; k < lc; k++) {
			if (k == j) {
				continue;
			}

			//printf("%d\n", *(((int *) arr) + (h * lc) + k));

			cofact[a][b] = *(((int *) arr) + (h * lc) + k);

			//printf("%d, %d, %d\n", a, b, cofact[a][b]);

			b++;
		}
		a++;
	}
	/*
	for (int i = 0; i < lc-1; i++) {
		for (int j = 0; j < lc-1; j++) {
			printf("%d ", cofact[i][j]);
		} 
		printf("\n");
	}
	*/
	return determinante((int *) cofact, lc-1);
}

float determinante (int * arr, int lc) {
	if (lc == 1) {
		return *arr;
	}

	float det = 0;
	float cof;

	for (int j = 0; j < lc; j++) {
		if (j % 2 == 0) {
			cof = 1;
		}
		else {
			cof = -1;
		}
		cof *= cofator(arr, lc, 0, j);

		det += *(((int *) arr) + (0 * lc) + (j)) * cof; 
	}

	return det;
}