/*
 * List_f.h
 *
 * This file is part of the libtd project and provided under the MIT License.
 * You can refer to the LICENSE file at repository's root for complete license
 * terms.
 *
 *  Created on: 12 Jan. 2016
 *      Author: theophile
 */

#ifndef _TD_LISTF_H_
#define _TD_LISTF_H_

#include <libtd.h>

List_f	*listf_new	(void);
List_f	*listf_init	(size_t sz, double *items);
List_f	*listf_cpy	(List_f *l);
List_f	*listf_flip	(List_f *l);
size_t	 listf_len	(List_f *l);
size_t	 listf_cap	(List_f *l);
void	 listf_push	(List_f *l, double el);
float	 listf_pop	(List_f *l);
float	 listf_get	(List_f *l, size_t at);
void	 listf_set	(List_f *l, size_t at, double el);
float	 listf_front	(List_f *l);
float	 listf_tail	(List_f *l);
void	 listf_remove	(List_f *l, size_t at);
void	 listf_append	(List_f *dst, List_f *src);
void	 listf_del	(List_f *l);
int	 listf_cmp	(List_f *l0, List_f *l1);
int	 listf_ncmp	(List_f *l0, List_f *l1, size_t count);

void     listf_print	(List_f *l);

#endif  /* _TD_LISTF_H_ */
