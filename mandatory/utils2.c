/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 17:13:32 by jofilipe          #+#    #+#             */
/*   Updated: 2023/05/05 17:13:32 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_pos(t_stack *stack)
{
	int		max;
	int		pos;
	int		i;
	t_stack	*stack2;

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
	free (stack2);
	return (pos);
}

int	find_min_pos(t_stack *stack)
{
	int		min;
	int		pos;
	int		i;
	t_stack	*stack2;

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
	free (stack2);
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

int	match(t_stack *stack_b, int num)
{
	int		match_num;
	int		max;
	t_stack	*stack2;

	match_num = find_min(stack_b);
	max = find_max(stack_b);
	stack2 = copy_stack(stack_b);
	if (num > max || num < match_num)
	{
		free (stack2);
		return (max);
	}
	while (stack2->size--)
	{
		if (stack2->top->data < num && stack2->top->data > match_num)
			match_num = stack2->top->data;
		stack2->top = stack2->top->next;
	}
	free (stack2);
	return (match_num);
}

int	find_index(t_stack *stack, int num)
{
	int		index;
	t_stack	*stack_2;

	index = 0;
	stack_2 = copy_stack(stack);
	while (num != stack_2->top->data)
	{
		stack_2->top = stack_2->top->next;
		index++;
	}
	free (stack_2);
	return (index);
}
