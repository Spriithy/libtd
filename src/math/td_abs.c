/*
 * td_abs.c
 *
 * This file is part of the libtd project and provided under the MIT License.
 * You can refer to the LICENSE file at repository's root for complete license
 * terms.
 *
 *  Created on: 9 janv. 2016
 *      Author: theophile
 */

int
td_abs (i)
	int i;
{
	return ((i < 0) ? -i : i);
}
