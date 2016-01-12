/*
 * dbllist.c
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
        List_d	*l;
        int     dt;
{
        td_assert (dt > 0);
        if (l->size + dt <= l->capacity)
                return ;
        l->capacity = l->size + dt;
	if ((l->data = realloc (l->data, l->capacity * sizeof (double))) == NULL) {
		fprintf(stderr, "%s:%d: Malloc failed -~- cannot grow current "
			"List_d", __FILE__, __LINE__);
                exit (EXIT_FAILURE);
        }
}

List_d *
listd_new (void)
{
        List_d	*l;

        l = calloc (1, sizeof (List_d));
        l->capacity = TD_DBLLIST_DEFAULT_SIZE;
        l->size = 0;
        if ((l->data = malloc ((l->capacity + 1) * sizeof (double))) == NULL) {
                fprintf (stderr, "%s:%d: Malloc failed -~- can't allocate memory"
			" for new List_d\n", __FILE__, __LINE__);
                exit (EXIT_FAILURE);
        }

        return (l);
}

List_d *
listd_init (sz, items)
        size_t  sz;
        double	*items;
{
        List_d	*l;
        int     i;

        l = calloc (1, sizeof (List_d));
        l->capacity = sz;
        l->size = 0;
	if ((l->data = malloc (l->capacity * sizeof (double))) == NULL) {
		fprintf(stderr, "%s:%d: Malloc failed -~- can't allocate memory"
			" for new List_d\n", __FILE__, __LINE__);
                exit (EXIT_FAILURE);
        }
        i = sz;
        while (i-- > 0)
                listd_push (l, items[sz - i - 1]);

        return (l);
}

List_d *
listd_cpy (l)
        List_d	*l;
{
        return (listd_init (l->size, l->data));
}

List_d *
listd_flip (l)
        List_d	*l;
{
        List_d	*r;
        size_t  sz;

        r = listd_new ();
        sz = l->size;
        r->size = sz;
        r->capacity = sz;
        while (sz-- > 0)
                listd_push (r, listd_get (l, sz));

        return (r);
}

size_t
listd_len (l)
        List_d	*l;
{
        return l->size;
}

size_t
listd_cap (l)
        List_d	*l;
{
        return l->capacity;
}

void
listd_push (l, el)
        List_d	*l;
        double	el;
{
        if (l->size == l->capacity)
                grow (l, 1);
        l->data[l->size++] = el;
}

double
listd_pop (l)
        List_d	*l;
{
        td_assert (l->size != 0);

        return (l->data[--l->size]);
}

double
listd_get (l, at)
        List_d	*l;
        size_t  at;
{
        td_assert (at < l->size);

        return (l->data[at]);
}

void
listd_set (l, at, el)
        List_d	*l;
        size_t  at;
        double	el;
{
        td_assert (at < l->size);

        l->data[at] = el;
}

double
listd_front (l)
        List_d	*l;
{
        td_assert (l->size > 0);

        return (l->data[0]);
}

double
listd_tail (l)
        List_d	*l;
{
        td_assert (l->size > 0);

        return (l->data[l->size - 1]);
}

void
listd_remove (l, at)
        List_d	*l;
        size_t  at;
{
        size_t  ofs;
        double    *d;

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
listd_append (l0, l1)
        List_d	*l0;
        List_d	*l1;
{
        size_t  sz;

        sz = l1->size;
        if (sz == 0)
                return ;
        if (l0->size + sz > l0->capacity)
                grow (l0, l0->capacity - sz);
        while (sz-- > 0)
                listd_push (l0, listd_get (l1, l1->size - sz));
}

void
listd_del (l)
        List_d	*l;
{
        free (l->data);
        free (l);
}

int
listd_cmp (l0, l1)
        List_d	*l0;
        List_d	*l1;
{
        size_t  sz;

        td_assert ((sz = l0->size) == l1->size);
        while (sz-- > 0)
                if (l0->data[sz] != l1->data[sz])
                        return (0);

        return (1);
}

int
listd_ncmp (l0, l1, count)
        List_d	*l0;
        List_d	*l1;
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
listd_print (l)
        List_d	*l;
{
        size_t  sz;

        sz = 0;
        printf ("[ ");
        while (sz < l->size) {
                printf (((sz == l->size - 1) ? "%f " : "%f, "),
                        listd_get (l, sz));
                sz++;
        }
        printf ("]\n");
}
