/*
 * td_bcmp.c
 *
 * This file is part of the libtd project and provided under the MIT License.
 * You can refer to the LICENSE file at repository's root for complete license
 * terms.
 *
 *  Created on: 9 Jan. 2016
 *      Author: theophile
 */

int
td_bcmp (s1, s2, count)
	const void	*s1;
	const void 	*s2;
	int		count;
{
	while (count-- > 0)
		if (*(unsigned char *) s1++ != *(unsigned char *) s2++)
			return (1);

	return (0);
}
