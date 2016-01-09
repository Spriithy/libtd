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
 * tdlib.h
 * This file is part of the c_td project.
 *
 *  Created on: Jan 7, 2016
 *      Author: theophile
 */

#ifndef _SRC_TDLIB_H_
#define _SRC_TDLIB_H_

#define	TD_NULL	(void *) 0

#include "tdassert.h"

typedef unsigned long	size_t;

/* memory management functions */
void	*td_memset	(void *ptr, int c, size_t count);
void	*td_bzero	(void *ptr, size_t count);
void	*td_memcpy	(void *dst, const void *src, size_t count);
void	*td_memccpy	(void *dst, const void *src, int c, size_t count);
void	*td_memmove	(void *dst, const void *src, size_t count);
void	*td_memchr	(const void *ptr, int c, size_t count);
int 	td_memcmp	(const void *s1, const void *s2, size_t count);

/* string related functions */

size_t	td_strlen   	(const char *s);
size_t	td_strnlen  	(const char *s, size_t maxlen);
char	*td_strdup  	(const char *s);
char	*td_strndup 	(const char *s, size_t n);
char	*td_stpcpy  	(char *dst, const char *src);
char	*td_stpncpy 	(char *dst, const char *src, size_t len);
char	*td_strcpy  	(char *dst, const char *src);
char	*td_strncpy 	(char *dst, const char *src, size_t len);
char	*td_strcat  	(char *s1, const char *s2);
char	*td_strncat 	(char *s1, const char *s2, size_t n);
size_t	td_strlcpy  	(char *dst, const char *src, size_t size);
size_t	td_strlcat  	(char *dst, const char *src, size_t size);
char	*td_strchr  	(const char *s, int c);
char	*td_strrchr 	(const char *s, int c);
char	*td_strstr  	(const char *big, const char *little);
char	*td_strcasestr	(const char *big, const char *little);
char	*td_strnstr 	(const char *big, const char *little, size_t len);
int 	td_strcmp   	(const char *s1, const char *s2);
int 	td_strncmp  	(const char *s1, const char *s2, size_t n);

#endif /* _SRC_TDLIB_H_ */
