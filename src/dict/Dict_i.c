/*
 * Dict_i.c
 *
 * This file is part of the libtd project and provided under the MIT License.
 * You can refer to the LICENSE file at repository's root for complete license
 * terms.
 *
 *  Created on: 12 Jan 2016
 *      Author: Theophile
 */

#include <libtd.h>

static void grow (m, dt)
	Dict_i	*m;
	int     dt;
{
	td_assert (dt > 0);

	if (m->size + dt <= m->capacity)
		return ;
	m->capacity = m->size + dt;
	if ((m->values = realloc (m->values, m->capacity * sizeof (int))) == NULL) {
		fprintf (stderr, "%s:%d: Malloc failed -~- cannot grow current"
			" Dict_i values array.\n", __FILE__, __LINE__);
		exit (EXIT_FAILURE);
	}
	if ((m->keys = realloc (m->keys, m->capacity * sizeof (char *))) == NULL) {
		fprintf (stderr, "%s:%d: Malloc failed -~- cannot grow current"
			" Dict_i keys array.\n", __FILE__, __LINE__);
		exit (EXIT_FAILURE);
	}
}

Dict_i *
dicti_new (void)
{

}

Dict_i *
dicti_init (keys, values)
	List_s	*keys;
	List_i	*values;
{

}

Dict_i *
dicti_cpy (m)
	Dict_i	*m;
{
	return (dicti_Ainit (m->keys, m->values));
}

size_t
dicti_len (m)
	Dict_i	*m;
{
	return (m->size);
}

size_t
dicti_cap (m)
	Dict_i	*m;
{
	return (m->capacity);
}

size_t
dicti_posof (m, key)
	Dict_i		*m;
	const char	*key;
{
	size_t		d;

	d = 0;
	if (!dicti_contains (m, key)) {
		fprintf (stderr, "Couldn't resolve <%s> as an existing key in "
			"the given Dict_i.\n", key);
		dicti_print (m);
		exit (EXIT_FAILURE);
	}
	while (d++ < m->size)
		if (td_streq (m->keys[d], key)) return (d);

	return (DICT_KEY_NOT_STORED);
}

int
dicti_contains (m, key)
	Dict_i		*m;
	const char	*key;
{
	size_t		d;

	d = m->size;
	while (d-- > 0)	/* Do we have 'key' in store please ? */
		if (td_streq (m->keys[d], key)) return (DICT_KEY_FOUND);

	return (DICT_KEY_NOT_FOUND);
}

void
dicti_add (m, key, val)
	Dict_i		*m;
	const char	*key;
	const int	val;
{
	if (dicti_contains (m, key)) {
		fprintf (stderr, "Key <%s> is already stored in the given map"
			".\n", key);
		dicti_print (m);
		exit (EXIT_FAILURE);
	}

	if (m->size == m->capacity)
		grow (m, 1);
	// All this seems OK
	m->keys[m->size - 1] = key;
	m->values[m->size - 1] = val;
}

void
dicti_set (m, key, val)
	Dict_i		*m;
	const char	*key;
	const int	val;
{
	if (!dicti_contains (m, key)) {
		fprintf (stderr, "Couldn't resolve <%s> as an existing key in " 
			"the given Dict_i.\n", key);
		dicti_print (m);
		exit (EXIT_FAILURE);
	}
	
}

int
dicti_get (m, key)
	Dict_i		*m;
	const char	*key;
{
	size_t		d;
	
	if (!dicti_contains (m, key)) {
		fprintf (stderr, "Couldn't resolve <%s> as an existing key in "
			"the given Dict_i.\n", key);
		dicti_print (m);
		exit (EXIT_FAILURE);
	}

}

List_s *
dicti_keys (m)
	Dict_i	*m;
{
	return (lists_init (m->size, m->keys));
}

List_i *
dicti_values (m)
	Dict_i	*m;
{
	return (listi_init (m->size, m->values));
}

void
dicti_remove (m, key)
	Dict_i		*m;
	const char	*key;
{

}

void
dicti_del (m)
	Dict_i	*m;
{
	lists_del (m->keys);
	listi_del (m->values);
	free (m);
}

void
dicti_print (m)
	Dict_i	*m;
{

}