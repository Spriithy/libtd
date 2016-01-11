/*
 * td_strdup.c
 *
 * This file is part of the libtd project and provided under the MIT License.
 * You can refer to the LICENSE file at repository's root for complete license
 * terms.
 *
 *  Created on: 9 janv. 2016
 *      Author: theophile
 */

#include <stdlib.h>
#include <td/string.h>
#include <td/tdef.h>

char *
td_strdup (s)
	const char	*s;
{
	char	*nws;
	size_t	len;

	len = td_strlen (s) + 1;
	if (!(nws = (char *) malloc (len)))
		return (TD_NULL);
	td_memcpy (nws, s, len);

	return (nws);
}
