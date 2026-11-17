#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_data	data;

	data.a.values = NULL; // Stack A intialises with an empty array. It will be filled from the command line arguments.
	data.a.size = 0;
	data.b.values = NULL; // Stack B initialises with an empty array. It will be filled during the sorting process.
	data.b.size = 0; 
	data.strategy = ADAPTIVE;

	// If parsing fails, print "Error" and free the allocated memory before exiting
	if (!parse_args(argc, argv, &data))
	{
		print_error();
		free_data(&data);
		return (1);
	}
	// No numbers given: display nothing and exit successfully
	if (data.a.size == 0)
	{
		free_data(&data);
		return (0);
	}
	// Connect to the sorted algo here
	free_data(&data);
	return (0);
}