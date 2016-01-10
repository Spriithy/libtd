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
 * ascii.h
 * This file is part of the libtd project.
 *
 *  Created on: 9 Jan 2016
 *      Author: Theophile
 *
 * This file contains basic type functions such as isalpha or toupper. For now,
 * are only implemented character manipulation/treatment functions.
 *
 */

 /*
        ascii code	0	NULL	(Null character)
        ascii code	1	SOH	(Start of Header)
        ascii code	2	STX	(Start of Text)
        ascii code	3	ETX	(End of Text)
        ascii code	4	EOT	(End of Transmission)
        ascii code	5	ENQ	(Enquiry)
        ascii code	6	ACK	(Acknowledgement)
        ascii code	7	BEL	(Bell)
        ascii code	8	BS	(Backspace)
        ascii code	9	HT	(Horizontal Tab)
        ascii code	10	LF	(Line feed)
        ascii code	11	VT	(Vertical Tab)
        ascii code	12	FF	(Form feed)
        ascii code	13	CR	(Carriage return)
        ascii code	14	SO	(Shift Out)
        ascii code	15	SI	(Shift In)
        ascii code	16	DLE	(Data link escape)
        ascii code	17	DC1	(Device control 1)
        ascii code	18	DC2	(Device control 2)
        ascii code	19	DC3	(Device control 3)
        ascii code	20	DC4	(Device control 4)
        ascii code	21	NAK	(Negative acknowledgement)
        ascii code	22	SYN	(Synchronous idle)
        ascii code	23	ETB	(End of transmission block)
        ascii code	24	CAN	(Cancel)
        ascii code	25	EM	(End of medium)
        ascii code	26	SUB	(Substitute)
        ascii code	27	ESC	(Escape)
        ascii code	28	FS	(File separator)
        ascii code	29	GS	(Group separator)
        ascii code	30	RS	(Record separator)
        ascii code	31	US	(Unit separator)

        ascii code	32	 	(space)
        ascii code	33	!	(exclamation mark)
        ascii code	34	"	(Quotation mark)
        ascii code	35	#	(Number sign)
        ascii code	36	$	(Dollar sign)
        ascii code	37	%	(Percent sign)
        ascii code	38	&	(Ampersand)
        ascii code	39	'	(Apostrophe)
        ascii code	40	(	(round brackets or parentheses)
        ascii code	41	)	(round brackets or parentheses)
        ascii code	42	*	(Asterisk)
        ascii code	43	+	(Plus sign)
        ascii code	44	,	(Comma)
        ascii code	45	-	(Hyphen)
        ascii code	46	.	(Full stop , dot)
        ascii code	47	/	(Slash)
        ascii code	48	0	(number zero)
        ascii code	49	1	(number one)
        ascii code	50	2	(number two)
        ascii code	51	3	(number three)
        ascii code	52	4	(number four)
        ascii code	53	5	(number five)
        ascii code	54	6	(number six)
        ascii code	55	7	(number seven)
        ascii code	56	8	(number eight)
        ascii code	57	9	(number nine)
        ascii code	58	:	(Colon)
        ascii code	59	;	(Semicolon)
        ascii code	60	<	(Less-than sign )
        ascii code	61	=	(Equals sign)
        ascii code	62	>	(Greater-than sign ; Inequality)
        ascii code	63	?	(Question mark)
        ascii code	64	@	(At sign)
        ascii code	65	A	(Capital A )
        ascii code	66	B	(Capital B )
        ascii code	67	C	(Capital C )
        ascii code	68	D	(Capital D )
        ascii code	69	E	(Capital E )
        ascii code	70	F	(Capital F )
        ascii code	71	G	(Capital G )
        ascii code	72	H	(Capital H )
        ascii code	73	I	(Capital I )
        ascii code	74	J	(Capital J )
        ascii code	75	K	(Capital K )
        ascii code	76	L	(Capital L )
        ascii code	77	M	(Capital M )
        ascii code	78	N	(Capital N )
        ascii code	79	O	(Capital O )
        ascii code	80	P	(Capital P )
        ascii code	81	Q	(Capital Q )
        ascii code	82	R	(Capital R )
        ascii code	83	S	(Capital S )
        ascii code	84	T	(Capital T )
        ascii code	85	U	(Capital U )
        ascii code	86	V	(Capital V )
        ascii code	87	W	(Capital W )
        ascii code	88	X	(Capital X )
        ascii code	89	Y	(Capital Y )
        ascii code	90	Z	(Capital Z )
        ascii code	91	[	(square brackets or box brackets)
        ascii code	92	\	(Backslash)
        ascii code	93	]	(square brackets or box brackets)
        ascii code	94	^	(Caret or circumflex accent)
        ascii code	95	_	(underscore , understrike , underbar or low line)
        ascii code	96	`	(Grave accent)
        ascii code	97	a	(Lowercase  a )
        ascii code	98	b	(Lowercase  b )
        ascii code	99	c	(Lowercase  c )
        ascii code	100	d	(Lowercase  d )
        ascii code	101	e	(Lowercase  e )
        ascii code	102	f	(Lowercase  f )
        ascii code	103	g	(Lowercase  g )
        ascii code	104	h	(Lowercase  h )
        ascii code	105	i	(Lowercase  i )
        ascii code	106	j	(Lowercase  j )
        ascii code	107	k	(Lowercase  k )
        ascii code	108	l	(Lowercase  l )
        ascii code	109	m	(Lowercase  m )
        ascii code	110	n	(Lowercase  n )
        ascii code	111	o	(Lowercase  o )
        ascii code	112	p	(Lowercase  p )
        ascii code	113	q	(Lowercase  q )
        ascii code	114	r	(Lowercase  r )
        ascii code	115	s	(Lowercase  s )
        ascii code	116	t	(Lowercase  t )
        ascii code	117	u	(Lowercase  u )
        ascii code	118	v	(Lowercase  v )
        ascii code	119	w	(Lowercase  w )
        ascii code	120	x	(Lowercase  x )
        ascii code	121	y	(Lowercase  y )
        ascii code	122	z	(Lowercase  z )
        ascii code	123	{	(curly brackets or braces)
        ascii code	124	|	(vertical-bar, vbar, vertical line or vertical slash)
        ascii code	125	}	(curly brackets or braces)
        ascii code	126	~	(Tilde ; swung dash)
        ascii code	127	DEL	(Delete)
 */

#ifndef _TD_TYPES_H_
#define	_TD_TYPES_H_

int	td_digittoint   (int c);
int	td_isalnum      (int c);
int	td_isalpha      (int c);
int	td_isascii      (int c);
int	td_isblank      (int c);
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
