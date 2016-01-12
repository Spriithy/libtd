/*
 * fltlist.c
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
        List_f	*l;
        int     dt;
{
        td_assert (dt > 0);
        if (l->size + dt <= l->capacity)
                return ;
        l->capacity = l->size + dt;
	if ((l->data = realloc (l->data, l->capacity * sizeof (float))) == NULL) {
		fprintf(stderr, "%s:%d: Malloc failed -~- cannot grow current "
			"List_f", __FILE__, __LINE__);
                exit (EXIT_FAILURE);
        }
}

List_f *
listf_new (void)
{
        List_f	*l;

        l = calloc (1, sizeof (List_f));
        l->capacity = TD_FLTLIST_DEFAULT_SIZE;
        l->size = 0;
        if ((l->data = malloc ((l->capacity + 1) * sizeof (float))) == NULL) {
                fprintf (stderr, "%s:%d: Malloc failed -~- can't allocate memory"
			" for new List_f\n", __FILE__, __LINE__);
                exit (EXIT_FAILURE);
        }

        return (l);
}

List_f *
listf_init (sz, items)
        size_t  sz;
        double	*items;
{
        List_f	*l;
        int     i;

        l = calloc (1, sizeof (List_f));
        l->capacity = sz;
        l->size = 0;
	if ((l->data = malloc (l->capacity * sizeof (float))) == NULL) {
		fprintf(stderr, "%s:%d: Malloc failed -~- can't allocate memory"
			" for new List_f\n", __FILE__, __LINE__);
                exit (EXIT_FAILURE);
        }
        i = sz;
        while (i-- > 0)
                listf_push (l, items[sz - i - 1]);

        return (l);
}

List_f *
listf_cpy (l)
        List_f	*l;
{
        return (listf_init (l->size, (double *) l->data));
}

List_f *
listf_flip (l)
        List_f	*l;
{
        List_f	*r;
        size_t  sz;

        r = listf_new ();
        sz = l->size;
        r->size = sz;
        r->capacity = sz;
        while (sz-- > 0)
                listf_push (r, listf_get (l, sz));

        return (r);
}

size_t
listf_len (l)
        List_f	*l;
{
        return l->size;
}

size_t
listf_cap (l)
        List_f	*l;
{
        return l->capacity;
}

void
listf_push (l, el)
        List_f	*l;
        double	el;
{
        if (l->size == l->capacity)
                grow (l, 1);
        l->data[l->size++] = (float) el;
}

float
listf_pop (l)
        List_f	*l;
{
        td_assert (l->size != 0);

        return (l->data[--l->size]);
}

float
listf_get (l, at)
        List_f	*l;
        size_t  at;
{
        td_assert (at < l->size);

        return (l->data[at]);
}

void
listf_set (l, at, el)
        List_f	*l;
        size_t  at;
        double	el;
{
        td_assert (at < l->size);

        l->data[at] = (float) el;
}

float
listf_front (l)
        List_f	*l;
{
        td_assert (l->size > 0);

        return (l->data[0]);
}

float
listf_tail (l)
        List_f	*l;
{
        td_assert (l->size > 0);

        return (l->data[l->size - 1]);
}

void
listf_remove (l, at)
        List_f	*l;
        size_t  at;
{
        size_t  ofs;
        float    *d;

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
listf_append (l0, l1)
        List_f	*l0;
        List_f	*l1;
{
        size_t  sz;

        sz = l1->size;
        if (sz == 0)
                return ;
        if (l0->size + sz > l0->capacity)
                grow (l0, l0->capacity - sz);
        while (sz-- > 0)
                listf_push (l0, listf_get (l1, l1->size - sz));
}

void
listf_del (l)
        List_f	*l;
{
        free (l->data);
        free (l);
}

int
listf_cmp (l0, l1)
        List_f	*l0;
        List_f	*l1;
{
        size_t  sz;

        td_assert ((sz = l0->size) == l1->size);
        while (sz-- > 0)
                if (l0->data[sz] != l1->data[sz])
                        return (0);

        return (1);
}

int
listf_ncmp (l0, l1, count)
        List_f	*l0;
        List_f	*l1;
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
listf_print (l)
        List_f	*l;
{
        size_t  sz;

        sz = 0;
        printf ("[ ");
        while (sz < l->size) {
                printf (((sz == l->size - 1) ? "%f " : "%f, "),
                        listf_get (l, sz));
                sz++;
        }
        printf ("]\n");
}
