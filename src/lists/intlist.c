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
#include <td/tdef.h>
#include <td/mem.h>
#include <td/assert.h>
#include <td/intList.h>

static void grow (l, dt)
        intList *l;
        int     dt;
{
        td_assert (dt > 0);
        if (l->size + dt <= l->capacity)
                return ;
        l->capacity = l->size + dt;
        if ((l->data = realloc (l->data, l->capacity * sizeof (int))) == NULL) {
                /* TODO : exception */
        }
}

intList *
intlist_new (void)
{
        intList *l;

        l = calloc (1, sizeof (intList));
        l->capacity = TD_INTLIST_DEFAULT_SIZE;
        l->size = 0;
        if ((l->data = malloc ((l->capacity + 1) * sizeof (int))) == NULL) {
                /* TODO : exception */
        }

        return (l);
}

intList *
intlist_init (sz, items)
        size_t  sz;
        int     *items;
{
        intList *l;
        int     i;

        l = calloc (1, sizeof (intList));
        l->capacity = sz;
        l->size = 0;
        if ((l->data = malloc (l->capacity * sizeof (int))) == NULL) {
                /* TODO : exception */
        }
        i = sz;
        while (i-- > 0)
                intlist_push (l, items[sz - i - 1]);

        return (l);
}

intList *
intlist_cpy (l)
        intList *l;
{
        return (intlist_init (l->size, l->data));
}

intList *
intlist_flip (l)
        intList *l;
{
        intList *r;
        size_t  sz;

        r = intlist_new ();
        sz = l->size;
        r->size = sz;
        r->capacity = sz;
        while (sz-- > 0)
                intlist_push (r, intlist_get (l, sz));

        return (r);
}

size_t
intlist_len (l)
        intList *l;
{
        return l->size;
}

size_t
intlist_cap (l)
        intList *l;
{
        return l->capacity;
}

void
intlist_push (l, el)
        intList *l;
        int     el;
{
        if (l->size == l->capacity)
                grow (l, 1);
        l->data[l->size++] = el;
}

int
intlist_pop (l)
        intList *l;
{
        td_assert (l->size != 0);

        return (l->data[--l->size]);
}

int
intlist_get (l, at)
        intList *l;
        size_t  at;
{
        td_assert (at < l->size);

        return (l->data[at]);
}

void
intlist_set (l, at, el)
        intList *l;
        size_t  at;
        int     el;
{
        td_assert (at < l->size);

        l->data[at] = el;
}

int
intlist_front (l)
        intList *l;
{
        td_assert (l->size > 0);

        return (l->data[0]);
}

int
intlist_tail (l)
        intList *l;
{
        td_assert (l->size > 0);

        return (l->data[l->size - 1]);
}

void
intlist_remove (l, at)
        intList *l;
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
intlist_append (l0, l1)
        intList *l0;
        intList *l1;
{
        size_t  sz;

        sz = l1->size;
        if (sz == 0)
                return ;
        if (l0->size + sz > l0->capacity)
                grow (l0, l0->capacity - sz);
        while (sz-- > 0)
                intlist_push (l0, intlist_get (l1, l1->size - sz));
}

void
intlist_del (l)
        intList *l;
{
        free (l->data);
        free (l);
}

int
intlist_cmp (l0, l1)
        intList *l0;
        intList *l1;
{
        size_t  sz;

        td_assert ((sz = l0->size) == l1->size);
        while (sz-- > 0)
                if (l0->data[sz] != l1->data[sz])
                        return (0);

        return (1);
}

int
intlist_ncmp (l0, l1, count)
        intList *l0;
        intList *l1;
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
intlist_print (l)
        intList *l;
{
        size_t  sz;

        sz = 0;
        printf("[ ");
        while (sz < l->size) {
                printf (((sz == l->size - 1) ? "%d " : "%d, "),
                        intlist_get (l, sz));
                sz++;
        }
        printf("]\n");
}
