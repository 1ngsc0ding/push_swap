#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef enum e_strategy
{
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE
}	t_strategy;

typedef struct s_stack
{
	int	*values;
	int	size;
}	t_stack;

typedef struct s_data
{
	t_stack		a;
	t_stack		b;
	t_strategy	strategy;
}	t_data;

int		parse_args(int argc, char **argv, t_data *data);
int		parse_number(const char **cursor, int *value);
int		is_duplicate(int *values, int size);
int		init_stacks(t_data *data, int capacity);
void	free_data(t_data *data);
void	print_error(void);

void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

#endif
