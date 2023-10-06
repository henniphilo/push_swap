/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 12:27:42 by hwiemann          #+#    #+#             */
/*   Updated: 2023/10/06 12:15:04 by hwiemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//stacks bilden
// checken ob elemente valide sind
// in bereich von int min und max
// checken nach vorzeichen
// befehle implementieren
// dann logik

#include "push_swap.h"

void	initialize(t_Stack *stack)
{
	stack->top = NULL;
}

int	stackempty(t_Stack *stack)
{
	return (stack->top == NULL);
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

int	main(void)
{
	t_Stack	stackA;
	t_Stack	stackB;

	initialize(&stackA);
	initialize(&stackB);

	return (0);
}
