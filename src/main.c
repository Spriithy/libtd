/*
 * main.c
 *
 * This file is part of the libtd project and provided under the MIT License.
 * You can refer to the LICENSE file at repository's root for complete license
 * terms.
 *
 *  Created on: Jan 7, 2016
 *      Author: theophile
 */

#include <stdio.h>
#include <td/string.h>
#include <td/mem.h>
#include <td/math.h>

int
main (void)
{
	char	*foo;
	char	*source = "Je suis une taupe n'est-ce pas ?";
	foo = td_strdup(source);
	printf("<%s>\n", foo);
	
	return (0);
}
