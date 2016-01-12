/*
 * List_c.h
 *
 * This file is part of the libtd project and provided under the MIT License.
 * You can refer to the LICENSE file at repository's root for complete license
 * terms.
 *
 *  Created on: 11 Jan. 2016
 *      Author: theophile
 */

#ifndef _TD_LISTC_H_
#define _TD_LISTC_H_

#include <libtd.h>

List_c	*listc_new	(void);
List_c	*listc_init	(size_t sz, int *items);
List_c	*listc_cpy	(List_c *l);
List_c	*listc_flip	(List_c *l);
size_t   listc_len	(List_c *l);
size_t   listc_cap	(List_c *l);
void     listc_push	(List_c *l, int el);
char     listc_pop	(List_c *l);
char     listc_get	(List_c *l, size_t at);
void     listc_set	(List_c *l, size_t at, int el);
char     listc_front	(List_c *l);
char     listc_tail	(List_c *l);
void     listc_remove	(List_c *l, size_t at);
void     listc_append	(List_c *dst, List_c *src);
void     listc_del	(List_c *l);
int      listc_cmp	(List_c *l0, List_c *l1);
int      listc_ncmp	(List_c *l0, List_c *l1, size_t count);

void     listc_print	(List_c *l);

#endif  /* _TD_LISTC_H_ */
