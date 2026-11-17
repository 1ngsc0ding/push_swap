#include "../push_swap.h"

void	print_error(void)
{
	write(2, "Error\n", 6);
}

void	free_data(t_data *data)
{
	free(data->a.values);
	free(data->b.values);
	data->a.values = NULL;
	data->b.values = NULL;
	data->a.size = 0;
	data->b.size = 0;
}
