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
 */

#ifndef _TD_TYPES_H_
#define	_TD_TYPES_H_

/* Returns :
 *	- an integer given the corresponding character 
 *	- on failure
 */
int	td_digittoint   (int c);

/* Returns whether the given character is an alpha-numeric character */
int	td_isalnum      (int c);

/* Returns whether the given character is a letter (upper or lower case) */
int	td_isalpha      (int c);

/* Returns whether the given character is a valid ascii char */
int	td_isascii      (int c);

/* Returns whether the given character is a space or a tab */
int	td_isblank      (int c);

/* Returns whether the given character is a control sequence ascii character */
int	td_iscntrl 	(int c);

/* Returns whether the given character is a digit */
int	td_isdigit 	(int c);

/* Returns whether the given character is a graph */
int	td_isgraph 	(int c);

/* Returns whether the given character is a valid hexadecimal number (0-9,A-F) */
int	td_ishexnumber	(int c);

/* Returns whether the given character is an ideogram */
int	td_isideogram	(int c);

/* Returns whether the given character is a lowercase letter */
int	td_islower 	(int c);

/* Returns whether the given character is a number */
int	td_isnumber 	(int c);

/* Returns whether the given character is a phonogram */
int	td_isphonogram	(int c);

/* Returns whether the given character is a special ascii character */
int	td_isspecial	(int c);

/* Returns whether the given character is a printable character */
int	td_isprint 	(int c);

/* Returns whether the given character is a punctuation mark */
int	td_ispunct 	(int c);

/* Returns whether the given character is a prune */
int	td_isrune  	(int c);

/* Returns whether the given character is a space */
int	td_isspace 	(int c);

/* Returns whether the given character is an uppercase letter */
int	td_isupper 	(int c);

/* Returns whether the given character is an hexadecimal digit */
int	td_isxdigit	(int c);

/* Returns the ascii character corresponding to the given int (or char) */
int	td_toascii 	(int c);

/* Returns :
 *	- the lowercase character of the given letter (int / char)
 *	- itself if already lowercase or non-alpha
 */
int	td_tolower 	(int c);

/* Returns :
*	- the uppercase character of the given letter (int / char)
*	- itself if already uppercase or non-alpha
*/
int	td_toupper 	(int c);

#endif /* _TD_TYPES_H_ */
