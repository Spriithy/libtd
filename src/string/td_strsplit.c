/*
 * td_strsplit.c
 *
 * This file is part of the libtd project and provided under the MIT License.
 * You can refer to the LICENSE file at repository's root for complete license
 * terms.
 *
 *  Created on: 13 Jan 2016
 *      Author: Theophile
 */

#include <libtd.h>

List_s *
td_strsplit (str)
	const char	*str;
{
	return (td_strcsplit(str, ' '));
}
