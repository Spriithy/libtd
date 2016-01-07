/*
 * main.c
 * This file is part of the c_td project.
 *
 *  Created on: Jan 7, 2016
 *      Author: theophile
 */
#include "tdlib.h"

int
main (void)
{
	char source[] = "once upon a midnight dreary...", dest[4];
	td_memcpy(dest, source, 4);
	for(size_t n = 0; n < 4; ++n)
		putchar(dest[n]);
}
