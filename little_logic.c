/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_logic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:40:12 by hwiemann          #+#    #+#             */
/*   Updated: 2024/01/30 19:27:34 by hwiemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// creating sorting logics for 5 and less elements
// funktion that looks for the minimum and then cyc;ing through until you have it and push it to stack b
// then looking again for the net minimum, rotate and push to b -> creates reversed order and then pushing it back
// kleinste oder groesste zahl suchen
// vergleichen ob nachvorne oder hinten rotieren sinnvoller ist


#include "pushswap.h"

int	find_min(struct s_stack *stack)
{
	struct s_stack	*head;
	int	min;

	head = stack;
	min = head->data;

	while(head != NULL)
	{
		if(head->data < min)
		{
			min = head->data;
		}
		head = head->next;
	}
	return(min);
}

int	find_min_position(struct s_stack *stack)
{
	struct s_stack	*head;
	int	min;
	int	current_pos;
	int	min_pos;

	head = stack;
	min = head->data;
	min_pos = 0;
	current_pos = 0;

	while(head != NULL)
	{
		if(head->data < min)
		{
			min = head->data;
			min_pos = current_pos;
		}
		head = head->next;
		current_pos++;
	}
	return(min_pos);
}

int	find_max(struct s_stack *stack)
{
	struct s_stack	*head;
	int	max;

	head = stack;
	max = head->data;

	while(head != NULL)
	{
		if(head->data > max)
		{
			max = head->data;
		}
		head = head->next;
	}
//	ft_printf("max is <%d>\n", max);
	return(max);
}

void	sort(struct s_stack **stack_a, struct s_stack **stack_b)
{
	int	min;
	int	min_pos;
	int	size;

	// ft_printf("kleinstes element: >%d<\n", find_min(*stack_a));

	while((*stack_a)->next != NULL)
	{
		min = find_min(*stack_a);
		min_pos = find_min_position(*stack_a);
		size = stacksize(*stack_a);

	//	ft_printf("position of min: %d\n", min_pos);
		if (min_pos == 1)
		{
			sa(stack_a);
		}
		else if(min_pos <= (size/2))
		{
			while (*stack_a != NULL && (*stack_a)->data != min )
			{
				ra(&*stack_a);
			}
		}
		else if(min_pos > (size/2))
		{
			while (*stack_a != NULL && (*stack_a)->data != min )
			{
				rra(&*stack_a);
			}
		}
		if ((*stack_a)->data == min)
		{
			pb(&*stack_a, stack_b);
		}
		// ft_printf("moving to next element\n");
	 }
	//  ft_printf("Stack A after sort: ");
	// printstack(*stack_a);
	// ft_printf("Stack B after sort: ");
 	// printstack(*stack_b);
}

void	sort_back(struct s_stack *stack_a, struct s_stack *stack_b)
{
	while(stack_b)
	{
		pa(&stack_a, &stack_b);
	}
	// ft_printf("Stack A after sort_back: ");
	// printstack(stack_a);
	// ft_printf("Stack B after sort_back: ");
 	// printstack(stack_b);
}

void	little_logic(struct s_stack *stack_a, struct s_stack *stack_b)
{
	sort(&stack_a, &stack_b);
	sort_back(stack_a, stack_b);
}

struct s_stack	*sort_three(struct s_stack **stack_a)
{
	int	min;
	int	max;

	min = find_min(*stack_a);
	max = find_max(*stack_a);

	if((*stack_a)->data == min)
	{
		rra(stack_a);
		sa(stack_a);
	}
	else if((*stack_a)->data == max)
	{
		ra(stack_a);
		if(!(check_sort(*stack_a)))
			sa(stack_a);
	}
	else
	{
		if((*stack_a)->next->data == min)
			sa(stack_a);
		else
			rra(stack_a);
	}
	ft_printf("Stack A after sort_three: ");
	printstack(*stack_a);

	return(*stack_a);
}
