/*
 * td_memcmp.c
 *
 * This file is part of the libtd project and provided under the MIT License.
 * You can refer to the LICENSE file at repository's root for complete license
 * terms.
 *
 *  Created on: 9 Jan. 2016
 *      Author: theophile
 */

#include <libtd.h>

int
td_memcmp (s1, s2, count)
	const void	*s1, *s2;
	size_t		count;
{
	const unsigned char	*m;
	const unsigned char	*n;

	m = s1;
	n = s2;
	do {
		if (*m++ != *n++)
			return (*(m - 1) - *(n - 1));
	} while (count-- > 0);

	return (0);
}
