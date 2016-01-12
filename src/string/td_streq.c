/*
 * td_streq.c
 *
 * This file is part of the libtd project and provided under the MIT License.
 * You can refer to the LICENSE file at repository's root for complete license
 * terms.
 *
 *  Created on: 11 Jan. 2016
 *      Author: theophile
 */

int
td_streq (s1, s2)
        const char      *s1;
        const char      *s2;
{
        const char     *l;
        const char     *t;

        l = s1; t = s2;
        while ((*l++ != '\0') && (*t++ != '\0'))
                if (*l != *t) return (0);

        return (1);
}
