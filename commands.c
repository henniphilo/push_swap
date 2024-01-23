/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 13:43:35 by hwiemann          #+#    #+#             */
/*   Updated: 2024/01/23 10:53:13 by hwiemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

struct s_stack	*pop(struct s_stack *head)
{
	struct s_stack *newhead;

	if(head == NULL)
	{
		ft_printf("empty stack\n");
		return (0);
	}
	newhead = head->next;
	free(head);
	if(newhead != NULL)
	{
		newhead->prev = NULL;
	}
	return (newhead);
}

struct s_stack	*push(struct s_stack *head, int data)
{
	struct s_stack	*newnode;

	newnode = create_node(data);

	if(newnode == NULL)
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

struct s_stack ft_swap(struct s_stack *a, struct s_stack *b)
{
	struct s_stack	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
	ft_printf("swap\n");
	return(tmp);
}

// pb | push the first element of stack a to the top of stack b

struct s_stack	*push_stack(struct s_stack *stack_from, struct s_stack **stack_to)
{
	int	firstelement;

	if(stack_from == NULL)
	{
		ft_printf("StackA is empty");
		return(*stack_to);
	}

	firstelement = stack_from->data;
	stack_from = pop(stack_from);
	*stack_to = push(*stack_to, firstelement);

	ft_printf("pb\n");
	return(stack_from);
}

struct s_stack	*swap_stack(struct s_stack *stack)
{
	int	firstelement;
	int	secondelement;

	if(stack == NULL)
	{
		ft_printf("Stack is empty no swapping");
		return(NULL);
	}

	firstelement = stack->data;
	stack = pop(stack);
	if(stack == NULL)
	{
		ft_printf("Stack has not enaugh elements to swap");
		return(NULL);
	}
	secondelement = stack->data;
	stack = pop(stack);

	stack = push(stack, firstelement);
	stack = push(stack, secondelement);

	ft_printf("swap\n");
	return(stack);
}



/*
//swap first 2 elements in stackA
struct s_stack	*sa(struct s_stack *stackA)
{

} */

