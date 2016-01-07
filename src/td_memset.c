/*
 * td_memset.c
 * This file is part of the c_td project.
 *
 *  Created on: Jan 7, 2016
 *      Author: theophile
 */

#include "tdlib.h"

void*
td_memset (ptr, c, count)
	void	*ptr;
	int		c;
	size_t 	count;
{
		void	*start;

		start = ptr;
		while (count--)
			*(unsigned char *) ptr++ = (unsigned char) c;

		return (start);
}

