/*
 * td_isdigit.h
 * This file is part of the libtd project and provided under the MIT License.
 * You can refer to the LICENSE file at repository's root for complete license
 * terms.
 *
 *  Created on: 10 Jan 2016
 *      Author: Theophile
 */

int
is_digit (c)
        int     c;
{
        return (c >= '0' && c <= '9');
}
