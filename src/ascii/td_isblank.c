/*
 * td_isblank.h
 *
 * This file is part of the libtd project and provided under the MIT License.
 * You can refer to the LICENSE file at repository's root for complete license
 * terms.
 *
 *  Created on: 10 Jan 2016
 *      Author: Theophile
 */

int
td_isblank (c)
        int     c;
{
        return ((c == ' ') || (c == '\t'));
}
