/*
 * td_strndup.c
 *
 * This file is part of the libtd project and provided under the MIT License.
 * You can refer to the LICENSE file at repository's root for complete license
 * terms.
 *
 *  Created on: 10 Jan. 2016
 *      Author: theophile
 */

#include <stdlib.h>
#include <libtd.h>

char *
td_strndup (s, len)
	const char     *s;
        size_t          len;
{
	char    *nws;
        size_t  sz;

        sz = td_strlen (s);
        if (sz > len)
                sz = len;

	if (!(nws = (char *) malloc (sz + 1)))
		return ((char *) TD_NULL);

	td_memcpy (nws, s, len);
        nws[sz] = '\0';

	return (nws);
}
