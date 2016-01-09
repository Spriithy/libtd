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
 * This file is part of the c_td project.
 *
 *  Created on: 9 Jan 2016
 *      Author: Theophile
 *
 * This file contains basic type functions such as isalpha or toupper. For now,
 * are only implemented character manipulation/treatment functions. See complete
 * documentation in the doc folder.
 *
 */

#ifndef _SRC_TDCTYPE_H_
#define	_SRC_TDCTYPE_H_

#undef 	digittoint	(c);
#undef 	isalnum 	(c);
#undef 	isalpha 	(c);
#undef 	isascii 	(c);
#undef 	iscntrl 	(c);
#undef 	isdigit 	(c);
#undef 	isgraph 	(c);
#undef 	ishexnumber	(c);
#undef 	isideogram	(c);
#undef 	islower 	(c);
#undef 	isnumber 	(c);
#undef 	isphonogram	(c);
#undef 	isspecial	(c);
#undef 	isprint 	(c);
#undef 	ispunct 	(c);
#undef 	isrune  	(c);
#undef 	isspace 	(c);
#undef 	isupper 	(c);
#undef 	isxdigit	(c);
#undef 	toascii 	(c);
#undef 	tolower 	(c);
#undef	toupper 	(c);

int	digittoint	(int c);
int	isalnum 	(int c);
int	isalpha 	(int c);
int	isascii 	(int c);
int	iscntrl 	(int c);
int	isdigit 	(int c);
int	isgraph 	(int c);
int	ishexnumber	(int c);
int	isideogram	(int c);
int	islower 	(int c);
int	isnumber 	(int c);
int	isphonogram	(int c);
int	isspecial	(int c);
int	isprint 	(int c);
int	ispunct 	(int c);
int	isrune  	(int c);
int	isspace 	(int c);
int	isupper 	(int c);
int	isxdigit	(int c);
int	toascii 	(int c);
int	tolower 	(int c);
int	toupper 	(int c);

#endif /* _SRC_TDCTYPE_H_ */
