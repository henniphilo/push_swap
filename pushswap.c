/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 13:34:13 by hwiemann          #+#    #+#             */
/*   Updated: 2024/01/23 16:19:57 by hwiemann         ###   ########.fr       */
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
	ft_printf("\n");
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


struct s_stack *init_stack(int argc, char **argv)
{
	struct s_stack	*head;
	struct s_stack	*current;
	struct s_stack	*node;
	int	i;
	int	value;

	head = 0;
	current = 0;
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
			break;
		}
	}
	return(head);
}

struct s_stack *init_empty_stack(void)
{
	return(NULL);
}

struct s_stack	*swap_stack(struct s_stack *stack);


int main(int argc, char **argv)
{
	struct s_stack	*head;
	struct s_stack	*stackB;

	int	size;

	if (argc < 2)
	{
		ft_printf("not enough arrguments");
		return 1;
	}
	check_args(argc, argv);
	head = init_stack(argc, argv);

	if (head == NULL)
	{
		ft_printf("Error Stack init");
		return 1;
	}
	ft_printf("Stack: ");
	printstack(head);

	size = stacksize(head);
	ft_printf("stacksize: %d \n", size);
	printf("data: %d\n", head->data);
	int	first = head->data;


	head = pop(head);
	ft_printf("after pop A: ");
	printstack(head);
	printf("data A: %d\n", head->data);

	size = stacksize(head);
	ft_printf("stacksize A: %d \n", size);

	head = push(head, first);
	ft_printf("after push A: ");
	printstack(head);
	ft_printf("data A: %d\n", head->data);

	size = stacksize(head);
	ft_printf("stacksize A: %d \n", size);

	stackB = init_empty_stack();
	ft_printf("Stack B: ");
	printstack(stackB);

	head = push_stack(head, &stackB);
	ft_printf("A after pb: ");
	printstack(head);

	size = stacksize(head);
	ft_printf("stacksize A: %d \n", size);

	stackB = push(stackB, 9);

	ft_printf("Stack B: ");
	printstack(stackB);
	size = stacksize(stackB);
	ft_printf("stacksize B: %d \n", size);

	stackB = push_stack(stackB, &head);
	ft_printf("Stack B: ");
	printstack(stackB);
	size = stacksize(stackB);
	ft_printf("stacksize B: %d \n", size);

	ft_printf("after pb A: ");
	printstack(head);
	ft_printf("data A: %d\n", head->data);

	size = stacksize(head);
	ft_printf("stacksize A: %d \n", size);

	head = swap_stack(head);
	ft_printf("after swap A: ");
	printstack(head);

	head = rota_stack(head);
	ft_printf("after rotate A: ");
	printstack(head);

	return (0);
}
