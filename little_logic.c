/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_logic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:40:12 by hwiemann          #+#    #+#             */
/*   Updated: 2024/02/05 12:27:27 by hwiemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// creating sorting logics for 5 and less elements
// funktion that looks for the minimum and then cyc;ing through until you have it and push it to stack b
// then looking again for the net minimum, rotate and push to b -> creates reversed order and then pushing it back
// kleinste oder groesste zahl suchen
// vergleichen ob nachvorne oder hinten rotieren sinnvoller ist


#include "pushswap.h"

void	sort_three(struct s_stack **stack_a)
{
	int	min;
	int	max;

	min = find_min(*stack_a);
	max = find_max(*stack_a);

	if((*stack_a)->data == min)
	{
		rra(stack_a);
		sa(stack_a);
	}
	else if((*stack_a)->data == max)
	{
		ra(stack_a);
		if(check_sort(*stack_a) == 1)
				sa(stack_a);
	}
	else
	{
		if((*stack_a)->next->data == min)
			sa(stack_a);
		else
			rra(stack_a);
	}

	ft_printf("Stack A nach sort 3: ");
 	printstack(*stack_a);

}

void	sort_five(struct s_stack **stack_a, struct s_stack **stack_b)
{
	struct s_stack	*head;

	head = *stack_a;

	push_min(&head, stack_b);
	push_min(&head, stack_b);
	sort_three(&head);

	pa(&head, stack_b);
	pa(&head, stack_b);

	// ft_printf("Stack A nach sort 5: ");
 	// printstack(*stack_a);
	// ft_printf("Stack B nach sort 5: ");
 	// printstack(*stack_b);
}


