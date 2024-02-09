/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 13:43:35 by hwiemann          #+#    #+#             */
/*   Updated: 2024/02/09 15:46:31 by hwiemann         ###   ########.fr       */
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

//push the first element of a stack to the top of second stack

void	push_stack(struct s_stack **stack_from, struct s_stack **stack_to)
{
	int	firstelement;

	if(*stack_from == NULL)
	{
		ft_printf("Stack is empty\n");
		return;
	}

	firstelement = (*stack_from)->data;
	*stack_from = pop(*stack_from);
	*stack_to = push(*stack_to, firstelement);

	// ft_printf(">%d< was pushed\n", (*stack_to)->data);
	// printstack(stack_from);
	// printstack(*stack_to);
	/*return(stack_from);*/
}

//pa | push the first element of stack b to the top of stack a

void	pa(struct s_stack **stack_a, struct s_stack **stack_b)
{
	if(*stack_b != NULL)
	{
		push_stack(stack_b, stack_a);
		ft_printf("pa\n");
	}
}

// pb | push the first element of stack a to the top of stack b

void	pb(struct s_stack **stack_a, struct s_stack **stack_b)
{
	if(*stack_b != NULL)
	{
		push_stack(stack_a, stack_b);
		ft_printf("pb\n");
	}
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

	//ft_printf("swap\n");

	(*stack)->data = secondelement;

	return(*stack);
}

struct s_stack	*sa(struct s_stack **stack_a)
{
	if(*stack_a == NULL)
	{
		return(*stack_a);
	}
	swap_stack(stack_a);
	ft_printf("sa\n");
	return(*stack_a);
}

struct s_stack	*sb(struct s_stack **stack_b)
{
	if(*stack_b == NULL)
	{
		return(*stack_b);
	}
	swap_stack(stack_b);
		ft_printf("sb\n");
	return(*stack_b);
}

int	ss(struct s_stack **stack_a, struct s_stack **stack_b)
{
	if(*stack_a == NULL || *stack_b == NULL)
	{
		return(1);
	}
	swap_stack(stack_a);
	swap_stack(stack_b);
	ft_printf("ss\n");
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
		ft_printf("no rotation possible\n");
		return(*head);
	//	exit(1);
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

struct s_stack	*ra(struct s_stack **stack_a)
{
	if(*stack_a == NULL)
	{
		return(*stack_a);
	}
	rota_stack(stack_a);
	ft_printf("ra\n");
	return(*stack_a);
}

struct s_stack	*rb(struct s_stack **stack_b)
{
	if(*stack_b == NULL)
	{
		return(*stack_b);
	}
	rota_stack(stack_b);
	ft_printf("rb\n");
	//ft_putendl_fd("rb", 1);
	return(*stack_b);
}

int	rr(struct s_stack **stack_a, struct s_stack **stack_b)
{
	if(*stack_a == NULL || *stack_b == NULL)
	{
		return(1);
	}
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

struct s_stack	*rra(struct s_stack **stack_a)
{
	if(*stack_a == NULL)
	{
		return(*stack_a);
	}
	reverse_rotation(stack_a);
	ft_printf("rra\n");
	return(*stack_a);
}
//rrb | reverse rotate the stack b, move the last element to the top.
struct s_stack	*rrb(struct s_stack **stack_b)
{
	if(*stack_b == NULL)
	{
		return(*stack_b);
	}
	reverse_rotation(stack_b);
	ft_printf("rrb\n");
	return(*stack_b);
}

//rra | reverse rotate the stack a, move the last element to the top.
int	rrr(struct s_stack **stack_a, struct s_stack **stack_b)
{
	if(*stack_a == NULL || *stack_b == NULL)
	{
		return(1);
	}
	reverse_rotation(stack_a);
	reverse_rotation(stack_b);
	ft_printf("rrr");
//	ft_putendl_fd("rrr", 1);
	return(0);
}

