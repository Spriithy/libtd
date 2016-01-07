/*
 * td_bzero.c
 * This file is part of the c_td project.
 *
 *  Created on: Jan 7, 2016
 *      Author: theophile
 */

#include "tdlib.h"

void*
td_bzero (ptr, count)
	void	*ptr;
	size_t	count;
{
		void	*start;

		start = ptr;
		while (count--)
			*(unsigned char *) ptr++ = 0;

		return (start);
}
