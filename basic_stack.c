/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:20:17 by hwiemann          #+#    #+#             */
/*   Updated: 2024/02/07 14:21:18 by hwiemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	stackempty(struct s_stack *stack)
{
	return (stack->next == NULL);
}

int	stacksize(struct s_stack *stack)
{
	int	i;

	i = 0;
	if (stackempty(stack))
		return (1);
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

static void ft_swap(struct s_stack *a, struct s_stack *b)
{
	struct s_stack	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static void	bubble_index(struct s_stack **stack)
{
	int	swapped;
	struct s_stack	*bubble;
	//struct s_stack	*blubb;

	swapped = 1;

	while(swapped)
	{
		swapped = 0;
		bubble = *stack;
		//blubb = NULL;

		while(bubble && bubble->next)
		{
			if(bubble->data > bubble->next->data)
			{
				ft_swap(bubble, bubble->next);
				swapped = 1;
			}
		bubble = bubble->next;
		}
	}
}

void	stack_index(struct s_stack *stack)
{
	int	index;

	index = 1;

	bubble_index(&stack);

	while(stack != NULL)
		{
			stack ->index = index++;
			stack = stack->next;
		}
}
