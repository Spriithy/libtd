/*
 * td_strcsplit.c
 *
 * This file is part of the libtd project and provided under the MIT License.
 * You can refer to the LICENSE file at repository's root for complete license
 * terms.
 *
 *  Created on: 13 Jan 2016
 *      Author: Theophile
 */

#include <libtd.h>

List_s *
td_strcsplit (str, del)
	const char	*str;
	int		del;
{
	List_s		*l;
	char		*s;
	int		c, tsz;

	l = lists_new ();
	if ((s = malloc (__td_tok_size * sizeof (char))) == NULL) {
		fprintf (stderr, "%s:%d: Malloc failed -~- cannot create new"
			" token while splitting string \"%s\".\n",
			__FILE__, __LINE__, str);
		exit (EXIT_FAILURE);
	}

	tsz = 0;
	while ((c = *str++) != '\0')
		if (c != (char) del) {
			if (tsz % __td_tok_size == 0) {
				if ((s = realloc (s, (tsz + __td_tok_size) * sizeof (char))) == NULL) {
					fprintf (stderr, "%s:%d: Realloc failed -~- cannot realloc current"
						" token while splitting string \"%s\".\n",
						__FILE__, __LINE__, str);
					exit (EXIT_FAILURE);
				}
			}
			*(s + tsz++) = (char) c;
		} else {
			lists_push (l, s);
			if ((s = malloc (__td_tok_size * sizeof (char))) == NULL) {
				fprintf (stderr, "%s:%d: Malloc failed -~- cannot reset"
					" token while splitting string \"%s\".\n",
					__FILE__, __LINE__, str);
				exit (EXIT_FAILURE);
			}
			tsz = 0;
		}
	lists_push (l, s);

	return (l);
}
