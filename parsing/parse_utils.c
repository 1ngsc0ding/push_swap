#include "../push_swap.h"

static int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

static int	is_space_char(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

int	parse_number(const char **cursor, int *value)
{
	long long	number; // Using long long to handle potential overflow
	int			 sign;

	number = 0;
	sign = 1; // Default sign is positive

	while (is_space_char(**cursor))
		(*cursor)++;
	if (**cursor == '+' || **cursor == '-')
	{
		if (**cursor == '-')
			sign = -1;
		(*cursor)++;
	}
	if (!is_digit(**cursor))
		return (1); 
	while (is_digit(**cursor))
	{
		number = number * 10 + (**cursor - '0'); // Convert char to it
		if ((sign == 1 && number > INT_MAX) // Check for int_max overflow
			|| (sign == -1 && number > -(long long)INT_MIN)) // Check for int_min overflow
			return (1); 
		(*cursor)++;
	}
	if (**cursor && !is_space_char(**cursor))
		return (1);
	*value = (int)(number * sign); // Just cast it to int
	return (0);
}