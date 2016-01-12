/*
 * td_memmove.c
 *
 * This file is part of the libtd project and provided under the MIT License.
 * You can refer to the LICENSE file at repository's root for complete license
 * terms.
 *
 *  Created on: 9 Jan. 2016
 *      Author: theophile
 */

#include <libtd.h>

void *
td_memmove (dst, src, count)
	void		*dst;
	const void 	*src;
	size_t		count;
{
	unsigned char		*d;
	const unsigned char	*s;

	d = dst + count;
	s = src + count;
	if (count == 0 || d == s) goto end;
	while (count-- > 0)
		*--d = *--s;

	end:	return (dst);
}
