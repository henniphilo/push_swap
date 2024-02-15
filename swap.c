/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:46:56 by hwiemann          #+#    #+#             */
/*   Updated: 2024/02/15 10:37:55 by hwiemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

//swapping the first to elements of a stack

void	swap_stack(struct s_stack **stack)
{
	struct s_stack	*tmp;

	tmp = (*stack)->next;
	if (*stack != NULL && (*stack)->next != NULL)
	{
		(*stack)->next = tmp->next;
		if(tmp->next != NULL)
		{
			tmp->next->prev = *stack;
		}
		tmp->next = *stack;
		tmp->prev = NULL;
		(*stack)->prev = tmp;
		*stack = tmp;
	}
}


// 	(*stack)->next->next = (*stack);
// 	(*stack)->next->prev = NULL;
// 	(*stack)->next = (*stack)->next->next;
// 	(*stack)->prev = (*stack)->next;

// }

struct s_stack	*sa(struct s_stack **stack_a)
{
	if (*stack_a == NULL || (*stack_a)->next == NULL)
	{
		return (*stack_a);
	}
	swap_stack(stack_a);
	ft_printf("sa\n");
	return (*stack_a);
}

// int	firstelement;
	// int	secondelement;

	// if (*stack == NULL)
	// {
	// 	ft_printf("Stack is empty no swapping");
	// 	return (NULL);
	// }
	// firstelement = (*stack)->data;
	// *stack = pop(*stack);
	// if (*stack == NULL)
	// {
	// 	ft_printf("Stack has not enaugh elements to swap");
	// 	return (NULL);
	// }
	// secondelement = (*stack)->data;
	// *stack = pop(*stack);
	// *stack = push(*stack, firstelement);
	// *stack = push(*stack, secondelement);
	// (*stack)->data = secondelement;
	// return (*stack);

struct s_stack	*sb(struct s_stack **stack_b)
{
	if (*stack_b == NULL)
	{
		return (*stack_b);
	}
	swap_stack(stack_b);
	ft_printf("sb\n");
	return (*stack_b);
}

int	ss(struct s_stack **stack_a, struct s_stack **stack_b)
{
	if (*stack_a == NULL || *stack_b == NULL)
	{
		return (1);
	}
	swap_stack(stack_a);
	swap_stack(stack_b);
	ft_printf("ss\n");
	return (0);
}
