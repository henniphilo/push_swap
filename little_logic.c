/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_logic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:40:12 by hwiemann          #+#    #+#             */
/*   Updated: 2024/01/29 19:00:32 by hwiemann         ###   ########.fr       */
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
struct s_stack	*sort(struct s_stack *stack_a, struct s_stack *stack_b)
{
	struct s_stack	*head = stack_a;


	if(!(check_sort(stack_a)))
	{
		ft_printf("stack is already sorted");
		return(stack_a);
	}
	ft_printf("kleinstes element: >%d<\n", find_min(stack_a));

	while(stack_a->next != NULL)
	{
	 while (!(head->data == find_min(head)))
	 {
		ra(&head);
	 }
		ft_printf("data is: %i\n", head->data);
			if (pb(&head, &stack_b) == 1)
			{
				ft_printf("error in push_b\n");
				break;
			}
		ft_printf("moving to next element\n");
		// ra(head);
	 }
	// ft_printf("Stack A after sort: ");
	// printstack(stack_a);
	// ft_printf("Stack B after sort: ");
 	// printstack(stack_b);
	return(stack_b);
}

