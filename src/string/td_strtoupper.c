/*
 * td_strtoupper.c
 *
 * This file is part of the libtd project and provided under the MIT License.
 * You can refer to the LICENSE file at repository's root for complete license
 * terms.
 *
 *  Created on: 13 Jan 2016
 *      Author: Theophile
 */

#include <libtd.h>
#include <stdio.h>

char *
td_strtoupper (str)
	char	*str;
{
	char	*p;

	if ((p = malloc (td_strlen(str) * sizeof (char))) == NULL) {
		fprintf (stderr, "%s:%d: Malloc failed -~- cannot allocate some"
			" memory for a new string (td_strtoupper).\n",
			__FILE__, __LINE__);
		exit (EXIT_FAILURE);
	}
	while ((*p++ = td_toupper((int) *str++)) != '\0')	// Why's that
		printf("%c\n", td_toupper(*(p - 1)));		// Buggy ?

	printf("<%s>\n", p);

	return (p);
}
