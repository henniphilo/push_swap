/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 13:43:35 by hwiemann          #+#    #+#             */
/*   Updated: 2024/01/24 12:39:19 by hwiemann         ###   ########.fr       */
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

int	pa(struct s_stack *stack_a, struct s_stack *stack_b)
{
	if(push_stack(stack_b, &stack_a) != 0)
		return(1);
	ft_printf("pa");
	ft_putendl_fd("pa", 1);
	return(0);
}

int	pb(struct s_stack *stack_a, struct s_stack *stack_b)
{
	if(push_stack(stack_a, &stack_b) != 0)
		return(1);
	ft_printf("pb");
	ft_putendl_fd("pb", 1);
	return(0);
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

int	sa(struct s_stack *stack_a)
{
	if(swap_stack(stack_a) != 0)
		return(1);
	ft_printf("sa");
	ft_putendl_fd("sa", 1);
	return(0);
}

int	sb(struct s_stack *stack_b)
{
	if(swap_stack(stack_b) != 0)
		return(1);
	ft_printf("sb");
	ft_putendl_fd("sb", 1);
	return(0);
}

int	ss(struct s_stack *stack_a, struct s_stack *stack_b)
{
	swap_stack(stack_a);
	swap_stack(stack_b);
	ft_printf("ss");
	ft_putendl_fd("ss", 1);
	return(0);
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

int	ra(struct s_stack *stack_a)
{
	if(rota_stack(stack_a) != 0)
		return(1);
	ft_printf("ra");
	ft_putendl_fd("ra", 1);
	return(0);
}

int	rb(struct s_stack *stack_b)
{
	if(rota_stack(stack_b) != 0)
		return(1);
	ft_printf("rb");
	ft_putendl_fd("rb", 1);
	return(0);
}

int	rr(struct s_stack *stack_a, struct s_stack *stack_b)
{
	rota_stack(stack_a);
	rota_stack(stack_b);
	ft_printf("rr");
	ft_putendl_fd("rr", 1);
	return(0);
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

int	rra(struct s_stack *stack_a)
{
	if(reverse_rotation(stack_a) != 0)
		return(1);
	ft_printf("rra");
	ft_putendl_fd("rra", 1);
	return(0);
}

int	rrb(struct s_stack *stack_b)
{
	if(reverse_rotation(stack_b) != 0)
		return(1);
	ft_printf("rrb");
	ft_putendl_fd("rrb", 1);
	return(0);
}

int	rrr(struct s_stack *stack_a, struct s_stack *stack_b)
{
	reverse_rotation(stack_a);
	reverse_rotation(stack_b);
	ft_printf("rrr");
	ft_putendl_fd("rrr", 1);
	return(0);
}

