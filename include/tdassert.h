/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2016 Theophile Dano, Spriithy
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * tdassert.h
 * This file is part of the c_td project.
 *
 *  Created on: 8 Jan 2016
 *      Author: Theophile
 *
 * This is a naive approach of an "assert" macro.
 *
 * TODO : implement td_printf, and use it here
 *
 */

#ifndef _SRC_TDASSERT_H_
#define _SRC_TDASSERT_H_

/* TODO : please get rid of it asap */
#include <stdio.h>
#include <stdlib.h>

#undef	td_assert
#undef	__td_assert

#define td_assert(e)  \
	((void) ((e) ? 0 : __td_assert (#e, __FILE__, __LINE__)))

#define __td_assert(e, file, line) \
	((void)printf ("%s:%u: failed assertion `%s'\n", file, line, e), abort())

#endif /* _SRC_TDASSERT_H_ */
