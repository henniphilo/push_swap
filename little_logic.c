/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_logic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:40:12 by hwiemann          #+#    #+#             */
/*   Updated: 2024/01/27 16:22:29 by hwiemann         ###   ########.fr       */
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

struct s_stack	*sort(struct s_stack *stack_a, struct s_stack *stack_b)
{
	//struct s_stack	*head;
	// int	min;

	/*if(check_sort(stack_a))
	{
		ft_printf("stack is already sorted");
		return(0);
	} */
	//head = stack_a;
	// min = find_min(head);
	// pb(&stack_a, &stack_b);


	ra(&stack_a);

/* 	while(stack_a)
	{
		min = find_min(stack_a);

		while (stack_a->data != min)
			ra(stack_a);
		pb(&stack_a, &stack_b);

		// if(stack_a->data == min)
		// {
		// 	ft_printf("data is: %i\n", head->data);
		// 	if (pb(&head, &stack_b) == 1)
		// 		ft_printf("error in push_b\n");
		// 	break;
		// }
		// ft_printf("moving to next element\n");
		// // head = head->next;
		// ra(head);
	} */
	printstack(stack_a);
	return(stack_b);
}

