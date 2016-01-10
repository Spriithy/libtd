/*
 * tdmath.h
 *
 * This file is part of the libtd project and provided under the MIT License.
 * You can refer to the LICENSE file at repository's root for complete license
 * terms.
 *
 *  Created on: 9 janv. 2016
 *      Author: theophile
 */
#ifndef _TD_MATH_C_
#define _TD_MATH_C_

#ifndef td_max
# define td_max(x, y)   (((x) > (y)) ? (x) : (y))
#endif

#ifndef td_min
# define td_min(x, y)   (((x) < (y)) ? (x) : (y))
#endif

int	td_abs  (int i);

#endif /* _TD_MATH_C_ */
