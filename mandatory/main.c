/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 17:13:45 by jofilipe          #+#    #+#             */
/*   Updated: 2023/05/05 17:13:45 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	param_to_stack(int argc, char **argv, t_stack *stack)
{
	int	temp;

	argc--;
	if (check_dups_arg(argv, argc) == -1)
		return (-1);
	while (argc > 0)
	{
		if (check_num(argv[argc]) == -1)
			return (-1);
		temp = ft_atoi(argv[argc]);
		stack_modif(create_node(temp), stack);
		argc--;
	}
	return (0);
}

int	string_to_stack(char *argv, t_stack *stack)
{
	int		i;
	char	**ar;
	int		j;

	ar = ft_split(argv, ' ');
	i = 0;
	if (!ar[0])
	{
		free_strings(ar, i);
		return (-1);
	}
	while (ar[i])
		i++;
	i--;
	j = i;
	if (check_dups_str(ar, i) == -1
		|| string_to_stack2(ar, i, stack) == -1)
	{
		free_strings(ar, j);
		return (-1);
	}
	free_strings(ar, j);
	return (0);
}

int	string_to_stack2(char **ar, int i, t_stack *stack)
{
	int	temp;

	while (i >= 0)
	{
		if (check_num(ar[i]) == -1)
			return (-1);
		temp = ft_atoi(ar[i]);
		stack_modif(create_node(temp), stack);
		i--;
	}
	return (0);
}

void	stack_init(t_stack *stack_a, t_stack *stack_b)
{
	stack_a->size = 0;
	stack_b->size = 0;
	stack_a->id = 'a';
	stack_b->id = 'b';
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	stack_init(&stack_a, &stack_b);
	if (argc == 2)
	{
		if (stack_string(argv[1], &stack_a) == -1)
		{
			free_stacks(&stack_a, &stack_b);
			return (-1);
		}
	}
	if (argc > 2)
	{
		if (stack_args(argc, argv, &stack_a) == -1)
		{
			free_stacks(&stack_a, &stack_b);
			return (-1);
		}
	}
	sort_alg(&stack_a, &stack_b);
	free_stacks(&stack_a, &stack_b);
}
