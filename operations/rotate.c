#include "../push_swap.h"

static void	rotate(t_stack *stack)
{
	int	first;
	int	i;

	if (stack->size < 2) // No rotation needed for the stack with less than 2 elements
		return ;
	first = stack->values[0]; // Move the first element to the end of the stack
	i = 0;
	while (i < stack->size - 1) 
	{
		stack->values[i] = stack->values[i + 1]; // Shift by one position
		i++;
	}
	stack->values[stack->size - 1] = first;  
}

void	ra(t_stack *a)
{
	rotate(a);
}

void	rb(t_stack *b)
{
	rotate(b);
}

void	rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
}
