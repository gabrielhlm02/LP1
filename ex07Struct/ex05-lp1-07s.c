#include <stdio.h>

struct Ponto {
	int x;
	int y;
	int z;
};

int main(void) {
	struct Ponto v1 = {1, 0, 5};
	struct Ponto v2 = {3, 3, 3};
	struct Ponto v3 = {0, 10, 0};

	printf("v1: %d\nv2: %d\nv3: %d\n", v1.y, v2.y, v3.y);
	v1.z += 10; v2.z += 10; v3.z += 10;
	printf("xv2: %d\nyv2: %d\nzv2: %d\n", v2.x, v2.y, v2.z);
}