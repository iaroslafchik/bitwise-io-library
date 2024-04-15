#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

bool bopenr(const char* filename);

bool bopenw(const char* filename);

bool beof();

int bgetbit();

void bputbit(bool bit);

void bcloser();

void bclosew();