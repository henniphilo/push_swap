/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 13:43:35 by hwiemann          #+#    #+#             */
/*   Updated: 2024/02/15 11:54:36 by hwiemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// struct s_stack	*pop(struct s_stack *head)
// {
// 	struct s_stack	*newhead;

// 	if (head == NULL)
// 	{
// 		ft_printf("empty stack\n");
// 		return (0);
// 	}
// 	newhead = head->next;
// 	//	free (head);
// 	if (newhead != NULL)
// 	{
// 		newhead->prev = NULL;
// 	}
// 	return (newhead);
// }

void	push_stack(struct s_stack **head_from, struct s_stack **head_to)
{
	struct s_stack	*newnode;

	newnode = NULL;
	if (*head_from)
	{
		newnode = *head_from;
		if ((*head_from)->next)
		{
			(*head_from)->next->prev = NULL;
		}
		*head_from = (*head_from)->next;
	}
	if (*head_to)
	{
		newnode->next = *head_to;
		(*head_to)->prev = newnode;
	}
	else
	{
		newnode->next = NULL;
	}
	*head_to = newnode;
}

//pa | push the first element of stack b to the top of stack a

void	pa(struct s_stack **stack_a, struct s_stack **stack_b)
{
	push_stack(stack_b, stack_a);
	ft_printf("pa\n");
}

// pb | push the first element of stack a to the top of stack b

void	pb(struct s_stack **stack_a, struct s_stack **stack_b)
{
	push_stack(stack_a, stack_b);
	ft_printf("pb\n");
}
