/*
 * List_i.h
 *
 * This file is part of the libtd project and provided under the MIT License.
 * You can refer to the LICENSE file at repository's root for complete license
 * terms.
 *
 *  Created on: 11 Jan. 2016
 *      Author: theophile
 */

#ifndef _TD_LISTI_H_
#define _TD_LISTI_H_

#include <libtd.h>

List_i	*listi_new	(void);
List_i	*listi_init	(size_t sz, int *items);
List_i	*listi_cpy	(List_i *l);
List_i	*listi_flip	(List_i *l);
size_t	 listi_len	(List_i *l);
size_t   listi_cap	(List_i *l);
void     listi_push	(List_i *l, int el);
int      listi_pop	(List_i *l);
int      listi_get	(List_i *l, size_t at);
void     listi_set	(List_i *l, size_t at, int el);
int      listi_front	(List_i *l);
int      listi_tail	(List_i *l);
void     listi_remove	(List_i *l, size_t at);
void     listi_append	(List_i *dst, List_i *src);
void     listi_del	(List_i *l);
int      listi_cmp	(List_i *l0, List_i *l1);
int      listi_ncmp	(List_i *l0, List_i *l1, size_t count);

void     listi_print	(List_i *l);

#endif  /* _TD_LISTI_H_ */
