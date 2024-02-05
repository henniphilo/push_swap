/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigger_logic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:21:51 by hwiemann          #+#    #+#             */
/*   Updated: 2024/02/05 20:16:24 by hwiemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"


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

void	sort(struct s_stack **stack_a, struct s_stack **stack_b)
{
	while((*stack_a)->next != NULL)
	{
		push_min(stack_a, stack_b);
	}
}

void	sort_back(struct s_stack **stack_a, struct s_stack **stack_b)
{
	struct s_stack	*head_a;
	struct s_stack	*head_b;

	head_a = *stack_a;
	head_b = *stack_b;

	while(head_b)
	{
		pa(&head_a, &head_b);
	}

	*stack_a = head_a;
	*stack_b = head_b;

}

void	little_logic(struct s_stack **stack_a, struct s_stack **stack_b)
{
	struct s_stack	*head_a;
	struct s_stack	*head_b;

	ft_printf("Stack A before little logic: ");
 	printstack(*stack_a);
	ft_printf("Stack B before little logic: ");
 	printstack(*stack_b);

	head_b = *stack_b;
	head_a = *stack_a;

	sort(&head_a, &head_b);

	ft_printf("Stack A nach sort function: ");
 	printstack(head_a);
	ft_printf("Stack B nach sort function: ");
 	printstack(head_b);

	sort_back(&head_a, &head_b);

}

//grosse halfte rueber auf b
void	hin_her(struct s_stack **stack_a, struct s_stack **stack_b)
{
	int	max;
	int	size;
	struct s_stack	*head;
	struct s_stack	*head_b;
	int	med;
	int	current_pos;

	size = stacksize(*stack_a);
	head = *stack_a;
	head_b = *stack_b;
	max = find_max(*stack_a);
	med = (max / 2 + max % 2);
	current_pos = 0;

	while(head && current_pos < size)
	{
		//ft_printf("betritt loop\n");
		if(head->data >= med)
		{
		//	ft_printf("schiebt auf b\n");
			pb(&head, &head_b);
		}
		else
		{
		//	ft_printf("hier\n");
			ra(&head);
		}
		current_pos++;
	}
		ft_printf("Stack A  hin her head: ");
 			printstack(head);
			ft_printf("Stack B  hin her head: ");
 			printstack(head_b);

	*stack_a = head;
	*stack_b = head_b;

// 	ft_printf("Stack A  hin her head: ");
//  			printstack(head);
// 			ft_printf("Stack B  hin her head: ");
//  			printstack(head_b);
}

//hier sind die pointer nicht richtig upgedatet warum????

void	presort_back(struct s_stack **stack_a, struct s_stack **stack_b)
{
	int	size_b;
	int	min_b;
	int	current_pos;
	struct s_stack	*head_a;
	struct s_stack	*head_b;

	current_pos = 0;

	size_b = stacksize(*stack_b);

	head_b = *stack_b;
	head_a = *stack_a;

	while(head_b && current_pos < size_b)
	{
		min_b = find_min(head_b);
		put_on_top_b(&head_b, min_b);
		//if(head_b->data == min_b)
		pa(&head_a, &head_b);
	// 		break;
	 	current_pos++;
	}
		ft_printf("Stack A after presort: ");
 			printstack(head_a);
			ft_printf("Stack B after presort: ");
 			printstack(head_b);

	*stack_a = head_a;
	*stack_b = head_b;
}

//was von b kommt nach unten sortieren wenn es kleiner ist als das naechste

void	smart_top(struct s_stack **stack_a, struct s_stack **stack_b)
{
	struct s_stack	*head_a;
	struct s_stack	*head_b;
	int	size_b;
	int	current;

	head_a = *stack_a;
	head_b = *stack_b;

	size_b = stacksize(*stack_b);
	current = 0;
	ft_printf("size b: %d\n", size_b);

	sort_back(&head_a, &head_b);

	// ft_printf("Stack A after sort_back: ");
 	// 	printstack(head_a);
	// 	ft_printf("Stack B after sort_back: ");
 	// 	printstack(head_b);

	while(head_a && current <= (size_b))
		{
			if(head_a->data < head_a->next->data)
				ra(&head_a);
			else
				pb(&head_a, &head_b);
			current++;
			//ft_printf("current: %d\n", current);
		}

	ft_printf("Stack A  smart head: ");
 		printstack(head_a);
		ft_printf("Stack B smart head: ");
 		printstack(head_b);

	*stack_a = head_a;
	*stack_b = head_b;
}

void	push_max(struct s_stack **stack_a, struct s_stack **stack_b)
{
	struct s_stack	*head;
	struct s_stack	*head_b;
	int	max;
	int	pos;
	int	size;

	head = *stack_a;
	head_b = *stack_b;

	size = stacksize(*stack_b);

	max = find_max(head_b);
	pos = find_num_position(head_b, max, size);

		if (pos == 1)
		{
			sb(&head_b);
		}
		else if(pos <= (size/2 + size % 2))
		{
			{
				rb(&head_b);
				ft_printf("hi\n");
			}
		}
		else if(pos > (size/2 + size % 2) )
		{
			while (head_b != NULL && head_b->data != max )
			{
				rrb(&head_b);
			}
		}
		if (head_b->data == max)
		{
			pa(&head, &head_b);
		}
	*stack_a = head;
	*stack_b = head_b;
}

void	sort_max(struct s_stack **stack_a, struct s_stack **stack_b)
{
	while(stack_b)
	{
		push_max(stack_a, stack_b);
	}
}

void	wtf(struct s_stack **stack_a, struct s_stack **stack_b)
{
	struct s_stack	*head;
	struct s_stack	*head_b;

	head = *stack_a;
	head_b = *stack_b;

	hin_her(&head, &head_b);
	sort_max(&head, &head_b);

	//smart_top(&head, &head_b);

	//presort_back(&head, &head_b);

	*stack_a = head;
	*stack_b = head_b;
}
