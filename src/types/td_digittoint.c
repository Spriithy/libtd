/*
 * td_digittoint.h
 *
 * This file is part of the libtd project and provided under the MIT License.
 * You can refer to the LICENSE file at repository's root for complete license
 * terms.
 *
 *  Created on: 10 Jan 2016
 *      Author: Theophile
 */

 #include <td/ascii.h>

 int
 td_digittoint (c)
        int     c;
{
        if (td_isdigit (c)) return (c - '0');

        return (-1);
}
