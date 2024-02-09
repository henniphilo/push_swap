/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:20:17 by hwiemann          #+#    #+#             */
/*   Updated: 2024/02/09 12:51:02 by hwiemann         ###   ########.fr       */
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
	j = 0;


	while(i < n - 1)
	{
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
	//ft_printf("sorted array ist : [%s]", array);
		free(array);
}

void	to_sorted_array(int argc, char **argv)
{
	char	**array;

	array = args_array(argc, argv);
//	ft_printf("array ist : [%s] \n", array);
	array_sort(array, argc - 1);
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


// static void	bubble_index(struct s_stack **stack)
// {
// 	int	swapped;
// 	struct s_stack	*bubble;
// 	//struct s_stack	*blubb;

// 	swapped = 1;

// 	while(swapped)
// 	{
// 		swapped = 0;
// 		bubble = *stack;
// 		//blubb = NULL;

// 		while(bubble && bubble->next)
// 		{
// 			if(bubble->data > bubble->next->data)
// 			{
// 				ft_swap(bubble, bubble->next);
// 				swapped = 1;
// 			}
// 		bubble = bubble->next;
// 		}
// 	}
// }

// void	stack_index(struct s_stack *stack)
// {
// 	int	index;

// 	index = 1;

// 	bubble_index(&stack);

// 	while(stack != NULL)
// 		{
// 			stack ->index = index++;
// 			stack = stack->next;
// 		}
// }
