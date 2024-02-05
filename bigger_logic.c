/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigger_logic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:21:51 by hwiemann          #+#    #+#             */
/*   Updated: 2024/02/05 15:54:49 by hwiemann         ###   ########.fr       */
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

	ft_printf("Stack A before sort pa: ");
 	printstack(head_a);
	ft_printf("Stack B before sort pa: ");
 	printstack(head_b);

	while(head_b)
	{
		pa(&head_a, &head_b);
	}

	ft_printf("Stack A after sort pa: ");
 	printstack(head_a);
	ft_printf("Stack B after sort pa: ");
 	printstack(head_b);

	stack_a = &head_a;
	stack_b = &head_b;

	ft_printf("Stack A after back to stack: ");
 	printstack(*stack_a);
	ft_printf("Stack B after back to stack: ");
 	printstack(*stack_b);
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

	// ft_printf("Stack A nach head assigned: ");
 	// printstack(head_a);
	// ft_printf("Stack B nach head assigned: ");
 	// printstack(head_b);

	sort(&head_a, &head_b);

	ft_printf("Stack A nach sort function: ");
 	printstack(head_a);
	ft_printf("Stack B nach sort function: ");
 	printstack(head_b);

	sort_back(&head_a, &head_b);

	// ft_printf("here faulty: \n");
	// ft_printf("Stack A nach little logic: ");
 	// printstack(head_a);
	// ft_printf("Stack B nach little logic: ");
 	// printstack(head_b);
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

	// ft_printf("Stack A before hin her: ");
 	// printstack(*stack_a);
	// ft_printf("Stack B before hin her: ");
 	// printstack(*stack_b);

	size = stacksize(*stack_a);
	head = *stack_a;
	head_b = *stack_b;
	max = find_max(*stack_a);
	med = (max / 2 + max % 2);
	current_pos = 0;

	ft_printf("Stack A nach head assigned: ");
 	printstack(head);
	ft_printf("Stack B nach head assigned: ");
 	printstack(head_b);

	ft_printf("med ist %d\n", med);

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

	stack_a = &head;
	*stack_b = head_b;

	ft_printf("Stack A after hin her stack: ");
 			printstack(*stack_a);
			ft_printf("Stack B after hin her stack: ");
 			printstack(*stack_b);
}

//hier sind die pointer nicht richtig upgedatet warum????

void	presort_back(struct s_stack **stack_a, struct s_stack **stack_b)
{
	//int	size_b;
	//int	min_b;
	//int	current_pos;
	struct s_stack	*head_a;
	struct s_stack	*head_b;

	//current_pos = 0;

	//size_b = stacksize(*stack_b);

	ft_printf("Stack A before presort assign: ");
 	printstack(*stack_a);
	ft_printf("Stack B before presort assign: ");
 	printstack(*stack_b);

	head_b = *stack_b;
	head_a = *stack_a;


			ft_printf("Stack A before presort: ");
 			printstack(head_a);
			ft_printf("Stack B before presort: ");
 			printstack(head_b);

	// while(head_b && current_pos < size_b)
	// {
	// 	min_b = find_min(head_b);
	// 	put_on_top_b(&head_b, min_b);
	// 	//if(head_b->data == min_b)
		ft_printf("ist min wird pa\n");
		// pa(&head_a, &head_b);
		pa(&head_a, &head_b);
	// 		break;
	// 	current_pos++;
	// }
		ft_printf("Stack A after presort: ");
 			printstack(head_a);
			ft_printf("Stack B after presort: ");
 			printstack(head_b);

	*stack_a = head_a;
	*stack_b = head_b;
}

void	wtf(struct s_stack **stack_a, struct s_stack **stack_b)
{
	struct s_stack	*head;
	struct s_stack	*head_b;

	ft_printf("Stack A before wtf: ");
 	printstack(*stack_a);
	ft_printf("Stack B before wtf: ");
 	printstack(*stack_b);

	head = *stack_a;
	head_b = *stack_b;


	hin_her(&head, &head_b);

	// ft_printf("Stack A after wtf: ");
 	// printstack(*stack_a);
	// ft_printf("Stack B after wtf: ");
 	// printstack(*stack_b);


	ft_printf("Stack A in wtf after hin her: ");
 	printstack(head);
	ft_printf("Stack B in wtf after hin her: ");
 	printstack(head_b);

	presort_back(&head, &head_b);

	*stack_a = head;
	*stack_b = head_b;
}
