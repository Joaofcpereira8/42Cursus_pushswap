/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 17:14:31 by jofilipe          #+#    #+#             */
/*   Updated: 2023/05/05 17:14:31 by jofilipe         ###   ########.fr       */
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
void		sort2(t_stack *stack_a, t_stack *stack_b);
void 		sort3(t_stack *stk_a, t_stack *stk_b);
void 		sort5(t_stack *stk_a, t_stack *stk_b);
int 		find_max_pos(t_stack *stack);
int 		find_min_pos(t_stack *stack);
void		sort_min_max(t_stack *stk_a, t_stack *stk_b, int position);
void		sort_alg(t_stack *stack_a, t_stack *stack_b);
void		sort_big(t_stack *stk_a, t_stack *stk_b);
int 		match(t_stack *stack_b, int num);
int 		find_min(t_stack *stack);
int 		find_max(t_stack *stack);




#endif //PUSH_SWAP_H
