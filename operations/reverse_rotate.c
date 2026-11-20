#include "../push_swap.h"

static void	reverse_rotate(t_stack *stack) // Just using t_stack cuz I only wanna rotate a stack at the time
{
	int	last;
	int	i;

	if (stack->size < 2) // No reverse rotation needed for the stack with less than 2 elements
		return ;
	last = stack->values[stack->size - 1];
	i = stack->size - 1;
	while (i > 0)
	{
		stack->values[i] = stack->values[i - 1];
		i--;
	}
	stack->values[0] = last;
}

void	rra(t_stack *a)
{
	reverse_rotate(a);
}

void	rrb(t_stack *b)
{
	reverse_rotate(b);
}

void	rrr(t_stack *a, t_stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}
