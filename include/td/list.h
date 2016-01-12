/*
 * List.h
 *
 * This file is part of the libtd project and provided under the MIT License.
 * You can refer to the LICENSE file at repository's root for complete license
 * terms.
 *
 *  Created on: Jan 11, 2016
 *      Author: theophile
 */

#include <libtd.h>

#ifndef _TD_LIST_H_
#define _TD_LIST_H_

#define TD_INTLIST_DEFAULT_SIZE     (0)
#define TD_CHRLIST_DEFAULT_SIZE     (0)
#define TD_STRLIST_DEFAULT_SIZE     (0)
#define TD_FLTLIST_DEFAULT_SIZE     (0)
#define TD_DBLLIST_DEFAULT_SIZE     (0)
#define TD_LNGLIST_DEFAULT_SIZE     (0)
#define	 TD_ULLIST_DEFAULT_SIZE     (0)

typedef struct s_intList {
        int		*data;
        size_t		capacity;
        size_t		size;
}	List_i;

typedef struct s_strList {
        char		**data;
        size_t		capacity;
        size_t		size;
}	List_s;

typedef struct s_chrList {
	char		*data;
	size_t		capacity;
	size_t		size;
}	List_c;

typedef struct s_fltList {
	float		*data;
	size_t		capacity;
	size_t		size;
}	List_f;

typedef struct s_dblList {
	double		*data;
	size_t		capacity;
	size_t		size;
}	List_d;

typedef struct s_lngList {
	long		*data;
	size_t		capacity;
	size_t		size;
}	List_l;

typedef struct s_ulList{
	unsigned long	*data;
	size_t		capacity;
	size_t		size;
}	List_ul;

#endif  /* _TD_LIST_H_ */
