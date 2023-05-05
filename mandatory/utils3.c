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

int find_min(t_stack *stack)
{
	int min;
	int i;
	t_stack *stack2;

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

int find_max(t_stack *stack)
{
	int max;
	int i;
	t_stack *stack2;

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