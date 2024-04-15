#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
typedef unsigned char uchar;

FILE *fpr, *fpw;

uchar rBitMask = 128, wBitMask = 128;
uchar rBuf, wBuf;

bool bopenr(const char *filename) {
	fpr = fopen(filename, "rb");
	fread(&rBuf, sizeof(uchar), 1, fpr);
	return 0;
}

bool bopenw(const char *filename) {
	fpw = fopen(filename, "wb");
	return 0;
}

bool beof() {
	return feof(fpr) ? 1 : 0;
}

int bgetbit() {
	int bit = rBuf & rBitMask ? 1 : 0;
	rBitMask >>= 1;
	if (rBitMask == 0) {
		fread(&rBuf, sizeof(uchar), 1, fpr);
		rBitMask = 128;
	}
	return bit;
}

void bputbit(bool bit) {
	bit ? wBuf |= wBitMask : wBuf;
	wBitMask >>= 1;
	if (wBitMask == 0) {
		fwrite(&wBuf, sizeof(uchar), 1, fpw);
		wBitMask = 128, wBuf = 0x00;
	}
}

void bcloser() {
	fclose(fpr);
}

void bclosew() {
	if (wBitMask != 128) fwrite(&wBuf, sizeof(uchar), 1, fpw);
	fclose(fpr);
}