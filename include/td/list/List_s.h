/*
 * List_s.h
 *
 * This file is part of the libtd project and provided under the MIT License.
 * You can refer to the LICENSE file at repository's root for complete license
 * terms.
 *
 *  Created on: 11 Jan. 2016
 *      Author: theophile
 */

#ifndef _TD_LISTS_H_
#define _TD_LISTS_H_

#include <libtd.h>

List_s	*lists_new	(void);
List_s	*lists_init	(size_t sz, char **items);
List_s	*lists_cpy	(List_s *l);
List_s	*lists_flip	(List_s *l);
size_t   lists_len	(List_s *l);
size_t   lists_cap	(List_s *l);
void     lists_push	(List_s *l, char *el);
char    *lists_pop	(List_s *l);
char    *lists_get	(List_s *l, size_t at);
void     lists_set	(List_s *l, size_t at, char *el);
char    *lists_front	(List_s *l);
char    *lists_tail	(List_s *l);
void     lists_remove	(List_s *l, size_t at);
void     lists_append	(List_s *dst, List_s *src);
void     lists_del	(List_s *l);
int      lists_cmp	(List_s *l0, List_s *l1);
int      lists_ncmp	(List_s *l0, List_s *l1, size_t count);

void     lists_print	(List_s *l);

#endif  /* _TD_LISTS_H_ */
