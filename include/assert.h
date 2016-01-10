/*
 * tdassert.h
 *
 * This file is part of the libtd project and provided under the MIT License.
 * You can refer to the LICENSE file at repository's root for complete license
 * terms.
 *
 *
 *  Created on: 8 Jan 2016
 *      Author: Theophile
 *
 * This is a naive approach of an "assert" macro.
 */

#ifndef _TD_ASSERT_H_
#define _TD_ASSERT_H_

/* TODO : please get rid of it asap */
#include <stdio.h>
#include <stdlib.h>

#ifdef	td_assert
# undef	td_assert
# undef	__td_assert
#else
# define td_assert(e)  \
	((void) ((e) ? 0 : __td_assert (#e, __FILE__, __LINE__)))

# define __td_assert(e, file, line) \
	((void)printf ("%s:%u: failed assertion `%s'\n", file, line, e), abort())
#endif /* td_assert */

#endif /* _TD_ASSERT_H_ */
