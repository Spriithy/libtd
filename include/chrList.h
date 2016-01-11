/*
 * chrList.h
 *
 * This file is part of the libtd project and provided under the MIT License.
 * You can refer to the LICENSE file at repository's root for complete license
 * terms.
 *
 *  Created on: 11 janv. 2016
 *      Author: theophile
 */

#ifndef _TD_CHRLIST_H_
#define _TD_CHRLIST_H_

#include <td/tdef.h>
#include "list.h"

chrList *chrlist_new     (void);
chrList *chrlist_init    (size_t sz, int *items);
chrList *chrlist_cpy     (chrList *l);
chrList *chrlist_flip    (chrList *l);
size_t   chrlist_len     (chrList *l);
size_t   chrlist_cap     (chrList *l);
void     chrlist_push    (chrList *l, int el);
char     chrlist_pop     (chrList *l);
char     chrlist_get     (chrList *l, size_t at);
void     chrlist_set     (chrList *l, size_t at, int el);
char     chrlist_front   (chrList *l);
char     chrlist_tail    (chrList *l);
void     chrlist_append  (chrList *dst, chrList *src);
void     chrlist_del     (chrList *l);
int      chrlist_cmp     (chrList *l0, chrList *l1);
int      chrlist_ncmp    (chrList *l0, chrList *l1, size_t count);

void     chrlist_print   (chrList *l);

#endif  /* _TD_STRLIST_H_ */
