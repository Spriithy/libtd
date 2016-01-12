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
#include <td/strList.h>
#include <td/chrList.h>
#include <td/intList.h>

int
main (void)
{
        intList	*il = intlist_new ();
        strList *sl = strlist_new ();
        chrList *cl = chrlist_new ();

        int i = 0;
        while (i < 16)
        {       intlist_push (il, i);
                chrlist_push (cl, 'a' + i);
                i++;
        }

        strlist_push (sl, "Foo");
        strlist_push (sl, "Bar");
        strlist_push (sl, "Baz");

        intlist_print (il);
        intlist_remove (il, 15);
        intlist_print (il);

        strlist_print (sl);
        strlist_remove (sl, 0);
        strlist_print (sl);

        chrlist_print	(cl);
        chrlist_remove	(cl, 13);
        chrlist_print	(cl);

        strList *slc = strlist_cpy (sl);
        strlist_print (slc);

        printf ("%d %d %d\n",
        intlist_cmp (il, il),
        chrlist_cmp (cl, cl),
        strlist_cmp (sl, slc));

        intlist_del (il);
        strlist_del (slc);
        strlist_del (sl);
        chrlist_del (cl);

        return (0);
}
