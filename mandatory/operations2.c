/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 19:00:24 by jofilipe          #+#    #+#             */
/*   Updated: 2023/05/02 19:00:24 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rr(t_stack *stack_a, t_stack *stack_b)
{
	if(rotate(stack_a) == -1)
		return (-1);
	if(rotate(stack_b) == -1)
		return (-1);
	return (0);
}

int	rrr(t_stack *stack_a, t_stack *stack_b)
{
	if(reverse(stack_a) == -1)
		return (-1);
	if(reverse(stack_b) == -1)
		return (-1);
	return (0);
}

void operations(t_stack *stack_a, t_stack *stack_b, char *oper)
{
	if (ft_strncmp(oper, "sa\n", 3) == 0)
		if(swap(stack_a) == 0)
			write(1, "sa\n", 3);
	if (ft_strncmp(oper, "sb\n", 3) == 0)
		if(swap(stack_b) == 0)
			write(1, "sb\n", 3);
	if (ft_strncmp(oper, "ss\n", 3) == 0)
		if(ss(stack_a, stack_b) == 0)
			write(1, "ss\n", 3);
	if (ft_strncmp(oper, "pa\n", 3) == 0)
		if(push(stack_b, stack_a) == 0)
			write(1, "pa\n", 3);
	if (ft_strncmp(oper, "pb\n", 3) == 0)
		if(push(stack_a, stack_b) == 0)
			write(1, "pb\n", 3);
	if (ft_strncmp(oper, "ra\n", 3) == 0)
		if(rotate(stack_a) == 0)
			write(1, "ra\n", 3);
	if (ft_strncmp(oper, "rb\n", 3) == 0)
		if(rotate(stack_b) == 0)
			write(1, "rb\n", 3);
	operations2(stack_a, stack_b, oper);
}

void operations2(t_stack *stack_a, t_stack *stack_b, char *oper)
{
	if (ft_strncmp(oper, "rr\n", 3) == 0)
		if(rr(stack_a, stack_b) == 0)
			write(1, "rr\n", 3);
	if (ft_strncmp(oper, "rra\n", 4) == 0)
		if(reverse(stack_a) == 0)
			write(1, "rra\n", 4);
	if (ft_strncmp(oper, "rrb\n", 4) == 0)
		if(rotate(stack_a) == 0)
			write(1, "rrb\n", 4);
	if (ft_strncmp(oper, "rrr\n", 4) == 0)
		if (rrr(stack_a, stack_b) == 0)
			write(1, "rrr\n", 4);
}