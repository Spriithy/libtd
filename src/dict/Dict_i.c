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
	Dict_i	*m;

	m = calloc (1, sizeof (Dict_i));
	m->capacity = DICT_BASE_SIZE;
	m->size = 0;
	if ((m->keys = malloc ((m->capacity + 1) * sizeof (char *))) == NULL) {
		fprintf (stderr, "%s:%d: Malloc failed -~- cannot create new"
			" Dict_i inner keys array\n", __FILE__, __LINE__);
		exit (EXIT_FAILURE);
	}
	if ((m->values = malloc ((m->capacity + 1) * sizeof (int))) == NULL) {
		fprintf (stderr, "%s:%d: Malloc failed -~- cannot create new"
			" Dict_i inner values array\n", __FILE__, __LINE__);
		exit (EXIT_FAILURE);
	}

	return (m);
}

Dict_i *
dicti_Linit (keys, values)
	List_s	*keys;
	List_i	*values;
{
	Dict_i	*m;
	size_t	sz;
	int	i;

	td_assert (keys->size == values->size);

	sz = keys->size;
	m = calloc (1, sizeof (Dict_i));
	m->capacity = sz;
	m->size = 0;
	if ((m->keys = malloc ((m->capacity + 1) * sizeof (char *))) == NULL) {
		fprintf (stderr, "%s:%d: Malloc failed -~- cannot create new"
			" Dict_i inner keys array\n", __FILE__, __LINE__);
		exit (EXIT_FAILURE);
	}
	if ((m->values = malloc ((m->capacity + 1) * sizeof (int))) == NULL) {
		fprintf (stderr, "%s:%d: Malloc failed -~- cannot create new"
			" Dict_i inner values array\n", __FILE__, __LINE__);
		exit (EXIT_FAILURE);
	}
	i = sz;
	while (i-- > 0)
		dicti_add (m, keys->data[sz - i - 1], values->data[sz - i - 1]);

	return (m);
}

Dict_i *
dicti_Ainit (keys, values, sz)
	char	**keys;
	int	*values;
	size_t	sz;
{
	Dict_i	*m;
	int	i;

	m = calloc (1, sizeof (Dict_i));
	m->capacity = sz;
	m->size = 0;
	if ((m->keys = malloc ((m->capacity + 1) * sizeof (char *))) == NULL) {
		fprintf (stderr, "%s:%d: Malloc failed -~- cannot create new"
			" Dict_i inner keys array\n", __FILE__, __LINE__);
		exit (EXIT_FAILURE);
	}
	if ((m->values = malloc ((m->capacity + 1) * sizeof (int))) == NULL) {
		fprintf (stderr, "%s:%d: Malloc failed -~- cannot create new"
			" Dict_i inner values array\n", __FILE__, __LINE__);
		exit (EXIT_FAILURE);
	}
	i = sz;
	while (i-- > 0)
		dicti_add (m, keys[sz - i - 1], values[sz - i - 1]);

	return (m);
}

Dict_i *
dicti_cpy (m)
	Dict_i	*m;
{
	return (dicti_Ainit (m->keys, m->values, m->size));
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
		fprintf (stderr, "Couldn't resolve \"%s\" as an existing key in "
			"the given Dict_i.\n", key);
		dicti_print (m);
		exit (EXIT_FAILURE);
	}
	while (d++ < m->size)
		if (td_streq (m->keys[d], key)) return (d);

	// We should never see this happen
	return (DICT_KEY_NOT_STORED);
}

int
dicti_contains (m, key)
	Dict_i		*m;
	const char	*key;
{
	size_t		d;

	d = m->size;
	while (d-- > 0) // Do we have 'key' in store please ?
		if (td_streq (m->keys[d], key)) return (DICT_KEY_FOUND);

	return (DICT_KEY_NOT_FOUND);
}

void
dicti_add (m, key, val)
	Dict_i	*m;
	char	*key;
	int	val;
{
	if (dicti_contains (m, key)) {
		fprintf (stderr, "Key \"%s\" is already stored in the given map"
			".\n", key);
		dicti_print (m);
		exit (EXIT_FAILURE);
	}

	if (m->size == m->capacity)
		grow (m, 1);
	// All this seems OK
	m->keys[m->size] = key;
	m->values[m->size] = val;
	m->size++;
}

void
dicti_set (m, key, val)
	Dict_i		*m;
	const char	*key;
	const int	val;
{
	size_t		d;

	d = 0;
	if (!dicti_contains (m, key)) {
		fprintf (stderr, "Couldn't resolve \"%s\" as an existing key in "
			"the given Dict_i.\n", key);
		dicti_print (m);
		exit (EXIT_FAILURE);
	}
	while (d++ < m->size)	// A classic loop-through
		if (td_streq (key, m->keys[d])) {
			m->values[d] = val;
			return ;
		}
}

int
dicti_get (m, key)
	Dict_i		*m;
	const char	*key;
{
	size_t		d;

	d = 0;
	if (!dicti_contains (m, key)) {
		fprintf (stderr, "Couldn't resolve \"%s\" as an existing key in "
			"the given Dict_i.\n", key);
		dicti_print (m);
		exit (EXIT_FAILURE);
	}
	while (d++ < m->size)
		if (td_streq (key, m->keys[d])) return (m->values[d]);

	// Should not happen
	return (DICT_KEY_NOT_STORED);
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
	size_t		ofs, at;
	char		**d;
	int		*v;

	td_assert (m->size > 0);
	if (!dicti_contains (m, key)) {
		fprintf (stderr, "Couldn't resolve \"%s\" as an existing key in "
			"the given Dict_i.\n", key);
		dicti_print (m);
		exit (EXIT_FAILURE);
	}

	// Same principle as Lists
	at = dicti_posof (m, key);
	d = m->keys + at;
	v = m->values + at;
	ofs = m->size - (at + 1);
	while (ofs-- > 0) {	// Just shift those after the position of
				// the key to remove (included)
		*d = *(d + 1);	d++;
		*v = *(v + 1);	v++;
	}
	m->size--;
}

void
dicti_del (m)
	Dict_i	*m;
{
	free (m->keys);
	free (m->values);
	free (m);
}

void
dicti_print (m)
	Dict_i	*m;
{
	size_t  sz;

	sz = 0;
	printf ("{ ");
	while (sz < m->size) {
		printf (((sz == m->size - 1) ? "\"%s\" : %d " : "\"%s\" : %d, "),
			m->keys[sz],
			m->values[sz]);
		sz++;
	}
	printf ("}\n");
}
