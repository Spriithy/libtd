/*
 * mem.h
 *
 * This file is part of the libtd project and provided under the MIT License.
 * You can refer to the LICENSE file at repository's root for complete license
 * terms.
 *
 *  Created on: 9 Jan. 2016
 *      Author: theophile
 */

#ifndef _TD_MEM_H_
#define _TD_MEM_H_

void	td_bzero	(void *ptr, int count);
void	td_bcopy	(const void *src, void *dst, int count);
int     td_bcmp         (const void *s1, const void *s2, int count);

#endif /* _TD_MEM_H_ */
