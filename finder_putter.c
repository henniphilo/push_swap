/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finder_putter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:25:37 by hwiemann          #+#    #+#             */
/*   Updated: 2024/02/05 12:27:34 by hwiemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	push_part_min(struct s_stack **stack_a, struct s_stack **stack_b, int part)
{
	//int	min = find_min(*stack_a);
	//int	size = stacksize(*stack_a);
	int	current_pos;
	int	min_pos = find_min_in_part(*stack_a, part);

	current_pos = 0;

	//	ft_printf("position of min: %d\n", min_pos);
		if (min_pos == 1)
		{
			sa(stack_a);
		}
		else
		{
			while (*stack_a && current_pos < min_pos )
			{
				ra(&*stack_a);
					current_pos++;
			}
		}
		if (current_pos == min_pos)
		{
			pb(&*stack_a, stack_b);
		}
}

int	find_min(struct s_stack *stack)
{
	struct s_stack	*head;
	int	min;

	head = stack;
	min = head->data;

	if (stack == NULL)
	{
		return(1);
	}

	while(head != NULL)
	{
		if(head->data < min)
		{
			min = head->data;
		}
		head = head->next;
	}
	ft_printf("min is: %d\n", min);
	return(min);
}


int	find_num_position(struct s_stack *stack, int num, int part)
{
	struct s_stack	*head;
	int	current_pos;
	int	num_pos;

	head = stack;
	num_pos = 0;
	current_pos = 0;

	if(stack == NULL)
		{
			return(1);
		}

	while(head != NULL && current_pos < part)
	{
		if(head->data == num)
		{
			num = head->data;
			num_pos = current_pos;
		}
		head = head->next;
		current_pos++;
	}
	ft_printf("pos of num:%d\n", num_pos);
	return(num_pos);
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

	if(stack == NULL)
		{
			return(1);
		}

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

	if(stack == NULL)
		{
			return(1);
		}

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

int	find_min_in_part(struct s_stack *stack, int part)
{
	struct s_stack	*head;
	int	min;
	int	current_pos;
	int	min_pos;

	head = stack;
	min = head->data;
	min_pos = 0;
	current_pos = 0;

	//ft_printf("part ist: %d\n", part);

	while(stack && current_pos < part)
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

void	push_min(struct s_stack **stack_a, struct s_stack **stack_b)
{
		int	min = find_min(*stack_a);
		int	min_pos = find_min_position(*stack_a);
		int	size = stacksize(*stack_a);

	//	ft_printf("position of min: %d\n", min_pos);
		if (min_pos == 1)
		{
			sa(stack_a);
		}
		else if(min_pos <= (size/2 + size % 2))
		{
			while (*stack_a != NULL && (*stack_a)->data != min )
			{
				ra(&*stack_a);
			}
		}
		else if(min_pos > (size/2 + size % 2) )
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
}


void	put_on_top_a(struct s_stack **stack, int num)
{
	struct s_stack	*head;
	int	num_pos;
	int	size;

	head = *stack;
	size = stacksize(*stack);
	num_pos = find_num_position(*stack, num, size);

	if(stack == NULL)
		{
			return;
		}

	if(num_pos == 1)
	{
		sa(stack);
	}
	else if(num_pos <= (size/2 + size % 2))
	{
		while (*stack != NULL && (*stack)->data != num )
		{
			ra(stack);
		}
	}
	else if(num_pos > (size/2 + size % 2) )
		{
			while (*stack != NULL && (*stack)->data != num)
			{
				rra(stack);
			}
		}
}

void	put_on_top_b(struct s_stack **stack, int num)
{
	struct s_stack	*head;
	int	num_pos;
	int	size;

	head = *stack;
	size = stacksize(*stack);
	num_pos = find_num_position(*stack, num, size);

	if(stack == NULL)
		{
			return;
		}

	if(num_pos == 1)
	{
		sb(stack);
	}
	else if(num_pos <= (size/2 + size % 2))
	{
		while (*stack != NULL && (*stack)->data != num )
		{
			rb(stack);
		}
	}
	else if(num_pos > (size/2 + size % 2) )
		{
			while (*stack != NULL && (*stack)->data != num)
			{
				rrb(stack);
			}
		}
}
