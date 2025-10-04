#include <stdio.h>
#define L 5
#define C 4

float cofator (int arr[L][C], int lc, int i, int j);
float determinante (int arr[L][C], int lc);


int main(void) {
	int dd[L][C];
	int lc = 3;
	for (int i = 0; i < lc; i++) {
		for (int j = 0; j < lc; j++) {
			dd[i][j] = 3;
		}
	}
	dd[0][0] = 4;

	printf("%f", determinante(dd, lc));
}


float cofator (int arr[L][C], int lc, int i, int j) {
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

			//printf("%d\n", arr[h][k]);

			cofact[a][b] = arr[h][k];

			//printf("%d, %d, %d\n", a, b, cofact[a][b]);

			b++;
		}
		a++;
	}

	/*for (int i = 0; i < lc-1; i++) {
		for (int j = 0; j < lc-1; j++) {
			printf("%d ", cofact[i][j]);
		} 
		printf("\n");
	}*/

	return determinante(cofact, lc-1);
}

float determinante (int arr[L][C], int lc) {
	if (lc == 1) {
		return arr[0][0];
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

		det += arr[0][j] * cof; 
	}

	return det;
}