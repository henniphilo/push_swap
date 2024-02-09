/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:20:17 by hwiemann          #+#    #+#             */
/*   Updated: 2024/02/09 17:06:37 by hwiemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

char	**args_array(int argc, char **argv)
{
	char	**array;
	int	i;

	if(argc < 2)
	{
		ft_printf("not enough arguments\n");
		return(NULL);
	}

	array = (char **)malloc((argc - 1) * sizeof(char *));
	i = 1;

	while(i < argc)
	{
		array[i - 1] = argv[i];
		i++;
	}
	return(array);
}

static void ft_swap(char **a, char **b)
{
	char	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	array_sort(char **array, int n)
{
	int	i;
	int j;

	i = 0;

	for(int k = 0; k < n; k++)
	{
		ft_printf("befor sort Element %d: %s\n", k, array[k]);
	}

	while(i < n - 1)
	{
		j = 0;
		while(j < n - i - 1)
		{
			if(strcmp(array[j], array[j + 1]) > 0)
			{
				ft_swap(&array[j], &array[j + 1]);
			}
			j++;
		}
		i++;
	}

	for(int k = 0; k < n; k++)
	{
		ft_printf("Element %d: %s\n", k, array[k]);
	}
}

// void	array_index(char **array, int n)
// {
// 	int	index;

// 	index = 0;

// 	while(index < n)
// 	{
// 		++index;
// 	}
// }

void	assign_index(struct s_stack **stack, char **array, int n)
{
	struct s_stack	*head;
	struct s_stack	*current;

	int	i;

	i = 0;
	head = *stack;

	ft_printf("stack is: \n");
	printstack(head);

	for(int k = 0; k < n; k++)
	{
		ft_printf("array %d: %s\n", k, array[k]);
	}

	while(i < n)
	{
		current = head;

		while(current != NULL && current->data != ft_atoi(array[i]))
		{
			current = current->next;
		}
		if(current != NULL)
		{
			ft_printf("i is: %d\n", i);
			current->index = i;
		}
		i++;
	}
	//*stack = head;
}


void	to_sorted_array(int argc, char **argv, struct s_stack *stack)
{
	char	**array;
	struct s_stack	*head;

	head = stack;
	array = args_array(argc, argv);
	array_sort(array, argc - 1);
	assign_index(&head, array, argc - 1);

//	stack = head;
	free(array);
}

int	stacksize(struct s_stack *stack)
{
	int	i;

	i = 0;
	if (stack == NULL)
		return (1);
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}


