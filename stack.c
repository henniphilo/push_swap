/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 13:34:13 by hwiemann          #+#    #+#             */
/*   Updated: 2023/12/29 11:15:48 by hwiemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// doubly linked list


void	printstack(struct s_stack *head)
{
	struct s_stack *ptr = head;

	while (ptr != NULL)
	{
		ft_printf(" (%d) ", ptr->data);
		ptr = ptr->next;
	}
}

struct s_stack *create_node(int data)
{
	struct s_stack	*node;

	node = (struct s_stack *)malloc(sizeof(struct s_stack));
	if (node != NULL)
	{
		node->data = data;
		node->next = NULL;
		node->prev = NULL;
	}
	else
	{
		ft_printf("Error allocating memory");
	}
	return node;
}

struct s_stack *init_stack(int argc, char *argv[])
{
	struct s_stack	*head;
	struct s_stack	*current;
	struct s_stack	*node;
	int	i;
	int	value;

	head = NULL;
	current = NULL;
	i = 1;

	while (i < argc)
	{
		value = atoi_ps(argv[i]);
		if (value != 0 || (value == 0 && argv[i][0] == '0'))
		{
			node = create_node(value);
			if (node != NULL)
			{
				if (head == NULL)
				{
					head = node;
					current = head;
				}
				else
				{
					current->next = node;
					node->prev = current;
					current = node;
				}
				i++;
			}
			else
			{
				ft_printf("Error Init");
			}
		}
		else
		{
			ft_printf("Error Convert");
		}
	}
	return head;
}

int main(int argc, char *argv[])
{
	struct s_stack	*head;

	if (argc < 2)
	{
		ft_printf("not enough arrguments");
		return 1;
	}
	head = init_stack(argc, argv);

	if (head == NULL)
	{
		ft_printf("Error Stack init");
		return 1;
	}
	ft_printf("Stack: ");
	printstack(head);

	return 0;
}
