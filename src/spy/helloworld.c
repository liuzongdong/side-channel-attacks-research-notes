#include <stdio.h>



int fooA() {
	int x = 4;
	int y = 4;
	int z = x / y;
	return z;
}


void fooB() {
	int a = 3;
	int b = 4;
	int c = a * b * a * b * a;
	printf("%d \n", c);
}

int main() {
	fooB();
}
