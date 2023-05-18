/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:25:12 by jofilipe          #+#    #+#             */
/*   Updated: 2023/05/16 14:25:12 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_p2(t_moves_index *init, t_moves_index *best_init)
{
	if (sum_moves(init) == 0)
	{
		*best_init = *init;
		return (-1);
	}
	if (sum_moves(init) < (*best_init).sum)
	{
		*best_init = *init;
		(*best_init).sum = sum_moves(init);
	}
	return (0);
}

void	free_strings(char **str, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_stacks(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a->size > 0)
	{
		delete_top_node(stack_a);
		stack_a->size--;
	}
	while (stack_b->size > 0)
	{
		delete_top_node(stack_b);
		stack_b->size--;
	}
}

int	stack_string(char *argv, t_stack *stack_a)
{
	if (string_to_stack(argv, stack_a) == -1)
	{
		write (2, "Error\n", 6);
		return (-1);
	}
	if (check_order_sorted(stack_a) == 0)
		return (-1);
	return (0);
}

int	stack_args(int argc, char **argv, t_stack *stack_a)
{
	if (param_to_stack(argc, argv, stack_a) == -1)
	{
		write (2, "Error\n", 6);
		return (-1);
	}
	if (check_order_sorted(stack_a) == 0)
		return (-1);
	return (0);
}
