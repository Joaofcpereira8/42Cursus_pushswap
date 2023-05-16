/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 18:07:05 by jofilipe          #+#    #+#             */
/*   Updated: 2023/05/05 18:07:05 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_big(t_stack *stk_a, t_stack *stk_b)
{
	t_moves_index	init;

	moves_to_0(&init);
	operations(stk_a, stk_b, "pb");
	operations(stk_a, stk_b, "pb");
	while (stk_a->size > 0)
	{
		init = sort(stk_a, stk_b);
		execute(&init, stk_a, stk_b);
	}
	moves_to_0(&init);
	count_moves(stk_b, &init, find_max(stk_b));
	execute(&init, stk_a, stk_b);
	while (stk_b->size)
		operations(stk_a, stk_b, "pa");
}

void	count_moves(t_stack *stack, t_moves_index *init, int num)
{
	int	position;
	int	mid;

	position = find_index(stack, num);
	mid = stack->size / 2;
	if (position <= mid)
	{
		if (stack->id == 'a')
			init->ra = position;
		else
			init->rb = position;
	}
	if (position > mid)
	{
		if (stack->id == 'a')
			init->rra = stack->size - position;
		else
			init->rrb = stack->size - position;
	}
}

t_moves_index	sort(t_stack *stack_a, t_stack *stack_b)
{
	t_moves_index	init;
	t_moves_index	best_init;
	t_stack			*copy;

	copy = copy_stack(stack_a);
	moves_to_0(&init);
	count_moves(stack_a, &init, stack_a->top->data);
	count_moves(stack_b, &init, match(stack_b, stack_a->top->data));
	best_init = init;
	best_init.sum = sum_moves(&init);
	while (copy->size > 0)
	{
		moves_to_0(&init);
		count_moves(stack_a, &init, copy->top->data);
		count_moves(stack_b, &init, match(stack_b, copy->top->data));
		if (sort_p2(&init, &best_init) == -1)
			break ;
		copy->size--;
		copy->top = copy->top->next;
	}
	free (copy);
	return (best_init);
}

void	execute(t_moves_index *init, t_stack *stk_a, t_stack *stk_b)
{
	while (init->ra)
	{
		operations(stk_a, stk_b, "ra");
		init->ra--;
	}
	while (init->rb)
	{
		operations(stk_a, stk_b, "rb");
		init->rb--;
	}
	while (init->rra)
	{
		operations(stk_a, stk_b, "rra");
		init->rra--;
	}
	while (init->rrb)
	{
		operations(stk_a, stk_b, "rrb");
		init->rrb--;
	}
	execute2(init, stk_a, stk_b);
}

void	execute2(t_moves_index *init, t_stack *stk_a, t_stack *stk_b)
{
	while (init->rr)
	{
		operations(stk_a, stk_b, "rr");
		init->rr--;
	}
	while (init->rrr)
	{
		operations(stk_a, stk_b, "rrr");
		init->rrr--;
	}
	operations(stk_a, stk_b, "pb");
}
