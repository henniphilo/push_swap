/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smaller_logic.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:40:12 by hwiemann          #+#    #+#             */
/*   Updated: 2024/02/14 14:32:17 by hwiemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	to_three(struct s_stack **stack_a, int min, int max)
{
	if ((*stack_a)->data == min)
	{
		rra(stack_a);
		sa(stack_a);
	}
	else if ((*stack_a)->data == max)
	{
		ra(stack_a);
		if (check_sort(*stack_a) == 1)
			sa(stack_a);
	}
	else
	{
		if ((*stack_a)->next->data == min)
			sa(stack_a);
		else
			rra(stack_a);
	}
}

void	sort_three(struct s_stack **stack_a)
{
	int	min;
	int	max;

	min = find_min(*stack_a);
	max = find_max(*stack_a);
	if (check_sort(*stack_a) == 1)
	{
		to_three(stack_a, min, max);
	}
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
	// free(head);
	//free(stack_b);
}
