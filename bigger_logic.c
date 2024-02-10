/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigger_logic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:21:51 by hwiemann          #+#    #+#             */
/*   Updated: 2024/02/10 17:16:27 by hwiemann         ###   ########.fr       */
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

	head_b = *stack_b;
	head_a = *stack_a;

	sort(&head_a, &head_b);
	sort_back(&head_a, &head_b);
}

void	hin_her(struct s_stack **stack_a, struct s_stack **stack_b, int chunk)
{
	struct s_stack	*head;
	struct s_stack	*head_b;
	int	size;
	int	current_pos;

	size = stacksize(*stack_a);
	head = *stack_a;
	head_b = *stack_b;
	current_pos = 0;

	while(head && current_pos < size)
	{
		if(head->index <= chunk)
		{
			pb(&head, &head_b);
		}
		else
		{
			ra(&head);
		}
		current_pos++;
	}
	*stack_a = head;
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

	max = find_max(head_b);

	if (head_b->data == max)
		{
			pa(&head, &head_b);
		}
	max = find_max(head_b);
	size = stacksize(head_b);
	pos = find_num_position(head_b, max, size);

	if (pos == 1)
		{
			sb(&head_b);
		}
		else if(pos <= (size/2 + size % 2))
		{
			while (head_b != NULL && head_b->data != max )
			{
				rb(&head_b);
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

	head = *stack_a;
	head_b = *stack_b;

	while(head_b)
	{
		push_max(&head, &head_b);
	}

	*stack_a = head;
	*stack_b = head_b;
}

int	chunky(int argc)
{
	int	chunk;

	chunk = 0;

	if((argc - 1) >= 6 && (argc - 1) <= 100)
	{
		chunk = ((argc - 1) / 5 + (argc - 1) % 5);
	}
	else if((argc - 1) >= 101 && (argc - 1) <= 500)
	{
		chunk = ((argc - 1) / 11 + (argc - 1) % 11);
	}
	else
		chunk = (argc - 1);

	ft_printf("chunk is: %d\n", chunk);

	return(chunk);
}

void	wtf(struct s_stack **stack_a, struct s_stack **stack_b, int argc)
{
	struct s_stack	*head;
	struct s_stack	*head_b;
	int	size;
	int	i;
	int	chunk;


	head = *stack_a;
	head_b = *stack_b;
	chunk = chunky(argc);
	i = 0;

	if((argc - 1) >= 6 && (argc - 1) <= 100)
	{
		while(head && i != 6)
		{
			hin_her(&head, &head_b, chunk * i + 1);
			i++;
		}
	}
	else if((argc - 1) >= 101 && (argc - 1) <= 500)
	{
		while(head && i != 12)
		{
			hin_her(&head, &head_b, chunk * i + 1);
			i++;
		}
	}
	else
		hin_her(&head, &head_b, chunk);

	size = stacksize(head);
	sort_max(&head, &head_b);

	*stack_a = head;
	*stack_b = head_b;
}
