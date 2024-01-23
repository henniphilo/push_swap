/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 13:43:35 by hwiemann          #+#    #+#             */
/*   Updated: 2024/01/23 17:06:32 by hwiemann         ###   ########.fr       */
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

//push the first element of a stack to the top of second stack

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

	ft_printf("push\n");
	return(stack_from);
}

//swapping the first to elements of a stack

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

//rotate stack moves first element to the bottom
/*
struct s_stack	*rotate_stack(struct s_stack *stack)
{
	int	firstelement;
	int	size;
	int	i;
	int	data;

	if (stack == NULL || stack->next == NULL)
	{
		ft_printf("stack empty, no rotation possible");
		return(0);
	}

	firstelement = stack->data;
	stack = pop(stack);
	size = stacksize(stack);

	ft_printf("stack size during rotate: %d\n", size);

	stack = push(stack, firstelement);
	if(size > 1)
	{
		i = 0;
		while(i < size + 1)
		{
			data = stack->data;
			stack = pop(stack);
			stack = push(stack, data);
			i++;
		}
	}
	return(stack);
} */

struct s_stack *rota_stack(struct s_stack *stack)
{
	struct s_stack	*current;
	struct s_stack	*new_top;

	current = stack;
	new_top = stack->next;

	if(stack == NULL || stack->next == NULL)
	{
		ft_printf("no rotation possible");
		return(stack);
	}
	while(current->next != NULL)
	{
		current = current->next;
	}
	stack->next = NULL;
	current->next = stack;

	return(new_top);
}

//reverse rotation move the last element to the top

struct s_stack *reverse_rotation(struct s_stack *stack)
{
	struct s_stack	*last;
	struct s_stack	*top;

	top = NULL;
	last = stack;

	if(stack == NULL || stack->next == NULL)
	{
		ft_printf("stack empty no reverse rota");
		return(stack);
	}

	while(last->next != NULL)
	{
		top = last;
		last = last->next;
	}
	top->next = NULL;
	last->next = stack;

	return(last);
}


