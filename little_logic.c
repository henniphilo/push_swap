/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_logic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:40:12 by hwiemann          #+#    #+#             */
/*   Updated: 2024/02/03 17:54:09 by hwiemann         ###   ########.fr       */
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
	//ft_printf("min is: %d\n", min);
	return(min);
}

void	put_on_top_a(struct s_stack **stack, int num)
{
	struct s_stack	*head;
	int	num_pos;
	int	size;

	head = *stack;
	num_pos = find_num_position(*stack, num);
	size = stacksize(*stack);

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

int	find_num_position(struct s_stack *stack, int num)
{
	struct s_stack	*head;
	int	current_pos;
	int	num_pos;

	head = stack;
	num_pos = 0;
	current_pos = 0;

	while(head != NULL)
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
	while((*stack_a)->next != NULL)
	{
		push_min(stack_a, stack_b);
	}
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



void	sort_back(struct s_stack *stack_a, struct s_stack *stack_b)
{
	while(stack_b)
	{
		pa(&stack_a, &stack_b);
	}

}

void	little_logic(struct s_stack *stack_a, struct s_stack *stack_b)
{
	sort(&stack_a, &stack_b);
	sort_back(stack_a, stack_b);

	ft_printf("Stack A nach sort: ");
 	printstack(stack_a);
	ft_printf("Stack B nach sort: ");
 	printstack(stack_b);
}

void	sort_three(struct s_stack **stack_a)
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
		if(check_sort(*stack_a) == 1)
				sa(stack_a);
	}
	else
	{
		if((*stack_a)->next->data == min)
			sa(stack_a);
		else
			rra(stack_a);
	}

	ft_printf("Stack A nach sort 3: ");
 	printstack(*stack_a);

}

void	sort_five(struct s_stack **stack_a, struct s_stack **stack_b)
{
	struct s_stack	*head;

	head = *stack_a;

	push_min(&head, stack_b);
	push_min(&head, stack_b);
	sort_three(&head);

	pa(&head, stack_b);
	pa(&head, stack_b);

	// ft_printf("Stack A nach sort 5: ");
 	// printstack(*stack_a);
	// ft_printf("Stack B nach sort 5: ");
 	// printstack(*stack_b);
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

void	sort_hundert(struct s_stack **stack_a, struct s_stack **stack_b)
{
	int	size;
	//int	min_pos;
	int	part;
	struct s_stack	*head;

	head = *stack_a;

	pb(&head, stack_b);
	pb(&head, stack_b);

	while(head->next != NULL)
	{
		size = stacksize(head);
	// ft_printf("stack size: %d\n", size);
		part = (size / 4 + size % 4);
		//min_pos = find_min_in_part(head, part);
			push_part_min(&head, stack_b, part);
			check_max(stack_b);
	}

	// ft_printf("stack a nach min part push:");
	// printstack(*stack_a);

	// ft_printf("stack b nach min part push:");
	// printstack(*stack_b);
}


int	check_max(struct s_stack **stack)
{
	int	min;
	int max;
	struct s_stack	*head;

	head = *stack;
	min = find_min(head);
	max = find_max(head);

	if(head->data == min)
		{
			rb(stack);
			if(check_reversed_order(*stack) == 1)
				sb(stack);
		}
	else if(head->data < max)
		{
			sb(stack);
				check_reversed_order(*stack);
		}
	return(0);
}

int	check_reversed_order(struct s_stack *stack)
{
	struct s_stack	*head;

	head = stack;
	while(head->next)
	{
		if(head->data < head->next->data)
			{
				// ft_printf("stack is not sorted\n");
				return(1);
			}
		head = head->next;
	}
	ft_printf("stack is reverse sorted\n");
	return(0);
}

void	hin_her(struct s_stack **stack_a, struct s_stack **stack_b)
{
	int	max;
	int	size;
	int	current;

	size = stacksize(*stack_a);
	max = find_max(*stack_a);
	current = 0;

	while(stack_a && current != size)
	{
		if((*stack_a)->data > (max/2 + max % 2))
		{
			pb(stack_a, stack_b);
		}
		else
		{
			ra(stack_a);
		}
		current++;
	}
}
