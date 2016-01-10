/*
 * td_strlen.c
 *
 * This file is part of the libtd project and provided under the MIT License.
 * You can refer to the LICENSE file at repository's root for complete license
 * terms.
 *
 *  Created on: 9 janv. 2016
 *      Author: theophile
 */

#include <td/string.h>

size_t
td_strlen (s)
	const char	*s;
{
	size_t	len;

	len = 0;
	while (*s++)
		len++;

	return (len);
}
