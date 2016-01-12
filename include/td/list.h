/*
 * list.h
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

#define TD_INTLIST_DEFAULT_SIZE     0
#define TD_CHRLIST_DEFAULT_SIZE     0
#define TD_STRLIST_DEFAULT_SIZE     0

typedef struct intList {
        int     *data;
        size_t  capacity;
        size_t  size;
} intList;

typedef struct strList {
        char    **data;
        size_t  capacity;
        size_t  size;
} strList;

typedef struct chrList {
        char    *data;
        size_t  capacity;
        size_t  size;
} chrList;

#endif  /* _TD_LIST_H_ */
