/*
 * List_ul.c
 *
 * This file is part of the libtd project and provided under the MIT License.
 * You can refer to the LICENSE file at repository's root for complete license
 * terms.
 *
 *  Created on: Jan 12, 2016
 *      Author: theophile
 */

#include <stdlib.h>
#include <stdio.h>
#include <libtd.h>

static void grow (l, dt)
        List_ul	*l;
        int     dt;
{
        td_assert (dt > 0);
        if (l->size + dt <= l->capacity)
                return ;
        l->capacity = l->size + dt;
	if ((l->data = realloc (l->data, l->capacity * sizeof (unsigned long))) == NULL) {
		fprintf(stderr, "%s:%d: Malloc failed -~- cannot grow current "
			"List_ul", __FILE__, __LINE__);
                exit (EXIT_FAILURE);
        }
}

List_ul *
listul_new (void)
{
        List_ul	*l;

        l = calloc (1, sizeof (List_ul));
        l->capacity = TD_ULLIST_DEFAULT_SIZE;
        l->size = 0;
        if ((l->data = malloc ((l->capacity + 1) * sizeof (unsigned long))) == NULL) {
                fprintf (stderr, "%s:%d: Malloc failed -~- can't allocate memory"
			" for new List_ul\n", __FILE__, __LINE__);
                exit (EXIT_FAILURE);
        }

        return (l);
}

List_ul *
listul_init (sz, items)
        size_t		sz;
        unsigned long	*items;
{
        List_ul	*l;
        int     i;

        l = calloc (1, sizeof (List_ul));
        l->capacity = sz;
        l->size = 0;
	if ((l->data = malloc (l->capacity * sizeof (unsigned long))) == NULL) {
		fprintf(stderr, "%s:%d: Malloc failed -~- can't allocate memory"
			" for new List_ul\n", __FILE__, __LINE__);
                exit (EXIT_FAILURE);
        }
        i = sz;
        while (i-- > 0)
                listul_push (l, items[sz - i - 1]);

        return (l);
}

List_ul *
listul_cpy (l)
        List_ul	*l;
{
        return (listul_init (l->size, l->data));
}

List_ul *
listul_flip (l)
        List_ul	*l;
{
        List_ul	*r;
        size_t  sz;

        r = listul_new ();
        sz = l->size;
        r->size = sz;
        r->capacity = sz;
        while (sz-- > 0)
                listul_push (r, listul_get (l, sz));

        return (r);
}

size_t
listul_len (l)
        List_ul	*l;
{
        return l->size;
}

size_t
listul_cap (l)
        List_ul	*l;
{
        return l->capacity;
}

void
listul_push (l, el)
        List_ul		*l;
        unsigned long	el;
{
        if (l->size == l->capacity)
                grow (l, 1);
        l->data[l->size++] = el;
}

unsigned long
listul_pop (l)
        List_ul	*l;
{
        td_assert (l->size != 0);

        return (l->data[--l->size]);
}

unsigned long
listul_get (l, at)
        List_ul	*l;
        size_t  at;
{
        td_assert (at < l->size);

        return (l->data[at]);
}

void
listul_set (l, at, el)
        List_ul		*l;
        size_t		at;
        unsigned long	el;
{
        td_assert (at < l->size);

        l->data[at] = el;
}

unsigned long
listul_front (l)
        List_ul	*l;
{
        td_assert (l->size > 0);

        return (l->data[0]);
}

unsigned long
listul_tail (l)
        List_ul	*l;
{
        td_assert (l->size > 0);

        return (l->data[l->size - 1]);
}

void
listul_remove (l, at)
        List_ul		*l;
        size_t		at;
{
        size_t		ofs;
        unsigned long    *d;

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
listul_append (l0, l1)
        List_ul	*l0;
        List_ul	*l1;
{
        size_t  sz;

        sz = l1->size;
        if (sz == 0)
                return ;
        if (l0->size + sz > l0->capacity)
                grow (l0, l0->capacity - sz);
        while (sz-- > 0)
                listul_push (l0, listul_get (l1, l1->size - sz));
}

void
listul_del (l)
        List_ul	*l;
{
        free (l->data);
        free (l);
}

int
listul_cmp (l0, l1)
        List_ul	*l0;
        List_ul	*l1;
{
        size_t  sz;

        td_assert ((sz = l0->size) == l1->size);
        while (sz-- > 0)
                if (l0->data[sz] != l1->data[sz])
                        return (0);

        return (1);
}

int
listul_ncmp (l0, l1, count)
        List_ul	*l0;
        List_ul	*l1;
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
listul_print (l)
        List_ul	*l;
{
        size_t  sz;

        sz = 0;
        printf ("[ ");
        while (sz < l->size) {
                printf (((sz == l->size - 1) ? "%lu " : "%lu, "),
                        listul_get (l, sz));
                sz++;
        }
        printf ("]\n");
}
