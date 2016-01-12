/*
 * strlist.c
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
        List_s	*l;
        int     dt;
{
        td_assert (dt > 0);
        if (l->size + dt <= l->capacity)
                return ;
        l->capacity = l->size + dt;
	if ((l->data = realloc (l->data, l->capacity * sizeof (char *))) == NULL) {
		fprintf(stderr, "%s:%d: Malloc failed -~- cannot grow current"
			" List_s\n", __FILE__, __LINE__);
		exit(EXIT_FAILURE);
        }
}

List_s *
lists_new (void)
{
        List_s	*l;

        l = calloc (1, sizeof (List_s));
        l->capacity = TD_STRLIST_DEFAULT_SIZE;
        l->size = 0;
	if ((l->data = malloc ((l->capacity + 1) * sizeof (char *))) == NULL) {
		fprintf(stderr, "%s:%d: Malloc failed -~- cannot create new"
			" List_s\n", __FILE__, __LINE__);
		exit(EXIT_FAILURE);
        }

        return (l);
}

List_s *
lists_init (sz, items)
        size_t  sz;
        char    **items;
{
        List_s	*l;
        int     i;

        l = calloc (1, sizeof (List_s));
        l->capacity = sz;
        l->size = 0;
	if ((l->data = malloc (l->capacity * sizeof (char *))) == NULL) {
		fprintf(stderr, "%s:%d: Malloc failed -~- cannot initialize new"
			" List_s\n", __FILE__, __LINE__);
		exit(EXIT_FAILURE);
        }
        i = sz;
        while (i-- > 0)
                lists_push (l, items[sz - i - 1]);

        return (l);
}

List_s *
lists_cpy (l)
        List_s	*l;
{
        return (lists_init (l->size, l->data));
}

List_s *
lists_flip (l)
        List_s	*l;
{
        List_s	*r;
        size_t  sz;

        r = lists_new ();
        sz = l->size;
        r->size = sz;
        r->capacity = sz;
        while (sz-- > 0)
                lists_push (r, lists_get (l, sz));

        return (r);
}

size_t
lists_len (l)
        List_s	*l;
{
        return l->size;
}

size_t
lists_cap (l)
        List_s	*l;
{
        return l->capacity;
}

void
lists_push (l, el)
        List_s	*l;
        char    *el;
{
        if (l->size == l->capacity)
                grow (l, 1);
        l->data[l->size++] = el;
}

char *
lists_pop (l)
        List_s	*l;
{
        td_assert (l->size != 0);

        return (l->data[--l->size]);
}

char *
lists_get (l, at)
        List_s	*l;
        size_t  at;
{
        td_assert (at < l->size);

        return (l->data[at]);
}

void
lists_set (l, at, el)
        List_s	*l;
        size_t  at;
        char    *el;
{
        td_assert (at < l->size);

        l->data[at] = el;
}

char *
lists_front (l)
        List_s	*l;
{
        td_assert (l->size > 0);

        return (l->data[0]);
}

char *
lists_tail (l)
        List_s	*l;
{
        td_assert (l->size > 0);

        return (l->data[l->size - 1]);
}

void
lists_remove (l, at)
        List_s	*l;
        size_t  at;
{
        size_t  ofs;
        char    **d;

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
lists_append (l0, l1)
        List_s	*l0;
        List_s	*l1;
{
        size_t  sz;

        sz = l1->size;
        if (sz == 0)
                return ;
        if (l0->size + sz > l0->capacity)
                grow (l0, l0->capacity - sz);
        while (sz-- > 0)
                lists_push (l0, lists_get (l1, l1->size - sz));
}

void
lists_del (l)
        List_s	*l;
{
        free (l->data);
        free (l);
}

int
lists_cmp (l0, l1)
        List_s	*l0;
        List_s	*l1;
{
        size_t  sz;

        td_assert ((sz = l0->size) == l1->size);
        while (sz-- > 0)
                if (l0->data[sz] != l1->data[sz])
                        return (0);

        return (1);
}

int
lists_ncmp (l0, l1, count)
        List_s	*l0;
        List_s	*l1;
        size_t  count;
{
        td_assert (l0->size >= count);
        td_assert (l1->size >= count);

        while (count-- > 0)
                if (!td_streq (l0->data[count], l1->data[count]))
                        return (0);

        return (1);
}

void
lists_print (l)
        List_s	*l;
{
        size_t  sz;

        sz = 0;
        printf ("[ ");
        while (sz < l->size) {
                printf (((sz == l->size - 1) ? "\"%s\" " : "\"%s\", "),
                        lists_get (l, sz));
                sz++;
        }
        printf ("]\n");
}
