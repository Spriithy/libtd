/*
 * strList.h
 *
 * This file is part of the libtd project and provided under the MIT License.
 * You can refer to the LICENSE file at repository's root for complete license
 * terms.
 *
 *  Created on: 11 janv. 2016
 *      Author: theophile
 */

#ifndef _TD_STRLIST_H_
#define _TD_STRLIST_H_

#include <td/tdef.h>
#include "list.h"

strList *strlist_new     (void);
strList *strlist_init    (size_t sz, char **items);
strList *strlist_cpy      (strList *l);
strList *strlist_flip    (strList *l);
size_t   strlist_len     (strList *l);
size_t   strlist_cap     (strList *l);
void     strlist_push    (strList *l, char *el);
char    *strlist_pop     (strList *l);
char    *strlist_get     (strList *l, size_t at);
void     strlist_set     (strList *l, size_t at, char *el);
char    *strlist_front   (strList *l);
char    *strlist_tail    (strList *l);
void     strlist_remove  (strList *l, size_t at);
void     strlist_append  (strList *dst, strList *src);
void     strlist_del     (strList *l);
int      strlist_cmp     (strList *l0, strList *l1);
int      strlist_ncmp    (strList *l0, strList *l1, size_t count);

void     strlist_print   (strList *l);

#endif  /* _TD_STRLIST_H_ */
