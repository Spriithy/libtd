/*
 * intlist.c
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
        List_i	*l;
        int     dt;
{
        td_assert (dt > 0);
        if (l->size + dt <= l->capacity)
                return ;
        l->capacity = l->size + dt;
	if ((l->data = realloc (l->data, l->capacity * sizeof (int))) == NULL) {
		fprintf(stderr, "%s:%d: Malloc failed -~- cannot grow current"
			" List_i\n", __FILE__, __LINE__);
                exit (EXIT_FAILURE);
        }
}

List_i *
listi_new (void)
{
        List_i	*l;

        l = calloc (1, sizeof (List_i));
        l->capacity = TD_INTLIST_DEFAULT_SIZE;
        l->size = 0;
	if ((l->data = malloc ((l->capacity + 1) * sizeof (int))) == NULL) {
		fprintf(stderr, "%s:%d: Malloc failed -~- cannot create new"
			" List_i\n", __FILE__, __LINE__);
                exit (EXIT_FAILURE);
        }

        return (l);
}

List_i *
listi_init (sz, items)
        size_t  sz;
        int     *items;
{
        List_i	*l;
        int     i;

        l = calloc (1, sizeof (List_i));
        l->capacity = sz;
        l->size = 0;
	if ((l->data = malloc (l->capacity * sizeof (int))) == NULL) {
		fprintf(stderr, "%s:%d: Malloc failed -~- cannot initialize new"
			" List_i\n", __FILE__, __LINE__);
                exit (EXIT_FAILURE);
        }
        i = sz;
        while (i-- > 0)
                listi_push (l, items[sz - i - 1]);

        return (l);
}

List_i *
listi_cpy (l)
        List_i	*l;
{
        return (listi_init (l->size, l->data));
}

List_i *
listi_flip (l)
        List_i	*l;
{
        List_i	*r;
        size_t  sz;

        r = listi_new ();
        sz = l->size;
        r->size = sz;
        r->capacity = sz;
        while (sz-- > 0)
                listi_push (r, listi_get (l, sz));

        return (r);
}

size_t
listi_len (l)
        List_i	*l;
{
        return l->size;
}

size_t
listi_cap (l)
        List_i	*l;
{
        return l->capacity;
}

void
listi_push (l, el)
        List_i	*l;
        int     el;
{
        if (l->size == l->capacity)
                grow (l, 1);
        l->data[l->size++] = el;
}

int
listi_pop (l)
        List_i	*l;
{
        td_assert (l->size != 0);

        return (l->data[--l->size]);
}

int
listi_get (l, at)
        List_i	*l;
        size_t  at;
{
        td_assert (at < l->size);

        return (l->data[at]);
}

void
listi_set (l, at, el)
        List_i	*l;
        size_t  at;
        int     el;
{
        td_assert (at < l->size);

        l->data[at] = el;
}

int
listi_front (l)
        List_i	*l;
{
        td_assert (l->size > 0);

        return (l->data[0]);
}

int
listi_tail (l)
        List_i	*l;
{
        td_assert (l->size > 0);

        return (l->data[l->size - 1]);
}

void
listi_remove (l, at)
        List_i	*l;
        size_t  at;
{
        size_t  ofs;
        int     *d;

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
listi_append (l0, l1)
        List_i	*l0;
        List_i	*l1;
{
        size_t  sz;

        sz = l1->size;
        if (sz == 0)
                return ;
        if (l0->size + sz > l0->capacity)
                grow (l0, l0->capacity - sz);
        while (sz-- > 0)
                listi_push (l0, listi_get (l1, l1->size - sz));
}

void
listi_del (l)
        List_i	*l;
{
        free (l->data);
        free (l);
}

int
listi_cmp (l0, l1)
        List_i	*l0;
        List_i	*l1;
{
        size_t  sz;

        td_assert ((sz = l0->size) == l1->size);
        while (sz-- > 0)
                if (l0->data[sz] != l1->data[sz])
                        return (0);

        return (1);
}

int
listi_ncmp (l0, l1, count)
        List_i	*l0;
        List_i	*l1;
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
listi_print (l)
        List_i	*l;
{
        size_t  sz;

        sz = 0;
        printf("[ ");
        while (sz < l->size) {
                printf (((sz == l->size - 1) ? "%d " : "%d, "),
                        listi_get (l, sz));
                sz++;
        }
        printf("]\n");
}
