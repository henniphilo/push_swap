/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 13:43:35 by hwiemann          #+#    #+#             */
/*   Updated: 2024/02/10 19:06:12 by hwiemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

struct s_stack	*pop(struct s_stack *head)
{
	struct s_stack	*newhead;

	if (head == NULL)
	{
		ft_printf("empty stack\n");
		return (0);
	}
	newhead = head->next;
	free (head);
	if (newhead != NULL)
	{
		newhead->prev = NULL;
	}
	return (newhead);
}

struct s_stack	*push(struct s_stack *head, int data)
{
	struct s_stack	*newnode;

	newnode = create_node(data);
	if (newnode == NULL)
	{
		ft_printf("no pushing today\n");
		return (head);
	}
	if (head == NULL)
	{
		return (newnode);
	}
	newnode->next = head;
	head->prev = newnode;
	return (newnode);
}

//push the first element of a stack to the top of second stack

void	push_stack(struct s_stack **stack_from, struct s_stack **stack_to)
{
	int	firstelement;

	if (*stack_from == NULL)
	{
		ft_printf("Stack is empty\n");
		return ;
	}
	firstelement = (*stack_from)->data;
	*stack_from = pop(*stack_from);
	*stack_to = push(*stack_to, firstelement);
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
