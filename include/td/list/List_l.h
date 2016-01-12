/*
 * List_l.h
 *
 * This file is part of the libtd project and provided under the MIT License.
 * You can refer to the LICENSE file at repository's root for complete license
 * terms.
 *
 *  Created on: 12 Jan. 2016
 *      Author: theophile
 */

#ifndef _TD_LISTL_H_
#define _TD_LISTL_H_

#include <libtd.h>

List_l	*listl_new	(void);
List_l	*listl_init	(size_t sz, long *items);
List_l	*listl_cpy	(List_l *l);
List_l	*listl_flip	(List_l *l);
size_t	 listl_len	(List_l *l);
size_t	 listl_cap	(List_l *l);
void	 listl_push	(List_l *l, long el);
long	 listl_pop	(List_l *l);
long	 listl_get	(List_l *l, size_t at);
void	 listl_set	(List_l *l, size_t at, long el);
long	 listl_front	(List_l *l);
long	 listl_tail	(List_l *l);
void	 listl_remove	(List_l *l, size_t at);
void	 listl_append	(List_l *dst, List_l *src);
void	 listl_del	(List_l *l);
int	 listl_cmp	(List_l *l0, List_l *l1);
int	 listl_ncmp	(List_l *l0, List_l *l1, size_t count);

void     listl_print	(List_l *l);

#endif  /* _TD_LISTL_H_ */
