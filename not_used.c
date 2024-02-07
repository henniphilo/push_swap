#include "pushswap.h"

//was von b kommt nach unten sortieren wenn es kleiner ist als das naechste

int	stackempty(struct s_stack *stack)
{
	return (stack->next == NULL);
}

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
//	ft_printf("size b: %d\n", size_b);

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

//	ft_printf("Stack A  smart head: ");
 		// printstack(head_a);
		// ft_printf("Stack B smart head: ");
 		// printstack(head_b);

	*stack_a = head_a;
	*stack_b = head_b;
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
