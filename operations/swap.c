#include "../push_swap.h"

static void	swap(t_stack *stack)
{
	int	temp;

	if (stack->size < 2) // No swap needed for the stack with less than 2 elements
		return ;
	temp = stack->values[0];
	stack->values[0] = stack->values[1];
	stack->values[1] = temp;
}

void	sa(t_stack *a)
{
	swap(a);
}

void	sb(t_stack *b)
{
	swap(b);
}

void	ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
}
