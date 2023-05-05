/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 17:14:24 by jofilipe          #+#    #+#             */
/*   Updated: 2023/05/05 17:14:24 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_dups_str(char **array, int size)
{
	int	i;

	while (size > 0)
	{
		i = size - 1;
		while (i >= 0)
		{
			if(ft_atoi(array[i]) == ft_atoi(array[size]))
				return (-1);
			i--;
		}
	}
	return (0);
}

int	check_dups_arg(char **array, int size)
{
	int	i;

	while (size > 0)
	{
		i = size - 1;
		while (i > 0)
		{
			if(ft_atoi(array[i]) == ft_atoi(array[size]))
				return (-1);
			i--;
		}
		size--;
	}
	return (0);
}

int	check_order_sorted(t_stack *stack)
{
	int i;
	t_stack *stack_copy;

	stack_copy = copy_stack(stack);
	i = stack_copy->size;
	while (i > 1)
	{
		if (stack_copy->top->data > stack_copy->top->next->data)
		{
			free(stack_copy);
			return (-1);
		}
		stack_copy->top = stack_copy->top->next;
		i--;
	}
	stack_copy->top = stack_copy->top->next;
	free(stack_copy);
	return (0);
}