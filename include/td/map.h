/*
 * map.h
 *
 * This file is part of the libtd project and provided under the MIT License.
 * You can refer to the LICENSE file at repository's root for complete license
 * terms.
 *
 *  Created on: 12 Jan 2016
 *      Author: Theophile
 */

#include <libtd.h>

#ifndef _TD_MAP_H_
#define _TD_MAP_H_

// const hash_t	td_map_hash	(const char *key);
// const int	td_map_heq	(const hash_t h0, const hash_t h1);

typedef struct s_mapi {
	size_t		capacity;
	size_t		size;
	List_s		*keys;
	List_i		*values;
}	Map_i;

typedef struct s_mapc {
	size_t		capacity;
	size_t		size;
	List_s		*keys;
	List_c		*values;
}	Map_c;

typedef struct s_maps {
	size_t		capacity;
	size_t		size;
	List_s		*keys;
	List_s		*values;
}	Map_s;

typedef struct s_mapf {
	size_t		capacity;
	size_t		size;
	List_s		*keys;
	List_f		*values;
}	Map_f;

typedef struct s_mapd {
	size_t		capacity;
	size_t		size;
	List_s		*keys;
	List_d		*values;
}	Map_d;

typedef struct s_mapl {
	size_t		capacity;
	size_t		size;
	List_s		*keys;
	List_l		*values;
}	Map_l;

typedef struct s_mapul {
	size_t		capacity;
	size_t		size;
	List_s		*keys;
	List_d		*values;
}	Map_ul;

#endif /* _TD_MAP_H_ */