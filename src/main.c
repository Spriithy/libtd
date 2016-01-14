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
#include <stdio.h>
#include <libtd.h>

int
main (void)
{
	lists_print (td_strsplit("Foo Bar Baz"));
	char	*str = "Foo Bar Baz j'te met une base";
	printf ("<%s>\n", str);

	td_strtoupper (str);
	
        return (0);
}
