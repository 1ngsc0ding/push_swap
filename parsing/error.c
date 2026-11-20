#include "../push_swap.h"

void	print_error(void)
{
	write(2, "Error\n", 6);
}

void	free_data(t_data *data)
{
	free(data->a.values);
	data->a.values = NULL;
	data->a.size = 0;
	
	free(data->b.values);
	data->b.values = NULL;
	data->b.size = 0;
}
