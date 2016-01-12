/*
 * Dict.h
 *
 * This file is part of the libtd project and provided under the MIT License.
 * You can refer to the LICENSE file at repository's root for complete license
 * terms.
 *
 *  Created on: 12 Jan 2016
 *      Author: Theophile
 */

#include <libtd.h>

#ifndef _TD_DICT_H_
#define _TD_DICT_H_

#define DICT_BASE_SIZE		(1 << 5)	/* Chunk of size 32 */
#define DICT_KEY_NOT_FOUND	(0)	/* Value returned when key not found */
#define DICT_KEY_FOUND		(1)
#define DICT_KEY_NOT_STORED	(-DICT_KEY_FOUND) 
#define DICT_EQUAL		(1)

#define __DJB2_HASH	(5381)

// const hash_t	td_map_hash	(const char *key);
// const int	td_map_heq	(const hash_t h0, const hash_t h1);

typedef struct s_dicti {
	size_t		capacity;
	size_t		size;
	char		**keys;
	int		*values;
}	Dict_i;

typedef struct s_dictc {
	size_t		capacity;
	size_t		size;
	char		**keys;
	char		*values;
}	Dict_c;

typedef struct s_dicts {
	size_t		capacity;
	size_t		size;
	char		**keys;
	char		**values;
}	Dict_s;

typedef struct s_dictf {
	size_t		capacity;
	size_t		size;
	char		**keys;
	float		*values;
}	Dict_f;

typedef struct s_dictd {
	size_t		capacity;
	size_t		size;
	char		**keys;
	double		*values;
}	Dict_d;

typedef struct s_dictl {
	size_t		capacity;
	size_t		size;
	char		**keys;
	long		*values;
}	Dict_l;

typedef struct s_dictul {
	size_t		capacity;
	size_t		size;
	char		**keys;
	unsigned long	*values;
}	Dict_ul;

#endif /* _TD_DICT_H_ */