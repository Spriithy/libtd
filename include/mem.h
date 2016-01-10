/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2016 Theophile Dano, Spriithy
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * tdstrings.h
 * This file is part of the td_libc project.
 *
 *  Created on: 9 janv. 2016
 *      Author: theophile
 */

#ifndef _TD_MEM_H_
#define _TD_MEM_H_

#ifndef TD_NULL
# define TD_NULL (void *) 0
#endif

#ifndef _SIZE_T_DEFINED
typedef unsigned long	size_t;
# define _SIZE_T_DEFINED
# define _SIZE_T
#endif /* _SIZE_T_DEFINED */

void	td_bzero	(void *ptr, size_t count);
void	td_bcopy	(const void *src, void *dst, size_t n);
int     td_bcmp 	(const void *s1, const void *s2, size_t n);

#endif /* _TD_MEM_H_ */
