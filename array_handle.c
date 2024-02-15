/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 17:20:09 by hwiemann          #+#    #+#             */
/*   Updated: 2024/02/15 11:52:45 by hwiemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	ft_swap(char **a, char **b)
{
	char	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	array_sort(char **array, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < n - 1)
	{
		j = 0;
		while (j < n - i - 1)
		{
			if (ft_atoi(array[j]) > ft_atoi(array[j + 1]))
			{
				ft_swap(&array[j], &array[j + 1]);
			}
			j++;
		}
		i++;
	}
}

void	assign_index(struct s_stack **stack, char **array, int n)
{
	struct s_stack	*head;
	struct s_stack	*current;
	int				i;

	i = 0;
	head = *stack;
	while (i < n)
	{
		current = head;
		while (current != NULL && current->data != ft_atoi(array[i]))
		{
			current = current->next;
		}
		if (current != NULL)
		{
			current->index = i;
		}
		i++;
	}
}

void	to_sorted_array(int argc, char **argv, struct s_stack *stack)
{
	struct s_stack	*head;

	head = stack;
	array_sort(argv, argc - 1);
	assign_index(&head, argv, argc - 1);
}
