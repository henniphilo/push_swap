/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigger_logic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:21:51 by hwiemann          #+#    #+#             */
/*   Updated: 2024/02/09 17:23:19 by hwiemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"


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

	// ft_printf("Stack A before little logic: ");
 	// printstack(*stack_a);
	// ft_printf("Stack B before little logic: ");
 	// printstack(*stack_b);

	head_b = *stack_b;
	head_a = *stack_a;

	sort(&head_a, &head_b);

	// ft_printf("Stack A nach sort function: ");
 	// printstack(head_a);
	// ft_printf("Stack B nach sort function: ");
 	// printstack(head_b);

	sort_back(&head_a, &head_b);

}

//kleineres drittel rueber auf b
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
	//med should be part nicht bezogen auf value sondern auf elementnummer
	med = (max / 2 + max % 2);
	current_pos = 0;

	while(head && current_pos < size)
	{
		ft_printf("index is: %d \n", head->index);
		if(head->data <= med)
		{
			pb(&head, &head_b);
		}
		else
		{
			//ft_printf("hier\n");
			ra(&head);
		}
		current_pos++;
	}
		// ft_printf("Stack A  hin her head: ");
 		// 	printstack(head);
		// 	ft_printf("Stack B  hin her head: ");
 		// 	printstack(head_b);

	*stack_a = head;
	*stack_b = head_b;

// 	ft_printf("Stack A  hin her head: ");
//  			printstack(head);
// 			ft_printf("Stack B  hin her head: ");
//  			printstack(head_b);
}

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


void	push_max(struct s_stack **stack_a, struct s_stack **stack_b)
{
	struct s_stack	*head;
	struct s_stack	*head_b;
	int	max;
	int	pos;
	int	size;

	head = *stack_a;
	head_b = *stack_b;

	// ft_printf("stack b is: \n");
	// printstack(head_b);

	max = find_max(head_b);
	//ft_printf("max is: %d\n", max);

	if (head_b->data == max)
		{
			pa(&head, &head_b);
		}
	max = find_max(head_b);
//	ft_printf("max is: %d\n", max);
	size = stacksize(head_b);
	pos = find_num_position(head_b, max, size);
	//ft_printf("pos is: %d\n", pos);

	if (pos == 1)
		{
			sb(&head_b);
		}
		else if(pos <= (size/2 + size % 2))
		{
			while (head_b != NULL && head_b->data != max )
			{
				rb(&head_b);
			//	ft_printf("hi\n");
			}
			pa(&head, &head_b);


		}
		else if(head_b && (pos > (size/2 + size % 2)))
		{
			while (head_b != NULL && head_b->data != max )
			{
				rrb(&head_b);
			}
		}

	*stack_a = head;
	*stack_b = head_b;
}

void	sort_max(struct s_stack **stack_a, struct s_stack **stack_b)
{
	struct s_stack	*head;
	struct s_stack	*head_b;
	//int	med;

	head = *stack_a;
	head_b = *stack_b;


	// ft_printf("Stack A:");
	// printstack(head);
	// ft_printf("Stack B:");
	// printstack(head_b);

	while(head_b)
	{
		push_max(&head, &head_b);
	// 	ft_printf("Stack A:");
	// printstack(head);
	// ft_printf("Stack B:");
	// printstack(head_b);
	// 	ft_printf("med is: %d, und data head is: %d \n", med, head->data);

	}

	*stack_a = head;
	*stack_b = head_b;
}

//ueberpruefen was von b kommt und das nochmal aufteilen in halfte runter,
void	chunky(struct s_stack **stack, int max_b)
{
	struct s_stack	*head;

	head = *stack;

	if(head && (head->data <= (max_b / 2)))
				ra(&head);

	*stack = head;
}


//hier an logic arbeiten

void	reverse_compare(struct s_stack **stack_a, struct s_stack **stack_b, int part)
{
	struct s_stack	*head;
	struct s_stack	*head_b;
	int	current;
	int	med;

	head = *stack_a;
	head_b = *stack_b;
	current = 0;

	med = (find_max(head) / 2);
	//ft_printf("med is %d\n", med);

	//ft_printf("Stack A:");
	//printstack(head);

	if (head != NULL)
	{
		//rra(&head);
		while(head && current <= part)
		{
			ft_printf("part is %d \n", part);
			ft_printf("current is %d \n", current);

			rra(&head);
				if(head && (head->data > head->next->data) && (head->data > med))
					{
						pb(&head, &head_b);
					}
			current++;
		}
	}

	*stack_a = head;
	*stack_b = head_b;
}

void	wtf(struct s_stack **stack_a, struct s_stack **stack_b)
{
	struct s_stack	*head;
	struct s_stack	*head_b;
	int	size;
	int max;

	head = *stack_a;
	head_b = *stack_b;
	max = find_max(head);

	hin_her(&head, &head_b);
	size = stacksize(head);

	sort_max(&head, &head_b);

//size would be good if part of stack
	ft_printf("size is %d \n", size);

	 reverse_compare(&head, &head_b, size - 1);

	sort_max(&head, &head_b);

	while(head->data != max)
	{
		rra(&head);
	}
	ra(&head);

	//smart_top(&head, &head_b);

	//presort_back(&head, &head_b);

	*stack_a = head;
	*stack_b = head_b;
}
