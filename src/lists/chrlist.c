/*
 * chrlist.c
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
        chrList *l;
        int     dt;
{
        td_assert (dt > 0);
        if (l->size + dt <= l->capacity)
                return ;
        l->capacity = l->size + dt;
	if ((l->data = realloc(l->data, l->capacity * sizeof(char))) == NULL) {
		fprintf(stderr, "%s:%d: Malloc failed -~- cannot grow current "
			"chrList", __FILE__, __LINE__);
                exit (EXIT_FAILURE);
        }
}

chrList *
chrlist_new (void)
{
        chrList *l;

        l = calloc (1, sizeof (chrList));
        l->capacity = TD_CHRLIST_DEFAULT_SIZE;
        l->size = 0;
        if ((l->data = malloc ((l->capacity + 1) * sizeof (char))) == NULL) {
                fprintf (stderr, "%s:%d: Malloc failed -~- can't allocate memory"
			" for new chrList\n", __FILE__, __LINE__);
                exit (EXIT_FAILURE);
        }

        return (l);
}

chrList *
chrlist_init (sz, items)
        size_t  sz;
        int     *items;
{
        chrList *l;
        int     i;

        l = calloc (1, sizeof (chrList));
        l->capacity = sz;
        l->size = 0;
	if ((l->data = malloc(l->capacity * sizeof(char))) == NULL) {
		fprintf(stderr, "%s:%d: Malloc failed -~- can't allocate memory"
			" for new chrList\n", __FILE__, __LINE__);
                exit (EXIT_FAILURE);
        }
        i = sz;
        while (i-- > 0)
                chrlist_push (l, items[sz - i - 1]);

        return (l);
}

chrList *
chrlist_cpy (l)
        chrList *l;
{
        return (chrlist_init (l->size, (int *) l->data));
}

chrList *
chrlist_flip (l)
        chrList *l;
{
        chrList *r;
        size_t  sz;

        r = chrlist_new ();
        sz = l->size;
        r->size = sz;
        r->capacity = sz;
        while (sz-- > 0)
                chrlist_push (r, chrlist_get (l, sz));

        return (r);
}

size_t
chrlist_len (l)
        chrList *l;
{
        return l->size;
}

size_t
chrlist_cap (l)
        chrList *l;
{
        return l->capacity;
}

void
chrlist_push (l, el)
        chrList *l;
        int     el;
{
        if (l->size == l->capacity)
                grow (l, 1);
        l->data[l->size++] = (char) el;
}

char
chrlist_pop (l)
        chrList *l;
{
        td_assert (l->size != 0);

        return (l->data[--l->size]);
}

char
chrlist_get (l, at)
        chrList *l;
        size_t  at;
{
        td_assert (at < l->size);

        return (l->data[at]);
}

void
chrlist_set (l, at, el)
        chrList *l;
        size_t  at;
        int     el;
{
        td_assert (at < l->size);

        l->data[at] = (char) el;
}

char
chrlist_front (l)
        chrList *l;
{
        td_assert (l->size > 0);

        return (l->data[0]);
}

char
chrlist_tail (l)
        chrList *l;
{
        td_assert (l->size > 0);

        return (l->data[l->size - 1]);
}

void
chrlist_remove (l, at)
        chrList *l;
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
chrlist_append (l0, l1)
        chrList *l0;
        chrList *l1;
{
        size_t  sz;

        sz = l1->size;
        if (sz == 0)
                return ;
        if (l0->size + sz > l0->capacity)
                grow (l0, l0->capacity - sz);
        while (sz-- > 0)
                chrlist_push (l0, chrlist_get (l1, l1->size - sz));
}

void
chrlist_del (l)
        chrList *l;
{
        free (l->data);
        free (l);
}

int
chrlist_cmp (l0, l1)
        chrList *l0;
        chrList *l1;
{
        size_t  sz;

        td_assert ((sz = l0->size) == l1->size);
        while (sz-- > 0)
                if (l0->data[sz] != l1->data[sz])
                        return (0);

        return (1);
}

int
chrlist_ncmp (l0, l1, count)
        chrList *l0;
        chrList *l1;
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
chrlist_print (l)
        chrList *l;
{
        size_t  sz;

        sz = 0;
        printf ("[ ");
        while (sz < l->size) {
                printf (((sz == l->size - 1) ? "\'%c\' " : "\'%c\', "),
                        chrlist_get (l, sz));
                sz++;
        }
        printf ("]\n");
}
