/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:25:12 by jofilipe          #+#    #+#             */
/*   Updated: 2023/05/16 14:25:12 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_p2(t_moves_index *init, t_moves_index *best_init)
{
	if (sum_moves(init) == 0)
	{
		*best_init = *init;
		return (-1);
	}
	if (sum_moves(init) < (*best_init).sum)
	{
		*best_init = *init;
		(*best_init).sum = sum_moves(init);
	}
	return (0);
}
