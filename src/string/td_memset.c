/*
 * td_memset.c
 *
 * This file is part of the libtd project and provided under the MIT License.
 * You can refer to the LICENSE file at repository's root for complete license
 * terms.
 *
 *  Created on: Jan 7, 2016
 *      Author: theophile
 */

#include <td/string.h>

void *
td_memset (ptr, c, count)
	void	*ptr;
	int	c;
	size_t	count;
{
	void	*start;

	start = ptr;
	while (count-- > 0)
		*(unsigned char *) ptr++ = (unsigned char) c;

	return (start);
}
