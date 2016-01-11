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
#include <td/tdef.h>
#include <td/mem.h>
#include <td/string.h>
#include <td/assert.h>
#include <td/strList.h>

static void grow (l, dt)
        strList *l;
        int     dt;
{
        td_assert (dt > 0);
        if (l->size + dt <= l->capacity)
                return ;
        l->capacity = l->size + dt;
        if ((l->data = realloc (l->data, l->capacity * sizeof (char *))) == NULL) {
                fprintf (stderr, "Malloc failed -~- \n");
                exit (EXIT_FAILURE);
        }
}

strList *
strlist_new (void)
{
        strList *l;

        l = calloc (1, sizeof (strList));
        l->capacity = TD_STRLIST_DEFAULT_SIZE;
        l->size = 0;
        if ((l->data = malloc ((l->capacity + 1) * sizeof (char *))) == NULL) {
                fprintf (stderr, "Malloc failed -~- \n");
                exit (EXIT_FAILURE);
        }

        return (l);
}

strList *
strlist_init (sz, items)
        size_t  sz;
        char    **items;
{
        strList *l;
        int     i;

        l = calloc (1, sizeof (strList));
        l->capacity = sz;
        l->size = 0;
        if ((l->data = malloc (l->capacity * sizeof (char *))) == NULL) {
                fprintf (stderr, "Malloc failed -~- \n");
                exit (EXIT_FAILURE);
        }
        i = sz;
        while (i-- > 0)
                strlist_push (l, items[sz - i - 1]);

        return (l);
}

strList *
strlist_cpy (l)
        strList *l;
{
        return (strlist_init (l->size, l->data));
}

strList *
strlist_flip (l)
        strList *l;
{
        strList *r;
        size_t  sz;

        r = strlist_new ();
        sz = l->size;
        r->size = sz;
        r->capacity = sz;
        while (sz-- > 0)
                strlist_push (r, strlist_get (l, sz));

        return (r);
}

size_t
strlist_len (l)
        strList *l;
{
        return l->size;
}

size_t
strlist_cap (l)
        strList *l;
{
        return l->capacity;
}

void
strlist_push (l, el)
        strList *l;
        char    *el;
{
        if (l->size == l->capacity)
                grow (l, 1);
        l->data[l->size++] = el;
}

char *
strlist_pop (l)
        strList *l;
{
        td_assert (l->size != 0);

        return (l->data[--l->size]);
}

char *
strlist_get (l, at)
        strList *l;
        size_t  at;
{
        td_assert (at < l->size);

        return (l->data[at]);
}

void
strlist_set (l, at, el)
        strList *l;
        size_t  at;
        char    *el;
{
        td_assert (at < l->size);

        l->data[at] = el;
}

char *
strlist_front (l)
        strList *l;
{
        td_assert (l->size > 0);

        return (l->data[0]);
}

char *
strlist_tail (l)
        strList *l;
{
        td_assert (l->size > 0);

        return (l->data[l->size - 1]);
}

void
strlist_remove (l, at)
        strList *l;
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
strlist_append (l0, l1)
        strList *l0;
        strList *l1;
{
        size_t  sz;

        sz = l1->size;
        if (sz == 0)
                return ;
        if (l0->size + sz > l0->capacity)
                grow (l0, l0->capacity - sz);
        while (sz-- > 0)
                strlist_push (l0, strlist_get (l1, l1->size - sz));
}

void
strlist_del (l)
        strList *l;
{
        free (l->data);
        free (l);
}

int
strlist_cmp (l0, l1)
        strList *l0;
        strList *l1;
{
        size_t  sz;

        td_assert ((sz = l0->size) == l1->size);
        while (sz-- > 0)
                if (l0->data[sz] != l1->data[sz])
                        return (0);

        return (1);
}

int
strlist_ncmp (l0, l1, count)
        strList *l0;
        strList *l1;
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
strlist_print (l)
        strList *l;
{
        size_t  sz;

        sz = 0;
        printf ("[ ");
        while (sz < l->size) {
                printf (((sz == l->size - 1) ? "\"%s\" " : "\"%s\", "),
                        strlist_get (l, sz));
                sz++;
        }
        printf ("]\n");
}
