/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 17:59:21 by hwiemann          #+#    #+#             */
/*   Updated: 2024/02/11 17:59:35 by hwiemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	best_way(struct s_stack **head, struct s_stack **head_b)
{
	int	max;
	int	pos;
	int	size;

	max = find_max(*head_b);
	size = stacksize(*head_b);
	pos = find_num_position(*head_b, max, size);
	if (pos == 1)
		sb(head_b);
	else if (pos <= (size / 2 + size % 2))
	{
		while (*head_b != NULL && (*head_b)->data != max)
		{
			rb(head_b);
		}
		pa(head, head_b);
	}
	else if (*head_b && (pos > (size / 2 + size % 2)))
	{
		while (*head_b != NULL && (*head_b)->data != max)
			rrb(head_b);
	}
}

void	push_max(struct s_stack **stack_a, struct s_stack **stack_b)
{
	struct s_stack	*head;
	struct s_stack	*head_b;
	int				max;

	head = *stack_a;
	head_b = *stack_b;
	max = find_max(head_b);
	if (head_b->data == max)
	{
		pa(&head, &head_b);
	}
	else
		best_way(&head, &head_b);
	*stack_a = head;
	*stack_b = head_b;
}

void	sort_max(struct s_stack **stack_a, struct s_stack **stack_b)
{
	struct s_stack	*head;
	struct s_stack	*head_b;

	head = *stack_a;
	head_b = *stack_b;
	while (head_b)
	{
		push_max(&head, &head_b);
	}
	*stack_a = head;
	*stack_b = head_b;
}
