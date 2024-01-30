/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 13:43:35 by hwiemann          #+#    #+#             */
/*   Updated: 2024/01/30 11:43:35 by hwiemann         ###   ########.fr       */
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

	ft_printf(">%d< was pushed\n", (*stack_to)->data);
	printstack(stack_from);
	printstack(*stack_to);
	return(stack_from);
}

//pa | push the first element of stack b to the top of stack a

struct s_stack	*pa(struct s_stack **stack_a, struct s_stack **stack_b)
{
	*stack_b = push_stack(*stack_b, stack_a);
	/*if(*stack_b != NULL)
		return(1);*/
	ft_printf("pa\n");
	//ft_putendl_fd("pa", 1);
	return(*stack_b);
}

// pb | push the first element of stack a to the top of stack b

struct s_stack	*pb(struct s_stack **stack_a, struct s_stack **stack_b)
{
	*stack_a = push_stack(*stack_a, stack_b);
/*	if(*stack_a != NULL)
		return(1);*/
	ft_printf("pb\n");
//	ft_putendl_fd("pb", 1);
	return(*stack_a);
}

//swapping the first to elements of a stack

struct s_stack	*swap_stack(struct s_stack **stack)
{
	int	firstelement;
	int	secondelement;

	if(*stack == NULL)
	{
		ft_printf("Stack is empty no swapping");
		return(NULL);
	}

	firstelement = (*stack)->data;
	*stack = pop(*stack);
	if(*stack == NULL)
	{
		ft_printf("Stack has not enaugh elements to swap");
		return(NULL);
	}
	secondelement = (*stack)->data;
	*stack = pop(*stack);

	*stack = push(*stack, firstelement);
	*stack = push(*stack, secondelement);

	ft_printf("swap\n");

	(*stack)->data = secondelement;

	return(*stack);
}

int	sa(struct s_stack **stack_a)
{
	if(swap_stack(stack_a) != 0)
		return(1);
	ft_printf("sa");
	//ft_putendl_fd("sa", 1);
	return(0);
}

int	sb(struct s_stack **stack_b)
{
	if(swap_stack(stack_b) != 0)
		return(1);
	ft_printf("sb");
	//ft_putendl_fd("sb", 1);
	return(0);
}

int	ss(struct s_stack **stack_a, struct s_stack **stack_b)
{
	swap_stack(stack_a);
	swap_stack(stack_b);
	ft_printf("ss");
//	ft_putendl_fd("ss", 1);
	return(0);
}

//rotate stack moves first element to the bottom

struct s_stack *rota_stack(struct s_stack **head)
{
	struct s_stack	*current;
	struct s_stack	*new_top;

	current = *head;
	new_top = (*head)->next;

	if(*head == NULL || (*head)->next == NULL)
	{
		ft_printf("no rotation possible");
		return(*head);
	}
	while(current->next != NULL)
	{
		current = current->next;
	}
	(*head)->next = NULL;
	current->next = *head;
//head updaten
	*head = new_top;
	return (*head);
}

int	ra(struct s_stack **stack_a)
{
	rota_stack(stack_a);
		//return(1);
	ft_printf("ra\n");
	//ft_printf("stack killer\n");
//	ft_putendl_fd("ra", 1);
	return(0);
}

int	rb(struct s_stack **stack_b)
{
	if(rota_stack(stack_b) != 0)
		return(1);
	ft_printf("rb");
	//ft_putendl_fd("rb", 1);
	return(0);
}

int	rr(struct s_stack **stack_a, struct s_stack **stack_b)
{
	rota_stack(stack_a);
	rota_stack(stack_b);
	ft_printf("rr");
	//ft_putendl_fd("rr", 1);
	return(0);
}

//reverse rotation move the last element to the top

struct s_stack *reverse_rotation(struct s_stack **stack)
{
	struct s_stack	*last;
	struct s_stack	*top;

	top = NULL;
	last = *stack;

	if(*stack == NULL || (*stack)->next == NULL)
	{
		ft_printf("stack empty no reverse rota");
		return(*stack);
	}

	while(last->next != NULL)
	{
		top = last;
		last = last->next;
	}
	top->next = NULL;
	last->next = *stack;

	*stack = last;

	return(*stack);
}

int	rra(struct s_stack **stack_a)
{
	if(reverse_rotation(stack_a) != 0)
		return(1);
	ft_printf("rra");
	ft_putendl_fd("rra", 1);
	return(0);
}

int	rrb(struct s_stack **stack_b)
{
	if(reverse_rotation(stack_b) != 0)
		return(1);
	ft_printf("rrb");
	ft_putendl_fd("rrb", 1);
	return(0);
}

int	rrr(struct s_stack **stack_a, struct s_stack **stack_b)
{
	reverse_rotation(stack_a);
	reverse_rotation(stack_b);
	ft_printf("rrr");
	ft_putendl_fd("rrr", 1);
	return(0);
}

