/*
 * td_memchr.c
 *
 * This file is part of the libtd project and provided under the MIT License.
 * You can refer to the LICENSE file at repository's root for complete license
 * terms.
 *
 *  Created on: 9 janv. 2016
 *      Author: theophile
 */

#include <td/string.h>
#include <td/tdef.h>

void *
td_memchr (ptr, c, count)
	const void	*ptr;
	int		c;
	size_t		count;
{
	const unsigned char	*p;

	if (count != 0) {
		p = ptr;
		do {
			if (*p++ == c)
				return ((void *) (p - 1));
		} while (count-- > 0);
	}

	return (TD_NULL);
}
