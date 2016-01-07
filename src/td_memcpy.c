/* 
 * td_memcpy.c
 * This file is part of the c_td project.
 *
 *  Created on: Jan 8, 2016
 *      Author: theophile
 *
 */

#include "tdlib.h"

void*
td_memcpy (dst, src, count)
	void		*dst;
	const void	*src;
	size_t		count;
{
		void 	*start;

		start = dst;
		while (count--)
			*(unsigned char *) dst++ = *(unsigned char *) src++;
		return (start);
}
