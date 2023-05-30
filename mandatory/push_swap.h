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

typedef struct s_stack
{
	int				size;
	struct s_node	*top;
	char			id;
}					t_stack;

typedef struct s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct moves_index
{
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
	int		sum;
}			t_moves_index;

//-------main-------//
int				string_to_stack(char *argv, t_stack *stack_a);
int				string_to_stack2(char **ar, int i, t_stack *stack);
int				param_to_stack(int argc, char **argv, t_stack *stack);
void			stack_init(t_stack *stack_a, t_stack *stack_b);

//-------checkers-------//
int				check_dups_str(char **array, int size);
int				check_dups_arg(char **array, int size);
int				check_order_sorted(t_stack *stack);

//-------operations1-------//
int				swap(t_stack *stack);
int				ss(t_stack *stack_a, t_stack *stack_b);
int				push(t_stack *source, t_stack *dest);
int				rotate(t_stack *stack);
int				reverse(t_stack *stack);

//-------operations2-------//
int				rr(t_stack *stack_a, t_stack *stack_b);
int				rrr(t_stack *stack_a, t_stack *stack_b);
void			operations(t_stack *stack_a, t_stack *stack_b, char *oper);
void			operations2(t_stack *stack_a, t_stack *stack_b, char *oper);

//-------sorts-------//
void			sort_alg(t_stack *stack_a, t_stack *stack_b);
void			sort2(t_stack *stack_a, t_stack *stack_b);
void			sort3(t_stack *stk_a, t_stack *stk_b);
void			sort5(t_stack *stk_a, t_stack *stk_b);

//-------sort_main-------//
void			sort_big(t_stack *stk_a, t_stack *stk_b);
void			count_moves(t_stack *stack, t_moves_index *init, int num);
t_moves_index	sort(t_stack *stack_a, t_stack *stack_b);
void			execute(t_moves_index *init, t_stack *stk_a, t_stack *stk_b);
void			execute2(t_moves_index *init, t_stack *stk_a, t_stack *stk_b);

//-------utils-------//
t_node			*create_node(int num);
void			stack_modif(t_node *node, t_stack *stack);
int				check_num(char *str);
t_stack			*copy_stack(t_stack *stack);
void			delete_top_node(t_stack *stack);

//-------utils2-------//
int				find_max_pos(t_stack *stack);
int				find_min_pos(t_stack *stack);
void			sort_min_max(t_stack *stk_a, t_stack *stk_b, int position);
int				match(t_stack *stack_b, int num);
int				find_index(t_stack *stack, int num);

//-------utils3-------//
int				find_min(t_stack *stack);
int				find_max(t_stack *stack);
void			moves_to_0(t_moves_index *init);
int				sum_moves(t_moves_index *init);
void			convert_rotates(t_moves_index *init);

//-------utils4-------//
int				sort_p2(t_moves_index *init, t_moves_index *best_init);
void			free_strings(char **str, int j);
void			free_stacks(t_stack *stack_a, t_stack *stack_b);
int				stack_string(char *argv, t_stack *stack_a);
int				stack_args(int argc, char **argv, t_stack *stack_a);

//-------utils5-------//
int check_string_empty(char *argv);

#endif //PUSH_SWAP_H
