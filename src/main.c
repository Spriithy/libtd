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
	Dict_i *di = dicti_new ();
	dicti_add (di, "Foo", 10);
	dicti_add (di, "Bar", 11);
	dicti_add (di, "Baz", 12);
	dicti_print (di);
	printf ("%d\n", dicti_posof (di, "Bar"));
	dicti_remove (di, "Bar");
	dicti_print (di);
	printf ("%d\n",  dicti_get (di, "Baz"));
	dicti_del (di);
	
        return (0);
}
