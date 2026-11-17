#include "../push_swap.h"

int	init_stacks(t_data *data, int capacity)
{
	data->b.values = malloc(sizeof(int) * capacity);
	if (!data->b.values)
		return (0);
	data->b.size = 0;
	return (1);
}
