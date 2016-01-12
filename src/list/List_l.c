/*
 * List_l.c
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
        List_l	*l;
        int     dt;
{
        td_assert (dt > 0);
        if (l->size + dt <= l->capacity)
                return ;
        l->capacity = l->size + dt;
	if ((l->data = realloc (l->data, l->capacity * sizeof (long))) == NULL) {
		fprintf(stderr, "%s:%d: Malloc failed -~- cannot grow current "
			"List_l", __FILE__, __LINE__);
                exit (EXIT_FAILURE);
        }
}

List_l *
listl_new (void)
{
        List_l	*l;

        l = calloc (1, sizeof (List_l));
        l->capacity = TD_LNGLIST_DEFAULT_SIZE;
        l->size = 0;
        if ((l->data = malloc ((l->capacity + 1) * sizeof (long))) == NULL) {
                fprintf (stderr, "%s:%d: Malloc failed -~- can't allocate memory"
			" for new List_l\n", __FILE__, __LINE__);
                exit (EXIT_FAILURE);
        }

        return (l);
}

List_l *
listl_init (sz, items)
        size_t  sz;
        long	*items;
{
        List_l	*l;
        int     i;

        l = calloc (1, sizeof (List_l));
        l->capacity = sz;
        l->size = 0;
	if ((l->data = malloc (l->capacity * sizeof (long))) == NULL) {
		fprintf(stderr, "%s:%d: Malloc failed -~- can't allocate memory"
			" for new List_l\n", __FILE__, __LINE__);
                exit (EXIT_FAILURE);
        }
        i = sz;
        while (i-- > 0)
                listl_push (l, items[sz - i - 1]);

        return (l);
}

List_l *
listl_cpy (l)
        List_l	*l;
{
        return (listl_init (l->size, l->data));
}

List_l *
listl_flip (l)
        List_l	*l;
{
        List_l	*r;
        size_t  sz;

        r = listl_new ();
        sz = l->size;
        r->size = sz;
        r->capacity = sz;
        while (sz-- > 0)
                listl_push (r, listl_get (l, sz));

        return (r);
}

size_t
listl_len (l)
        List_l	*l;
{
        return l->size;
}

size_t
listl_cap (l)
        List_l	*l;
{
        return l->capacity;
}

void
listl_push (l, el)
        List_l	*l;
        long	el;
{
        if (l->size == l->capacity)
                grow (l, 1);
        l->data[l->size++] = el;
}

long
listl_pop (l)
        List_l	*l;
{
        td_assert (l->size != 0);

        return (l->data[--l->size]);
}

long
listl_get (l, at)
        List_l	*l;
        size_t  at;
{
        td_assert (at < l->size);

        return (l->data[at]);
}

void
listl_set (l, at, el)
        List_l	*l;
        size_t  at;
        long	el;
{
        td_assert (at < l->size);

        l->data[at] = el;
}

long
listl_front (l)
        List_l	*l;
{
        td_assert (l->size > 0);

        return (l->data[0]);
}

long
listl_tail (l)
        List_l	*l;
{
        td_assert (l->size > 0);

        return (l->data[l->size - 1]);
}

void
listl_remove (l, at)
        List_l	*l;
        size_t  at;
{
        size_t  ofs;
        long    *d;

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
listl_append (l0, l1)
        List_l	*l0;
        List_l	*l1;
{
        size_t  sz;

        sz = l1->size;
        if (sz == 0)
                return ;
        if (l0->size + sz > l0->capacity)
                grow (l0, l0->capacity - sz);
        while (sz-- > 0)
                listl_push (l0, listl_get (l1, l1->size - sz));
}

void
listl_del (l)
        List_l	*l;
{
        free (l->data);
        free (l);
}

int
listl_cmp (l0, l1)
        List_l	*l0;
        List_l	*l1;
{
        size_t  sz;

        td_assert ((sz = l0->size) == l1->size);
        while (sz-- > 0)
                if (l0->data[sz] != l1->data[sz])
                        return (0);

        return (1);
}

int
listl_ncmp (l0, l1, count)
        List_l	*l0;
        List_l	*l1;
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
listl_print (l)
        List_l	*l;
{
        size_t  sz;

        sz = 0;
        printf ("[ ");
        while (sz < l->size) {
                printf (((sz == l->size - 1) ? "%l " : "%l, "),
                        listl_get (l, sz));
                sz++;
        }
        printf ("]\n");
}