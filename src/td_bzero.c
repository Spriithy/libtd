/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2016 Theophile Dano, Spriithy
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * td_bzero.c
 * This file is part of the c_td project.
 *
 *  Created on: Jan 7, 2016
 *      Author: theophile
 *
 * This is the td_bzero implementation that zeroes a chunk of memory to be zero.
 * The block size must already be owned (malloc, calloc ...) and count must not
 * exceed its length.
 */

#include "../include/tdstrings.h"

#define BZ0_VAL 0

void
td_bzero (ptr, count)
		void	*ptr;
		size_t	count;
{
		while (count-- > 0)
			*(unsigned char *) ptr++ = BZ0_VAL;
}
