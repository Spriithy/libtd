/*
 * intList.h
 *
 * This file is part of the libtd project and provided under the MIT License.
 * You can refer to the LICENSE file at repository's root for complete license
 * terms.
 *
 *  Created on: 11 Jan. 2016
 *      Author: theophile
 */

#ifndef _TD_NLIST_H_
#define _TD_NLIST_H_

#include <libtd.h>

intList *intlist_new     (void);
intList *intlist_init    (size_t sz, int *items);
intList *intlist_cpy     (intList *l);
intList *intlist_flip    (intList *l);
size_t   intlist_len     (intList *l);
size_t   intlist_cap     (intList *l);
void     intlist_push    (intList *l, int el);
int      intlist_pop     (intList *l);
int      intlist_get     (intList *l, size_t at);
void     intlist_set     (intList *l, size_t at, int el);
int      intlist_front   (intList *l);
int      intlist_tail    (intList *l);
void     intlist_remove  (intList *l, size_t at);
void     intlist_append  (intList *dst, intList *src);
void     intlist_del     (intList *l);
int      intlist_cmp     (intList *l0, intList *l1);
int      intlist_ncmp    (intList *l0, intList *l1, size_t count);

void     intlist_print   (intList *l);

#endif  /* _TD_NLIST_H_ */
