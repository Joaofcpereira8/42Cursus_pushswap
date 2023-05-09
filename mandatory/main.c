/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 17:13:45 by jofilipe          #+#    #+#             */
/*   Updated: 2023/05/05 17:13:45 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size)
	{
		ft_printf("%i\n", stack->top->data);
		stack->top = stack->top->next;
		i++;
	}
}

int param_to_stack(int argc, char **argv, t_stack *stack)
{
	int temp;

	argc--;
	if (check_dups_arg(argv, argc) == -1)
		return (-1);
	while(argc > 0)
	{
		if (check_num(argv[argc]) == -1)
			return (-1);
		temp = ft_atoi(argv[argc]);
		stack_modif(create_node(temp), stack);
		argc--;
	}
	return (0);
}

int string_to_stack(char *argv, t_stack *stack)
{
	int		i;
	char 	**ar;
	int 	temp;

	ar = ft_split(argv, ' ');
	i = 0;
	while(ar[i])
		i++;
	i--;
	if (check_dups_str(ar, i) == -1)
		return (-1);
	while (i >= 0)
	{
		if (check_num(ar[i]) == -1)
			return (-1);
		temp = ft_atoi(ar[i]);
		stack_modif(create_node(temp), stack);
		i--;
	}
	return (0);
}

void	stack_init(t_stack *stack_a, t_stack *stack_b)
{
	stack_a->size = 0;
	stack_b->size = 0;
	stack_a->id = 'a';
	stack_b->id = 'b';
}

int main(int argc, char **argv)
{
    t_stack stack_a;
    t_stack stack_b;

    if  (argc < 2)
        return (0);
    if (argc == 2)
    {
		stack_init(&stack_a, &stack_b);
		if (string_to_stack(argv[1], &stack_a) == -1)
		{
			write (2, "Error\n", 6);
			return (-1);
		}
		if(check_order_sorted(&stack_a) == 0)
			return (-1);
    }
	if (argc > 2)
	{
		stack_init(&stack_a, &stack_b);
		if (param_to_stack(argc, argv, &stack_a) == -1)
		{
			write (2, "Error\n", 6);
			return (-1);
		}
		if(check_order_sorted(&stack_a) == 0)
			return (-1);
	}
	sort_alg(&stack_a, &stack_b);
//	print_list(&stack_a);
}