/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 12:27:42 by hwiemann          #+#    #+#             */
/*   Updated: 2023/10/10 11:03:39 by hwiemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//stacks bilden
// checken ob elemente valide sind
// in bereich von int min und max
// checken nach vorzeichen
// befehle implementieren
// dann logik

#include "pushswap.h"

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

int	check_duplicates(int array[], int size, int num)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if ( array[i++] == num)
			return 1;
	}
	return (0);
}

void	check_args(int argc, char *argv[], t_Stack *stackA, int *sizeA)
{
	int	data[STACK_SIZE];
	int	i;
	int	num;

	*stackA = 0;
	i = 1;
	while (i< argc)
	{
		// muss noch checken nach vorzeichen

		if (num < INT_MIN || num > INT_MAX)
		{
			printf("not in the range");
			exit(-1);
		}
		if (check_duplicates(data, *sizeA, num))
		{
			printf("dups");
			exit(-1);
		}
		stackA[*sizeA] = num;
		i++;
	}
}

//converting arguments von char in int
//checking for the right arguments, nur zahlen nichts doppelt
int	main(int argc, char *argv[])
{
	t_list	**stackA;
	t_list	**stackB;

	if (argc < 2)
		return(-1);
	check_args();

	initialize(&stackA);
	initialize(&stackB);

	return (0);
}
