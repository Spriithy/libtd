/*
 * td_memccpy.c
 *
 * This file is part of the libtd project and provided under the MIT License.
 * You can refer to the LICENSE file at repository's root for complete license
 * terms.
 *
 *  Created on: 9 janv. 2016
 *      Author: theophile
 */

#include <td/string.h>

void *
td_memccpy (dst, src, c, count)
	void		*dst;
	const void	*src;
	int		c;
	size_t		count;
{
	if (count) {
		unsigned char 		*d;
		const unsigned char	*s;

		d = dst;
		s = src;
		do {
			if ((*d++ = *s++) == c)
				return (dst);
		} while (count-- > 0);
	}

	return (TD_NULL);
}
