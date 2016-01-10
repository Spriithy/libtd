/*
 * td_bzero.c
 *
 * This file is part of the libtd project and provided under the MIT License.
 * You can refer to the LICENSE file at repository's root for complete license
 * terms.
 *
 *  Created on: Jan 7, 2016
 *      Author: theophile
 *
 * This is the td_bzero implementation that zeroes a chunk of memory to be zero.
 * The block size must already be owned (malloc, calloc ...) and count must not
 * exceed its length.
 */

void
td_bzero (ptr, count)
	void	*ptr;
	int	count;
{
	while (count-- > 0)
		*(unsigned char *) ptr++ = 0;
}
