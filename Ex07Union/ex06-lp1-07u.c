#include <stdio.h>

union Ponto {
	int vec[3];
	struct {
		int x, y, z;
	};
};

int main(void) {
	union Ponto pt;
	pt.vec[0] = 10;
	pt.vec[1] = 20;
	pt.vec[2] = 30;
	printf("(%d,%d,%d)\n", pt.x, pt.y, pt.z);
}