/*
 * vector.h
 *
 * This file is part of the libtd project and provided under the MIT License.
 * You can refer to the LICENSE file at repository's root for complete license
 * terms.
 *
 *  Created on: 11 janv. 2016
 *      Author: theophile
 */

#ifndef _TD_VECTOR_H_
#define _TD_VECTOR_H_

#ifndef _SIZE_T_DEFINED
typedef unsigned long	size_t;
# define _SIZE_T_DEFINED
# define _SIZE_T
#endif /* _SIZE_T_DEFINED */

typedef struct Vector {
        void    **data;
        size_t  capacity;
        size_t  size;
} Vector;

Vector  *vec_new        (size_t sz);
Vector  *vec_init       (size_t sz, void** items);
Vector  *vec_cpy        (Vector *vec);
Vector  *vec_flip       (Vector *vec);
size_t   vec_len        (Vector *vec);
size_t   vec_cap        (Vector *vec);
void     vec_push       (Vector *vec, void *el);
void    *vec_pop        (Vector *vec);
void    *vec_get        (Vector *vec, size_t pos);
void     vec_set        (Vector *vec, size_t pos, void *el);
void    *vec_front      (Vector *vec);
void    *vec_tail       (Vector *vec);
void     vec_del        (Vector *vec);
void     vec_append     (Vector *dst, Vector *src);
void     vec_zero       (Vector *vec);
int      vec_cmp        (Vector *v, Vector *w);

#endif  /* _TD_VECTOR_H_ */
