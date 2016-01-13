/*
 * libtd.h
 *
 * This file is part of the libtd project and provided under the MIT License.
 * You can refer to the LICENSE file at repository's root for complete license
 * terms.
 *
 *  Created on: Jan 12, 2016
 *      Author: theophile
 */

#ifndef _LIBTD_H_
#define _LIBTD_H_

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//	This is simply meant to include all headers from the library
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

/* Useful headers */
#include "td/tdef.h"
#include "td/ascii.h"
#include "td/assert.h"

/* Headers relative to lists */
#include "td/List.h"
#include "td/list/List_c.h"
#include "td/list/List_d.h"
#include "td/list/List_f.h"
#include "td/list/List_i.h"
#include "td/list/List_l.h"
#include "td/list/List_s.h"
#include "td/list/List_ul.h"

/* Headers relative to Dictionaries */
#include "td/Dict.h"
#include "td/dict/Dict_i.h"

/* Include math-related headers */
#include "td/math.h"

/* Strings */
#include "td/mem.h"
#include "td/string.h"

#endif /* _LIBTD_H_ */
