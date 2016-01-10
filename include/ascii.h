/*
 * ascii.h
 *
 * This file is part of the libtd project and provided under the MIT License.
 * You can refer to the LICENSE file at repository's root for complete license
 * terms.
 *
 *  Created on: 9 Jan 2016
 *      Author: Theophile
 *
 * This file contains basic type functions such as isalpha or toupper. For now,
 * are only implemented character manipulation/treatment functions.
 *
 */

#ifndef _TD_TYPES_H_
#define	_TD_TYPES_H_

int	td_digittoint   (int c);
int	td_isalnum      (int c);
int	td_isalpha      (int c);
int	td_isascii      (int c);
int	td_isblank      (int c);
int	td_iscntrl 	(int c);
int	td_isdigit 	(int c);
int	td_isgraph 	(int c);
int	td_ishexnumber	(int c);
int	td_isideogram	(int c);
int	td_islower 	(int c);
int	td_isnumber 	(int c);
int	td_isphonogram	(int c);
int	td_isspecial	(int c);
int	td_isprint 	(int c);
int	td_ispunct 	(int c);
int	td_isrune  	(int c);
int	td_isspace 	(int c);
int	td_isupper 	(int c);
int	td_isxdigit	(int c);
int	td_toascii 	(int c);
int	td_tolower 	(int c);
int	td_toupper 	(int c);

#endif /* _TD_TYPES_H_ */
