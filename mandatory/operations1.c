/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 17:14:09 by jofilipe          #+#    #+#             */
/*   Updated: 2023/05/05 17:14:09 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_stack *stack)
{
	int	temp;

	if (stack->size < 2)
		return (-1);
	temp = stack->top->data;
	stack->top->data = stack->top->next->data;
	stack->top->next->data = temp;
	return (0);
}

int	ss(t_stack *stack_a, t_stack *stack_b)
{
	if (swap(stack_a) == -1)
		return (-1);
	if (swap(stack_b) == -1)
		return (-1);
	return (0);
}

int	push(t_stack *source, t_stack *dest)
{
	if (source->size == 0)
		return (-1);
	stack_modif(create_node(source->top->data), dest);
	delete_top_node(source);
	source->size -= 1;
	return (0);
}

int	rotate(t_stack *stack)
{
	if (stack->size == 0)
		return (-1);
	stack->top = stack->top->next;
	return (0);
}

int	reverse(t_stack *stack)
{
	if (stack->size == 0)
		return (-1);
	stack->top = stack->top->prev;
	return (0);
}
