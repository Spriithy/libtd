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
	List_d	*ld = listd_new ();
	for (double d = 0.1; d < 0.5; d += 0.05)
		listd_push (ld, d);
	printf ("size : %d\n", listd_len (ld));
	listd_print (ld);

        return (0);
}
