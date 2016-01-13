/*
 * Map.c
 *
 * This file is part of the libtd project and provided under the MIT License.
 * You can refer to the LICENSE file at repository's root for complete license
 * terms.
 *
 *  Created on: 12 Jan 2016
 *      Author: Theophile
 */

#include <libtd.h>

/* Credits to Dan Bernstein for the DJB2 hash algorithm used here
 * See http://www.cse.yorku.ca/~oz/hash.html for further informations
 */
static hash_t
__djb2 (key)
	unsigned char	*key;
{
	hash_t	hash;
	int	c;

	hash = __DJB2_HASH;
	while ((c = *key++))
		hash = ((hash << 5) + hash) + c;

	return (hash);
}

hash_t
td_map_hash (key)
	const unsigned char	*key;
{
	return (__djb2 (key));
}

int
td_map_heq (h0, h1)
	const hash_t	h0;
	const hash_t	h1;
{
	return (__djb2 (h0) == __djb2 (h1));
}
