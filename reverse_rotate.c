/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:47:30 by hwiemann          #+#    #+#             */
/*   Updated: 2024/02/12 14:11:32 by hwiemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

struct s_stack	*reverse_rotation(struct s_stack **stack)
{
	struct s_stack	*last;
	struct s_stack	*top;

	top = NULL;
	last = *stack;
	if (*stack == NULL || (*stack)->next == NULL)
	{
		ft_printf("Error");
		return (*stack);
	}
	while (last->next != NULL)
	{
		top = last;
		last = last->next;
	}
	top->next = NULL;
	last->next = *stack;
	*stack = last;
	return (*stack);
}

struct s_stack	*rra(struct s_stack **stack_a)
{
	if (*stack_a == NULL)
	{
		return (*stack_a);
	}
	reverse_rotation(stack_a);
	ft_printf("rra\n");
	return (*stack_a);
}

//rrb | reverse rotate the stack b, move the last element to the top.
struct s_stack	*rrb(struct s_stack **stack_b)
{
	if (*stack_b == NULL)
	{
		return (*stack_b);
	}
	reverse_rotation(stack_b);
	ft_printf("rrb\n");
	return (*stack_b);
}

//rra | reverse rotate the stack a, move the last element to the top.
int	rrr(struct s_stack **stack_a, struct s_stack **stack_b)
{
	if (*stack_a == NULL || *stack_b == NULL)
	{
		return (1);
	}
	reverse_rotation(stack_a);
	reverse_rotation(stack_b);
	ft_printf("rrr");
	return (0);
}
