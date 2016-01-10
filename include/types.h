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
 * tdctype.h
 * This file is part of the td_libc project.
 *
 *  Created on: 9 Jan 2016
 *      Author: Theophile
 *
 * This file contains basic type functions such as isalpha or toupper. For now,
 * are only implemented character manipulation/treatment functions.
 *
 */

#ifndef _TD_TYPES_H_
#define	_TD_TYPES_H_

int	td_digittoint   (int c);
int	td_isalnum      (int c);
int	td_isalpha      (int c);
int	td_isascii      (int c);
int	td_iscntrl 	(int c);
int	td_isdigit 	(int c);
int	td_isgraph 	(int c);
int	td_ishexnumber	(int c);
int	td_isideogram	(int c);
int	td_islower 	(int c);
int	td_isnumber 	(int c);
int	td_isphonogram	(int c);
int	td_isspecial	(int c);
int	td_isprint 	(int c);
int	td_ispunct 	(int c);
int	td_isrune  	(int c);
int	td_isspace 	(int c);
int	td_isupper 	(int c);
int	td_isxdigit	(int c);
int	td_toascii 	(int c);
int	td_tolower 	(int c);
int	td_toupper 	(int c);

#endif /* _TD_TYPES_H_ */
