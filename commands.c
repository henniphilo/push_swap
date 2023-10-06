/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 11:45:50 by hwiemann          #+#    #+#             */
/*   Updated: 2023/10/06 16:57:59 by hwiemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

//pb | push the first element of stack a to the top of stack b.
void	pb(t_Stack *stackA, t_Stack *stackB)
{
	int	topElement;

	if(!stackempty(stackA))
	{
		topElement = pop(stackA);
		push(stackB, topElement);
		printf("pb");
	}
	else
	{
		printf("pbError");
	}
}

//pa | push the first element of stack b to the top of stack a.
void	pa(t_Stack *stackA, t_Stack *stackB)
{
	int	topElement;

	if(!stackempty(stackB))
	{
		topElement = pop(stackB);
		push(stackA, topElement);
		printf("pa");
	}
	else
	{
		printf("paError");
	}
}

void	sa(t_Stack *stackA)
{
	int	top;
	int	next;

	if(stackA->top != NULL && stackA->top->next != NULL)
	{
		top = pop(stackA);
		next = pop(stackA);

		push(stackA, top);
		push(stackA, next);
		printf("sa");
	}
	else
	{
		printf("swapaError\n");
	}
}

void	sb(t_Stack *stackB)
{
	int	top;
	int	next;

	if(stackB->top != NULL && stackB->top->next != NULL)
	{
		top = pop(stackB);
		next = pop(stackB);

		push(stackB, top);
		push(stackB, next);
		printf("sb");
	}
	else
	{
		printf("swapbError\n");
	}
}

void	ss(t_Stack *stackA, t_Stack *stackB)
{
	sa(stackA);
	sb(stackB);
	printf("ss");
}

//ra (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one
//eventuell ft_lstlast verwenden fuer letzten node der liste?
void	ra(t_Stack *stackA)
{
	int	top;
	int	elements[MAX_SIZE];
	int	i;
	//int	last;

	i = 1;
	top = elements[0];

	sizeof(stackA)

	if(!stackempty(stackA))
	{
		top = pop(stackA);
		while(elements[i])
		{
			pop(stackA);
			i++;
		}
		push(stackA, top);
		while (i >= 0)
		{
			push(stackA; elements[i++])
		}
		printf("ra");
	}
	else
	{
		printf("fail")
	}
}
