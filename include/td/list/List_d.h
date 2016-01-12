/*
 * List_d.h
 *
 * This file is part of the libtd project and provided under the MIT License.
 * You can refer to the LICENSE file at repository's root for complete license
 * terms.
 *
 *  Created on: 12 Jan. 2016
 *      Author: theophile
 */

#ifndef _TD_LISTD_H_
#define _TD_LISTD_H_

#include <libtd.h>

List_d	*listd_new	(void);
List_d	*listd_init	(size_t sz, double *items);
List_d	*listd_cpy	(List_d *l);
List_d	*listd_flip	(List_d *l);
size_t	 listd_len	(List_d *l);
size_t	 listd_cap	(List_d *l);
void	 listd_push	(List_d *l, double el);
double	 listd_pop	(List_d *l);
double	 listd_get	(List_d *l, size_t at);
void	 listd_set	(List_d *l, size_t at, double el);
double	 listd_front	(List_d *l);
double	 listd_tail	(List_d *l);
void	 listd_remove	(List_d *l, size_t at);
void	 listd_append	(List_d *dst, List_d *src);
void	 listd_del	(List_d *l);
int	 listd_cmp	(List_d *l0, List_d *l1);
int	 listd_ncmp	(List_d *l0, List_d *l1, size_t count);

void     listd_print	(List_d *l);

#endif  /* _TD_LISTD_H_ */
