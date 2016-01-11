/*
 * string.h
 *
 * This file is part of the libtd project and provided under the MIT License.
 * You can refer to the LICENSE file at repository's root for complete license
 * terms.
 *
 *  Created on: Jan 7, 2016
 *      Author: theophile
 */

#ifndef _TD_STRING_H_
#define _TD_STRING_H_

#ifdef	TD_NULL
# undef	TD_NULL
#endif

#define	TD_NULL	((void *) 0)

#ifndef _SIZE_T_DEFINED
typedef unsigned long	size_t;
# define _SIZE_T_DEFINED
# define _SIZE_T
#endif /* _SIZE_T_DEFINED */

/* memory management functions */
void	*td_memset	(void *ptr, int c, size_t count);
void	*td_memcpy	(void *dst, const void *src, size_t count);
void	*td_memccpy	(void *dst, const void *src, int c, size_t count);
void	*td_memmove	(void *dst, const void *src, size_t count);
void	*td_memchr	(const void *ptr, int c, size_t count);
int 	 td_memcmp	(const void *s1, const void *s2, size_t count);

/* string related functions */
size_t	 td_strlen	(const char *s);
char	*td_strdup	(const char *s);
char	*td_strndup	(const char *s, size_t len);
char	*td_stpcpy	(char *dst, const char *src);
char	*td_stpncpy	(char *dst, const char *src, size_t len);
char	*td_strcpy	(char *dst, const char *src);
char	*td_strncpy	(char *dst, const char *src, size_t len);
char	*td_strcat	(char *s1, const char *s2);
char	*td_strncat	(char *s1, const char *s2, size_t len);
size_t	 td_strlcpy	(char *dst, const char *src, size_t len);
size_t	 td_strlcat	(char *dst, const char *src, size_t len);
char	*td_strchr	(const char *s, int c);
char	*td_strrchr	(const char *s, int c);
char	*td_strstr	(const char *big, const char *little);
char	*td_strcasestr	(const char *big, const char *little);
char	*td_strnstr	(const char *big, const char *little, size_t len);
int 	 td_strcmp	(const char *s1, const char *s2);
int 	 td_strncmp	(const char *s1, const char *s2, size_t len);

#endif /* _TD_STRING_H_ */
