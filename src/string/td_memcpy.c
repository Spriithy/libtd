/*
 * td_memcpy.c
 *
 * This file is part of the libtd project and provided under the MIT License.
 * You can refer to the LICENSE file at repository's root for complete license
 * terms.
 *
 *  Created on: Jan 8, 2016
 *      Author: theophile
 */

#include <td/string.h>
#include <td/mem.h>

void *
td_memcpy (dst, src, count)
	void		*dst;
	const void	*src;
	size_t		count;
{
		td_bcopy (src, dst, count);
		return (dst);
}
