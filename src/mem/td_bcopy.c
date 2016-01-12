/*
 * td_bcopy.c
 *
 * This file is part of the libtd project and provided under the MIT License.
 * You can refer to the LICENSE file at repository's root for complete license
 * terms.
 *
 *  Created on: 9 Jan. 2016
 *      Author: theophile
 */

void
td_bcopy (src, dst, count)
	const void 	*src;
	void		*dst;
	int		count;
{
	while (count-- > 0)
		*(unsigned char *) dst++ = *(unsigned char *) src++;
}
