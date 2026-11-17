#include "../push_swap.h"

static int	is_space(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

// Parses new int to store in array of stack A.
static int	append_value(t_data *data, int value, int *capacity)
{
	int	*new_values;
	int	new_capacity;
	int	i;

	// If stack A's size reaches its capacity
	if (data->a.size == *capacity)
	// Resize the array to double its current capacity
	{
		new_capacity = *capacity * 2;
		if (new_capacity == 0)
			new_capacity = 4;
		new_values = malloc(sizeof(int) * new_capacity);
		if (!new_values)
			return (0);
		i = 0;
		while (i < data->a.size)
		{
			new_values[i] = data->a.values[i];
			i++;
		}
		free(data->a.values);
		data->a.values = new_values;
		*capacity = new_capacity;
	}
	data->a.values[data->a.size] = value;
	data->a.size++;
	return (1);
}

static int	read_number_arg(const char *cursor, t_data *data, int *capacity)
{
	int	value;
	int	found;

	found = 0;
	while (*cursor)
	{
		while (is_space(*cursor))
			cursor++;
		if (!*cursor)
			break ;
		if (parse_number(&cursor, &value) != 1
			|| !append_value(data, value, capacity))
			return (0);
		found = 1;
	}
	// An empty or whitespace-only argument is invalid
	return (found);
}

static int	string_equal(char *left, char *right)
{
	int	i;

	i = 0;
	while (left[i] && right[i] && left[i] == right[i])
		i++;
	return (left[i] == right[i]);
}

// Reads a "--xxx" flag. Only one strategy flag is allowed, at any position.
static int	read_strategy(char *arg, t_strategy *strategy, int *flag_seen)
{
	if (*flag_seen)
		return (0);
	*flag_seen = 1;
	if (string_equal(arg, "--simple"))
		*strategy = SIMPLE;
	else if (string_equal(arg, "--medium"))
		*strategy = MEDIUM;
	else if (string_equal(arg, "--complex"))
		*strategy = COMPLEX;
	else if (string_equal(arg, "--adaptive"))
		*strategy = ADAPTIVE;
	else
		return (0);
	return (1);
}

// Returns 1 on success (data->a.size may be 0 if no numbers were given),
// 0 on error.
int	parse_args(int argc, char **argv, t_data *data)
{
	int	i;
	int	capacity;
	int	flag_seen;

	i = 1;
	capacity = 0;
	flag_seen = 0;
	data->strategy = ADAPTIVE;
	while (i < argc)
	{
		if (argv[i][0] == '-' && argv[i][1] == '-')
		{
			if (!read_strategy(argv[i], &data->strategy, &flag_seen))
				return (0);
		}
		else if (!read_number_arg(argv[i], data, &capacity))
			return (0);
		i++;
	}
	if (data->a.size == 0)
		return (1);
	if (is_duplicate(data->a.values, data->a.size))
		return (0);
	return (init_stacks(data, data->a.size));
}
