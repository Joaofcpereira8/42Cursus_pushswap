/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 18:27:13 by jofilipe          #+#    #+#             */
/*   Updated: 2023/05/05 18:27:13 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_stack *stack)
{
	int		min;
	int		i;
	t_stack	*stack2;

	i = 1;
	stack2 = copy_stack(stack);
	min = stack2->top->data;
	while (i <= stack2->size)
	{
		if (stack2->top->data < min)
			min = stack2->top->data;
		stack2->top = stack2->top->next;
		i++;
	}
	return (min);
}

int	find_max(t_stack *stack)
{
	int		max;
	int		i;
	t_stack	*stack2;

	i = 1;
	stack2 = copy_stack(stack);
	max = stack2->top->data;
	while (i <= stack2->size)
	{
		if (stack2->top->data > max)
			max = stack2->top->data;
		stack2->top = stack2->top->next;
		i++;
	}
	return (max);
}

void	moves_to_0(t_moves_index *init)
{
	init->ra = 0;
	init->rb = 0;
	init->rr = 0;
	init->rra = 0;
	init->rrb = 0;
	init->rrr = 0;
	init->sum = 0;
}

int	sum_moves(t_moves_index *init)
{
	int	total;

	total = 0;
	convert_rotates(init);
	total += init->ra;
	total += init->rb;
	total += init->rra;
	total += init->rrb;
	total += init->rr;
	total += init->rrr;
	return (total);
}

void	convert_rotates(t_moves_index *init)
{
	while (init->ra >= 1 && init->rb >= 1)
	{
		init->rr += 1;
		init->ra--;
		init->rb--;
	}
	while (init->rra >= 1 && init->rrb >= 1)
	{
		init->rrr += 1;
		init->rra--;
		init->rrb--;
	}
}
