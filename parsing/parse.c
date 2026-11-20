#include "../push_swap.h"

// I might be a lil ridiculous, but I ruled out 
// error = 1, success = 0 

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
	{
		new_capacity = *capacity * 2; // Resize the array to double its current capacity
		if (new_capacity == 0) 
			new_capacity = 4; // Initial capacity
		new_values = malloc(sizeof(int) * new_capacity); // Allocate new arr for new capacity
		if (!new_values) // If failed allocation
			return (1);
		i = 0;
		while (i < data->a.size) // If index of the array is exceeded
		{
			new_values[i] = data->a.values[i]; // Copy old to new each element
			i++;
		}
		free(data->a.values); // Free the old one to avoid leak
		data->a.values = new_values; // Update the new array to stack A
		*capacity = new_capacity; // Update the capacity
	}
	data->a.values[data->a.size] = value; 
	data->a.size++;
	return (0);
}

static int	read_number_arg(const char *cursor, t_data *data, int *capacity)
{
	int	value;
	int	found;

	found = 0; // Set default of found = 0

	while (*cursor)
	{
		while (is_space(*cursor))
			cursor++;
		if (!*cursor)
			break ;
		if (parse_number(&cursor, &value) == 1 // If parse fails (1 = err)
			|| append_value(data, value, capacity) == 1) // If append fails (1 = err)
			return (1);
		found = 1;
	}
	if (!found)
		return (1); // If found an empty argument or whitespace-only argument, return error
	return (0); 
}

static int	string_equal(char *left, char *right)
{
	int	i;

	i = 0;
	while (left[i] && right[i] && left[i] == right[i]) 
		i++;
	return (left[i] == right[i]);
}

static int	read_strategy(char *arg, t_strategy *strategy, int *flag_seen)
{
	if (*flag_seen)
		return (1);
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
		return (1);
	return (0);
}

// Error, return 1 and success, return 0
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
			if (read_strategy(argv[i], &data->strategy, &flag_seen) == 1) 
				return (1);
		}
		else if (read_number_arg(argv[i], data, &capacity) == 1)
			return (1);
		i++;
	}
	if (data->a.size == 0)
		return (0);
	if (is_duplicate(data->a.values, data->a.size) == 1)
		return (1);
	return (init_stacks(data, data->a.size));
}