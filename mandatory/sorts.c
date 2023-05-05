/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 17:13:23 by jofilipe          #+#    #+#             */
/*   Updated: 2023/05/05 17:13:23 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_alg(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 2)
		sort2(stack_a, stack_b);
	if (stack_a->size == 3)
		sort3(stack_a, stack_b);
	if (stack_a->size == 4 || stack_a->size == 5)
		sort5(stack_a, stack_b);
//	if (stack_a->size > 5)
//		sort_big(stack_a, stack_b);
}

void	sort2(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->top->data > stack_a->top->next->data)
		operations(stack_a, stack_b, "sa");
}

void sort3(t_stack *stk_a, t_stack *stk_b)
{
	if (stk_a->top->data > stk_a->top->next->data && stk_a->top->next->data
		< stk_a->top->prev->data && stk_a->top->data < stk_a->top->prev->data)
		operations(stk_a, stk_b, "sa");
	if (stk_a->top->data > stk_a->top->next->data && stk_a->top->next->data
	> stk_a->top->prev->data && stk_a->top->data > stk_a->top->prev->data)
	{
		operations(stk_a, stk_b, "sa");
		operations(stk_a, stk_b, "rra");
	}
	if (stk_a->top->data > stk_a->top->next->data && stk_a->top->next->data
		< stk_a->top->prev->data && stk_a->top->data > stk_a->top->prev->data)
		operations(stk_a, stk_b, "ra");
	if (stk_a->top->data < stk_a->top->next->data && stk_a->top->next->data
		> stk_a->top->prev->data && stk_a->top->data < stk_a->top->prev->data)
	{
		operations(stk_a, stk_b, "sa");
		operations(stk_a, stk_b, "ra");
	}
	if (stk_a->top->data < stk_a->top->next->data && stk_a->top->next->data
		> stk_a->top->prev->data && stk_a->top->data > stk_a->top->prev->data)
		operations(stk_a, stk_b, "rra");
}

void sort5(t_stack *stk_a, t_stack *stk_b)
{
	int position;

	position = find_min_pos(stk_a);
	sort_min_max(stk_a, stk_b, position);
	operations(stk_a, stk_b, "pb");
	if (stk_a->size == 4)
	{
		position = find_max_pos(stk_a);
		sort_min_max(stk_a, stk_b, position);
		operations(stk_a, stk_b, "pb");
	}
	sort3(stk_a, stk_b);
	if (stk_a->size == 3 && stk_b->size == 2)
	{
		operations(stk_a, stk_b, "pa");
		operations(stk_a, stk_b, "ra");
		operations(stk_a, stk_b, "pa");
	}
	if (stk_a->size == 3 && stk_b->size == 1)
		operations(stk_a, stk_b, "pa");
}

