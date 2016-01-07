/*
 * tdlib.h
 *
 *  Created on: Jan 7, 2016
 *      Author: theophile
 */

#ifndef _SRC_TDLIB_H_
#define _SRC_TDLIB_H_

/* define our custom EOL (end of line) macro */
#ifndef EOF
#define EOL -1
#endif

typedef unsigned long	size_t;

/* memory management functions */
void	*td_memset (void *ptr, int c, size_t count);
void	*td_bzero  (void *ptr, size_t count);
void   	*td_memcpy (void *dst, const void *src, size_t count);

/* TODO add other functions */


#endif /* _SRC_TDLIB_H_ */
