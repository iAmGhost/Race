#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <avr/io.h>

void DotMatrix_init();
void DotMatrix_drawPixel(int x, int y);
void DotMatrix_removePixel(int x, int y);
void DotMatrix_draw();
void DotMatrix_clear();
void DotMatrix_reset();
