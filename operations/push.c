#include "../push_swap.h"

static void	push(t_stack *destination, t_stack *source)
{
	int	i;

	if (source->size == 0)
		return ;
	i = destination->size;
	while (i > 0)
	{
		destination->values[i] = destination->values[i - 1];
		i--;
	}
	destination->values[0] = source->values[0];
	destination->size++;
	i = 0;
	while (i < source->size - 1)
	{
		source->values[i] = source->values[i + 1];
		i++;
	}
	source->size--;
}

void	pa(t_stack *a, t_stack *b)
{
	push(a, b);
}

void	pb(t_stack *a, t_stack *b)
{
	push(b, a);
}
