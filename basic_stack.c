/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:20:17 by hwiemann          #+#    #+#             */
/*   Updated: 2023/10/13 12:48:43 by hwiemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	initialize(t_Stack *stack)
{
	stack->top = NULL;
}

int	stackempty(t_Stack *stack)
{
	return (stack->top == NULL);
}

int	stacksize(t_Stack *stack)
{
	int	i;

	i = 0;
	if (stackempty(*stack))
		return;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

void	push(t_Stack *stack, int data)
{
	t_Node	*newNode;

	newNode = (t_Node *)malloc(sizeof(t_Node));
	if (!newNode)
	{
		ft_printf("Error");
		return;
	}
	newNode->data = data;
	newNode->next = stack->top;
	stack->top = newNode;
	stack->size++;
}

//top wegnehmen vom stack

int	pop(t_Stack *stack)
{
	int	data;
	t_Node	*tmp;

	if (stackempty(stack))
	{
		ft_printf("Error");
		return(1);
	}
	data = stack->top->data;
	*tmp = stack->top;
	stack->top = stack->top->next;
	free(tmp);
	stack->size--;
	return(data);
}

void	rotate(t_Stack *stack)
{
	int	tmp;

	tmp = pop(stack);
	if (stackempty(stack))
	{
		ft_printf("stack empty");
		return;
	}

	if (stackempty(stack))
	{
		push(stack, tmp);
		return;
	}
	rotate(stack);
	push(stack, tmp);
}
