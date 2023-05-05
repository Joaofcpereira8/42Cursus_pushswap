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
	operations(stk_a, stk_b, "pb");
	operations(stk_a, stk_b, "pb");

}