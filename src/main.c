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
 * main.c
 * This file is part of the td_libc project.
 *
 *  Created on: Jan 7, 2016
 *      Author: theophile
 */
#include "../include/tdstring.h"
#include "../include/tdstrings.h"
#include <stdio.h>

void
demo (const char* lhs, const char* rhs, size_t sz)
{
	for (size_t n = 0; n < sz; ++n)
		putchar (lhs[n]);
	int rc = td_memcmp (lhs, rhs, sz);
	if (rc == 0)
	printf (" compares equal to ");
	else if (rc < 0)
	printf (" precedes ");
	else if (rc > 0)
		printf (" follows ");
	for (size_t n = 0; n < sz; ++n)
		putchar (rhs[n]);
	puts (" in lexicographical order");
}

int
main (void)
{
	char source[] = "once upon a midnight dreary...", dest[11];
	td_memset (source, 104, 4);
	td_bcopy (source, dest, 10);
	dest[10] = '\0';
	printf ("<%s>\n", dest);
	printf ("%d\n", td_bcmp (source, dest, 10));
	printf ("%d\n", td_strlen ("foo bar baz"));

	char dst[] = "oldstring";
	const char src[] = "newstring";
	printf ("Before memmove dst = %s, src = %s\n", dst, src);
	td_memmove (dst, src, 9);
	printf ("After memmove dst = %s, src = %s\n", dst, src);

	char str[] = "ABCDEFG";
	char *ps = td_memchr (str, 'D', td_strlen (str));
	if (ps != NULL)
	printf ("search character found:  %s\n", ps);
	else
	printf ("search character not found\n");

	char a1[] =
		{ 'a', 'b', 'c' };
	char a2[sizeof a1] =
		{ 'a', 'b', 'd' };
	demo (a1, a2, sizeof a1);
	demo (a2, a1, sizeof a1);
	demo (a1, a1, sizeof a1);

	return (0);
}
