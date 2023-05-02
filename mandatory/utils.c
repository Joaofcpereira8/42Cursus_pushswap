//
// Created by jofilipe on 4/20/23.
//

#include "push_swap.h"

t_node *create_node(int num)
{
	t_node *newNode;

	newNode = malloc (sizeof(t_node));
	newNode->data = num;
	newNode->next = NULL;
	newNode->prev = NULL;
	return (newNode);
}

void	stack_modif(t_node *new_node, t_stack *stack)
{
	if (stack->size == 0)
	{
		stack->top = new_node;
		stack->top->next = new_node;
		stack->top->prev = new_node;
		stack->size++;
	}
	else
	{
		new_node->next = stack->top; //2 -> 3
		new_node->prev = stack->top->prev; //2->3->2
		stack->top->prev->next = new_node; //2->3->4->2
		stack->top->prev = new_node;
		stack->top = new_node;
		stack->size++;
	}
}

int check_num(char *str)
{
	if (str[0] == '0' && ft_atoi(str) == 0 && (str[1] == ' ' || str[1] == '\0'))
		return (1);
	else if (ft_atoi(str) == 0)
		return (-1);
	else if (ft_atol(str) >= INT_MIN && ft_atol(str) <= INT_MAX)
		return (1);
	return (-1);
}

t_stack		*copy_stack(t_stack *stack)
{
	t_stack *stack_copy;

	stack_copy = malloc(sizeof (t_stack));
	stack_copy->size = stack->size;
	stack_copy->top = stack->top;
	return (stack_copy);
}

void	delete_top_node(t_stack *stack)
{
	t_node *temp;

	temp = stack->top;
	stack->top = stack->top->next;
	stack->top->prev->prev->next = stack->top;
	stack->top->prev = stack->top->prev->prev;
	free(temp);
}