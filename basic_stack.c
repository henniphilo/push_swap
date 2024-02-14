/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:20:17 by hwiemann          #+#    #+#             */
/*   Updated: 2024/02/14 20:17:18 by hwiemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	printstack(struct s_stack *stack)
{
	struct s_stack	*head;

	head = stack;
	while (head != NULL)
	{
		ft_printf(" (%d) ", head->data);
		head = head->next;
	}
	ft_printf("\n");
}

struct s_stack	*create_node(int data)
{
	struct s_stack	*node;

	node = (struct s_stack *)malloc(sizeof(struct s_stack));
	if (node != NULL)
	{
		node->data = data;
		node->next = NULL;
		node->prev = NULL;
		node->index = 0;
	}
	else
	{
		ft_printf("Error allocating memory");
	}
	return (node);
}

static void	update_stack(t_stack **head, t_stack **current, t_stack *node)
{
	if (*head == NULL)
	{
		*head = node;
		*current = *head;
	}
	else
	{
		(*current)->next = node;
		node->prev = *current;
		*current = node;
	}
}

struct s_stack	*init_stack(int argc, char **argv)
{
	struct s_stack	*head;
	struct s_stack	*current;
	struct s_stack	*node;
	int				i;
	int				value;

	head = 0;
	current = 0;
	i = 1;
	while (i < argc)
	{
		value = ft_atoi(argv[i]);
		if (value != 0 || (value == 0 && argv[i][0] == '0'))
		{
			node = create_node(value);
			if (node != NULL)
			{
				update_stack(&head, &current, node);
				i++;
			}
		}
		else
			ft_printf("Error Convert");
	}
	return (head);
}

struct s_stack	*init_empty_stack(void)
{
	return (NULL);
}
