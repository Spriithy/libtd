/*
 * List_ul.h
 *
 * This file is part of the libtd project and provided under the MIT License.
 * You can refer to the LICENSE file at repository's root for complete license
 * terms.
 *
 *  Created on: 12 Jan. 2016
 *      Author: theophile
 */

#ifndef _TD_LISTUL_H_
#define _TD_LISTUL_H_

#include <libtd.h>

List_ul		*listul_new	(void);
List_ul		*listul_init	(size_t sz, unsigned long *items);
List_ul		*listul_cpy	(List_ul *l);
List_ul		*listul_flip	(List_ul *l);
size_t		 listul_len	(List_ul *l);
size_t		 listul_cap	(List_ul *l);
void		 listul_push	(List_ul *l, unsigned long el);
unsigned long	 listul_pop	(List_ul *l);
unsigned long	 listul_get	(List_ul *l, size_t at);
void		 listul_set	(List_ul *l, size_t at, unsigned long el);
unsigned long	 listul_front	(List_ul *l);
unsigned long	 listul_tail	(List_ul *l);
void		 listul_remove	(List_ul *l, size_t at);
void		 listul_append	(List_ul *dst, List_ul *src);
void		 listul_del	(List_ul *l);
int		 listul_cmp	(List_ul *l0, List_ul *l1);
int		 listul_ncmp	(List_ul *l0, List_ul *l1, size_t count);

void		 listul_print	(List_ul *l);

#endif  /* _TD_LISTUL_H_ */
