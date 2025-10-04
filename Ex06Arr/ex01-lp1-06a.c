#include <stdio.h>
#define L 5
#define C 4

void preenche (int arr[L][C], int l, int c);

int main(void) {
	int aray[L][C];
	preenche (aray, 4, 3);

	for (int i = 0; i < L; i++) {
		for (int j = 0; j < C; j++) {
			printf("%d ", aray[i][j]);
		}
	}
	printf("\n");
}

#if 1
void preenche (int arr[L][C], int l, int c) {
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < c; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
}

#elif 1
void preenche (int arr[L][C], int l, int c) {
	for (int i = 0; i < l*c; i++) {
		scanf("%d", &arr[i/C][i%C]);
	}
}

#else
void preenche (int arr[L][C], int l, int c) {
	for (int i = 0; i < l*c; i++) {
		//scanf("%d", (((int *) arr) + i));
		scanf("%d", ((int *) arr) + ((i/C)*C) + (i%C)); // :)
	}
}
#endif