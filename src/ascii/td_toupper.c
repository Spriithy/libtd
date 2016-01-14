/*
 * td_toupper.c
 *
 * This file is part of the libtd project and provided under the MIT License.
 * You can refer to the LICENSE file at repository's root for complete license
 * terms.
 *
 *  Created on: 13 Jan 2016
 *      Author: Theophile
 */

#include <td/ascii.h>

int
td_toupper (c)
	int	c;
{
	// Difference between Uppercase and Lower case A/a is 32
	// a.k.a. the space (' ') character ...
	if ((c >= 'a' && c <= 'z'))
		// ... thus, this return statement is equivalent to
		// return (c - 32);
		return (c - ' ');
	else
		// If c is either already uppercase, or c isn't a letter
		return (c);
}
