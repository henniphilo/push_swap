/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_logic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:40:12 by hwiemann          #+#    #+#             */
/*   Updated: 2024/01/30 11:34:05 by hwiemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// creating sorting logics for 5 and less elements
// funktion that looks for the minimum and then cyc;ing through until you have it and push it to stack b
// then looking again for the net minimum, rotate and push to b -> creates reversed order and then pushing it back

#include "pushswap.h"

int	find_min(struct s_stack *stack)
{
	struct s_stack	*head;
	int	min;

	head = stack;
	min = head->data;

	while(head != NULL)
	{
		if(head->data < min)
		{
			min = head->data;
		}
		head = head->next;
	}
	return(min);
}

//needs restructure to void
void	sort(struct s_stack **stack_a, struct s_stack **stack_b)
{
	// struct s_stack	*head;
	int	min;

	// head = *stack_a;

	ft_printf("kleinstes element: >%d<\n", find_min(*stack_a));

	while((*stack_a)->next != NULL)
	{
		min = find_min(*stack_a);
		while (*stack_a != NULL && (*stack_a)->data != min)
		{
			ra(&*stack_a);
		}
		ft_printf("data is: %i\n", (*stack_a)->data);
		if (*stack_a != NULL)
		{
			pb(&*stack_a, stack_b);
		}
		ft_printf("moving to next element\n");
	 }
	 ft_printf("Stack A after sort: ");
	printstack(*stack_a);
	ft_printf("Stack B after sort: ");
 	printstack(*stack_b);
}

void	sort_back(struct s_stack *stack_a, struct s_stack *stack_b)
{
	while(stack_b)
	{
		pa(&stack_a, &stack_b);
	}
	ft_printf("Stack A after sort_back: ");
	printstack(stack_a);
	ft_printf("Stack B after sort_back: ");
 	printstack(stack_b);
}

