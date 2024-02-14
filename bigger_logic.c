/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigger_logic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:21:51 by hwiemann          #+#    #+#             */
/*   Updated: 2024/02/14 20:27:42 by hwiemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	hin_her(struct s_stack **stack_a, struct s_stack **stack_b, int chunk)
{
	struct s_stack	*head;
	struct s_stack	*head_b;
	int				size;
	int				current_pos;

	size = stacksize(*stack_a);
	head = *stack_a;
	head_b = *stack_b;
	current_pos = 0;
	while (head && current_pos < size)
	{
		if (head->index <= chunk)
		{
			pb(&head, &head_b);
		}
		else
		{
			ra(&head);
		}
		current_pos++;
	}
	*stack_a = head;
	*stack_b = head_b;
}

int	chunky(int argc)
{
	int	chunk;

	chunk = 0;
	if ((argc - 1) >= 6 && (argc - 1) <= 100)
	{
		chunk = ((argc - 1) / 5 + (argc - 1) % 5);
	}
	else if ((argc - 1) >= 101 && (argc - 1) <= 500)
	{
		chunk = ((argc - 1) / 11 + (argc - 1) % 11);
	}
	else
		chunk = (argc - 1);
	return (chunk);
}

static void	way(t_stack **head, t_stack **head_b, int argc, int chunk)
{
	int	i;

	i = 0;
	if ((argc - 1) >= 6 && (argc - 1) <= 100)
	{
		while (*head && i != 6)
		{
			hin_her(head, head_b, chunk * i + 1);
			i++;
		}
	}
	else if ((argc - 1) >= 101 && (argc - 1) <= 500)
	{
		while (*head && i != 12)
		{
			hin_her(head, head_b, chunk * i + 1);
			i++;
		}
	}
	else
		hin_her(head, head_b, chunk);
}

void	wtf(struct s_stack **stack_a, struct s_stack **stack_b, int argc)
{
	struct s_stack	*head;
	struct s_stack	*head_b;
	int				chunk;

	head = *stack_a;
	head_b = *stack_b;
	chunk = chunky(argc);
	way(&head, &head_b, argc, chunk);
	sort_max(&head, &head_b);
	*stack_a = head;
	*stack_b = head_b;
	//free(*stack_b);
}
