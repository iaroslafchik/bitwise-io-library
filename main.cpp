#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "bitio.h"

int main(int argc, char* argv[]) {
	int bits = 0;
	printf("Program \"%s\" reads from file \"%s\" and writes to file \"%s\"\n", argv[0], argv[1], argv[2]);

	if (argv[1]) {
		bopenr(argv[1]);
		for (int counter = 0; !beof(); counter++) {
			if (counter % 8 == 0 && counter != 0) {
				printf(".");
			}
			printf("%d", bgetbit());
		}
		bcloser();
	}

	if (argv[2]) {
		bopenw(argv[2]);
		for (int i = 1; i < 10; i++) {
			for (int j = 0; j < i; j++) {
				bputbit(0);
			}
			for (int j = 0; j < i; j++) {
				bputbit(1);
			}
		}
		bclosew();
	}
}