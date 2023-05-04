/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:54:45 by jofilipe          #+#    #+#             */
/*   Updated: 2023/05/03 12:54:45 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_max_pos(t_stack *stack)
{
	int max;
	int	pos;
	int i;
	t_stack *stack2;

	i = 1;
	stack2 = copy_stack(stack);
	max = stack2->top->data;
	while (i <= stack2->size)
	{
		if (stack2->top->data > max)
		{
			max = stack2->top->data;
			pos = i;
		}
		stack2->top = stack2->top->next;
		i++;
	}
	return (pos);
}

int find_min_pos(t_stack *stack)
{
	int min;
	int	pos;
	int i;
	t_stack *stack2;

	pos = 1;
	i = 1;
	stack2 = copy_stack(stack);
	min = stack2->top->data;
	while (i <= stack2->size)
	{
		if (stack2->top->data < min)
		{
			min = stack2->top->data;
			pos = i;
		}
		stack2->top = stack2->top->next;
		i++;
	}
	return (pos);
}

void	sort_min_max(t_stack *stk_a, t_stack *stk_b, int position)
{
	if (position > 1 && position <= 3)
	{
		while (position > 1)
		{
			operations(stk_a, stk_b, "ra");
			position--;
		}
	}
	if (position > 3 && position <= 5)
	{
		while (position <= stk_a->size)
		{
			operations(stk_a, stk_b, "rra");
			position++;
		}
	}
}