/*
 * Dict_i.h
 *
 * This file is part of the libtd project and provided under the MIT License.
 * You can refer to the LICENSE file at repository's root for complete license
 * terms.
 *
 *  Created on: 12 Jan 2016
 *      Author: Theophile
 */

#ifndef _TD_DICTI_H_
#define _TD_DICTI_H_

#include <libtd.h>

Dict_i	*dicti_new	(void);
Dict_i	*dicti_Linit	(List_s *keys, List_i *values);
Dict_i	*dicti_Ainit	(char **keys, int *values, size_t sz);
Dict_i	*dicti_cpy	(Dict_i *m);
void	 dicti_merge	(Dict_i *dst, const Dict_i *src);
size_t	 dicti_len	(Dict_i *m);
size_t	 dicti_cap	(Dict_i *m);
size_t	 dicti_posof	(Dict_i *m, const char *key);
int	 dicti_contains	(Dict_i *m, const char *key);
void	 dicti_add	(Dict_i *m, char *key, int val);
void	 dicti_set	(Dict_i *m, const char *key, const int val);
int	 dicti_get	(Dict_i *m, const char *key);
List_s	*dicti_keys	(Dict_i *m);
List_i	*dicti_values	(Dict_i *m);
void	 dicti_remove	(Dict_i *m, const char *key);
void	 dicti_del	(Dict_i *m);

void	 dicti_print	(Dict_i *m);

#endif	/* _TD_DICTI_H_ */
