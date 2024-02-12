/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finder_putter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:25:37 by hwiemann          #+#    #+#             */
/*   Updated: 2024/02/12 13:43:55 by hwiemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// push part min
void	part_min(struct s_stack **stack_a, struct s_stack **stack_b, int part)
{
	int	current_pos;
	int	min_pos;

	min_pos = find_min_in_part(*stack_a, part);
	current_pos = 0;
	if (min_pos == 1)
	{
		sa(stack_a);
	}
	else
	{
		while (*stack_a && current_pos < min_pos)
		{
			ra(&*stack_a);
			current_pos++;
		}
	}
	if (current_pos == min_pos)
	{
		pb(&*stack_a, stack_b);
	}
}

void	push_min(struct s_stack **stack_a, struct s_stack **stack_b)
{
	int	min;
	int	min_pos;
	int	size;

	min = find_min(*stack_a);
	min_pos = find_min_position(*stack_a);
	size = stacksize(*stack_a);
	if (min_pos == 1)
	{
		sa(stack_a);
	}
	else if (min_pos <= (size / 2 + size % 2))
	{
		while (*stack_a != NULL && (*stack_a)->data != min)
			ra(stack_a);
	}
	else if (min_pos > (size / 2 + size % 2))
	{
		while (*stack_a != NULL && (*stack_a)->data != min)
			rra(stack_a);
	}
	if ((*stack_a)->data == min)
		pb(&*stack_a, stack_b);
}

void	put_on_top_a(struct s_stack **stack, int num)
{
	struct s_stack	*head;
	int				num_pos;
	int				size;

	head = *stack;
	size = stacksize(*stack);
	num_pos = find_num_position(*stack, num, size);
	if (stack == NULL)
	{
		return ;
	}
	if (num_pos == 1)
		sa(stack);
	else if (num_pos <= (size / 2 + size % 2))
	{
		while (*stack != NULL && (*stack)->data != num)
			ra(stack);
	}
	else if (num_pos > (size / 2 + size % 2))
	{
		while (*stack != NULL && (*stack)->data != num)
			rra(stack);
	}
}

void	put_on_top_b(struct s_stack **stack, int num)
{
	struct s_stack	*head;
	int				num_pos;
	int				size;

	head = *stack;
	size = stacksize(*stack);
	num_pos = find_num_position(*stack, num, size);
	if (stack == NULL)
	{
		return ;
	}
	if (num_pos == 1)
		sb(stack);
	else if (num_pos <= (size / 2 + size % 2))
	{
		while (*stack != NULL && (*stack)->data != num)
			rb(stack);
	}
	else if (num_pos > (size / 2 + size % 2))
	{
		while (*stack != NULL && (*stack)->data != num)
			rrb(stack);
	}
}
