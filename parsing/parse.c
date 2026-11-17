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

static int	read_arguments(int argc, char **argv, t_data *data)
{
	const char	*cursor;
	int			value;
	int			result;
	int			capacity;

	capacity = 0;
	while (argc > 0)
	{
		cursor = *argv;
		while (*cursor)
		{
			while (is_space(*cursor))
				cursor++;
			if (!*cursor)
				break ;
			result = parse_number(&cursor, &value);
			if (result != 1 || !append_value(data, value, &capacity))
				return (0);
		}
		argv++;
		argc--;
	}
	return (data->a.size > 0);
}

static int	string_equal(char *left, char *right)
{
	int	i;

	i = 0;
	while (left[i] && right[i] && left[i] == right[i])
		i++;
	return (left[i] == right[i]);
}

static int	read_strategy(char **argv, int *start, t_strategy *strategy)
{
	*start = 1;
	*strategy = ADAPTIVE;
	if (!argv[1] || argv[1][0] != '-' || argv[1][1] != '-')
		return (1);
	if (string_equal(argv[1], "--simple"))
		*strategy = SIMPLE;
	else if (string_equal(argv[1], "--medium"))
		*strategy = MEDIUM;
	else if (string_equal(argv[1], "--complex"))
		*strategy = COMPLEX;
	else if (string_equal(argv[1], "--adaptive"))
		*strategy = ADAPTIVE;
	else
		return (0);
	*start = 2;
	return (1);
}

int	parse_args(int argc, char **argv, t_data *data)
{
	int			start;
	t_strategy	strategy;

	if (argc < 2 || !read_strategy(argv, &start, &strategy))
		return (0);
	data->strategy = strategy;
	if (!read_arguments(argc - start, argv + start, data))
		return (0);
	if (is_duplicate(data->a.values, data->a.size))
		return (0);
	return (init_stacks(data, data->a.size));
}
