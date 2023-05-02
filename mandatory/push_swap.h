/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 18:49:06 by jofilipe          #+#    #+#             */
/*   Updated: 2023/04/22 18:49:06 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>

typedef struct	s_stack
{
    int				size;
    struct s_node	*top;
}					t_stack;

typedef struct s_node
{
    int				data;
    struct s_node	*next;
    struct s_node	*prev;
}					t_node;

int 		string_to_stack(char *argv, t_stack *stack_a);
int 		param_to_stack(int argc, char **argv, t_stack *stack);
t_node 		*create_node(int num);
void		stack_modif(t_node *node, t_stack *stack);
int 		check_num(char *str);
int			check_dups_str(char **array, int size);
int			check_dups_arg(char **array, int size);
int			check_order_sorted(t_stack *stack);
t_stack		*copy_stack(t_stack *stack);
int			swap(t_stack *stack);
int			ss(t_stack *stack_a, t_stack *stack_b);
int 		push(t_stack *source, t_stack *dest);
int 		rotate(t_stack *stack);
int 		reverse(t_stack *stack);
int			rr(t_stack *stack_a, t_stack *stack_b);
int			rrr(t_stack *stack_a, t_stack *stack_b);
void		delete_top_node(t_stack *stack);
void 		operations(t_stack *stack_a, t_stack *stack_b, char *oper);
void 		operations2(t_stack *stack_a, t_stack *stack_b, char *oper);




#endif //PUSH_SWAP_H
