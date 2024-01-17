/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 13:43:35 by hwiemann          #+#    #+#             */
/*   Updated: 2024/01/17 12:33:50 by hwiemann         ###   ########.fr       */
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

//swap first 2 elements in stackA
struct s_stack	*sa(struct s_stack *stackA)
{
	struct s_stack	*top;
	struct s_stack	*next;
	//int	size;

	//size = stacksize(stackA);
	if(stackA->next != NULL && stackA->next->prev != NULL)
	{
		top = pop(stackA);
		next = pop(stackA);

		/*push(stackA, next);
		push(stackA, top);*/
	}
	return (0);
}

