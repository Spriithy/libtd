/*
 * List_c.c
 *
 * This file is part of the libtd project and provided under the MIT License.
 * You can refer to the LICENSE file at repository's root for complete license
 * terms.
 *
 *  Created on: Jan 11, 2016
 *      Author: theophile
 */

#include <stdlib.h>
#include <stdio.h>
#include <libtd.h>

static void grow (l, dt)
        List_c	*l;
        int     dt;
{
        td_assert (dt > 0);
        if (l->size + dt <= l->capacity)
                return ;
        l->capacity = l->size + dt;
	if ((l->data = realloc (l->data, l->capacity * sizeof (char))) == NULL) {
		fprintf(stderr, "%s:%d: Malloc failed -~- cannot grow current "
			"List_c", __FILE__, __LINE__);
                exit (EXIT_FAILURE);
        }
}

List_c *
listc_new (void)
{
        List_c	*l;

        l = calloc (1, sizeof (List_c));
        l->capacity = TD_CHRLIST_DEFAULT_SIZE;
        l->size = 0;
        if ((l->data = malloc ((l->capacity + 1) * sizeof (char))) == NULL) {
                fprintf (stderr, "%s:%d: Malloc failed -~- can't allocate memory"
			" for new List_c\n", __FILE__, __LINE__);
                exit (EXIT_FAILURE);
        }

        return (l);
}

List_c *
listc_init (sz, items)
        size_t  sz;
        int     *items;
{
        List_c	*l;
        int     i;

        l = calloc (1, sizeof (List_c));
        l->capacity = sz;
        l->size = 0;
	if ((l->data = malloc (l->capacity * sizeof (char))) == NULL) {
		fprintf(stderr, "%s:%d: Malloc failed -~- can't allocate memory"
			" for new List_c\n", __FILE__, __LINE__);
                exit (EXIT_FAILURE);
        }
        i = sz;
        while (i-- > 0)
                listc_push (l, items[sz - i - 1]);

        return (l);
}

List_c *
listc_cpy (l)
        List_c	*l;
{
        return (listc_init (l->size, (int *) l->data));
}

List_c *
listc_flip (l)
        List_c	*l;
{
        List_c	*r;
        size_t  sz;

        r = listc_new ();
        sz = l->size;
        r->size = sz;
        r->capacity = sz;
        while (sz-- > 0)
                listc_push (r, listc_get (l, sz));

        return (r);
}

size_t
listc_len (l)
        List_c	*l;
{
        return l->size;
}

size_t
listc_cap (l)
        List_c	*l;
{
        return l->capacity;
}

void
listc_push (l, el)
        List_c	*l;
        int     el;
{
        if (l->size == l->capacity)
                grow (l, 1);
        l->data[l->size++] = (char) el;
}

char
listc_pop (l)
        List_c	*l;
{
        td_assert (l->size != 0);

        return (l->data[--l->size]);
}

char
listc_get (l, at)
        List_c	*l;
        size_t  at;
{
        td_assert (at < l->size);

        return (l->data[at]);
}

void
listc_set (l, at, el)
        List_c	*l;
        size_t  at;
        int     el;
{
        td_assert (at < l->size);

        l->data[at] = (char) el;
}

char
listc_front (l)
        List_c	*l;
{
        td_assert (l->size > 0);

        return (l->data[0]);
}

char
listc_tail (l)
        List_c	*l;
{
        td_assert (l->size > 0);

        return (l->data[l->size - 1]);
}

void
listc_remove (l, at)
        List_c	*l;
        size_t  at;
{
        size_t  ofs;
        char    *d;

        td_assert (l->size > 0);
        td_assert (at <= l->size);

        d = l->data + at;
        ofs = l->size - (at + 1);
        while (ofs-- > 0) {
                *d = *(d + 1);
                d++;
        }
        l->size--;
}

void
listc_append (l0, l1)
        List_c	*l0;
        List_c	*l1;
{
        size_t  sz;

        sz = l1->size;
        if (sz == 0)
                return ;
        if (l0->size + sz > l0->capacity)
                grow (l0, l0->capacity - sz);
        while (sz-- > 0)
                listc_push (l0, listc_get (l1, l1->size - sz));
}

void
listc_del (l)
        List_c	*l;
{
        free (l->data);
        free (l);
}

int
listc_cmp (l0, l1)
        List_c	*l0;
        List_c	*l1;
{
        size_t  sz;

        td_assert ((sz = l0->size) == l1->size);
        while (sz-- > 0)
                if (l0->data[sz] != l1->data[sz])
                        return (0);

        return (1);
}

int
listc_ncmp (l0, l1, count)
        List_c	*l0;
        List_c	*l1;
        size_t  count;
{
        td_assert (l0->size >= count);
        td_assert (l1->size >= count);

        while (count-- > 0)
                if (l0->data[count] != l1->data[count])
                        return (0);

        return (1);
}

void
listc_print (l)
        List_c	*l;
{
        size_t  sz;

        sz = 0;
        printf ("[ ");
        while (sz < l->size) {
                printf (((sz == l->size - 1) ? "\'%c\' " : "\'%c\', "),
                        listc_get (l, sz));
                sz++;
        }
        printf ("]\n");
}
