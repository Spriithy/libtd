/*
 * tdef.h
 *
 * This file is part of the libtd project and provided under the MIT License.
 * You can refer to the LICENSE file at repository's root for complete license
 * terms.
 *
 *  Created on: Jan 10, 2016
 *      Author: theophile
 */

#ifndef _TD_DEF_H_
#define _TD_DEF_H_

#undef  TD_NULL
#define	TD_NULL ((void *) 0)

#if  !defined (_SIZE_T_DEFINED) && !defined (__SIZE_TYPE__)
typedef unsigned long long	size_t;
#  define _SIZE_T_DEFINED
#  define __SIZE_TYPE__
#  define _SIZE_T
#endif /* !_SIZE_T_DEFINED && !__SIZE_TYPE__ */

#ifndef _HASH_T_DEFINED
typedef unsigned long long	hash_t;
# define _HASH_T_DEFINED
# define _HASH_T
#endif /* _HASH_T_DEFINED */

#endif  /* _TD_DEF_H_ */
