/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 13:34:13 by hwiemann          #+#    #+#             */
/*   Updated: 2024/02/14 20:27:42 by hwiemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	choose_logic(t_stack **stack_a, t_stack *stack_b, int argc)
{
	if (argc == 4)
	{
		sort_three(stack_a);
	}
	else if (argc == 6)
	{
		sort_five(stack_a, &stack_b);
		//free(stack_b);
	}
	else
	{
		wtf(stack_a, &stack_b, argc);
		//free(stack_b);
	}
}

int	main(int argc, char **argv)
{
	struct s_stack	*stack_a;
	struct s_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc <= 2)
		return (1);
	if (argc > 2)
		check_args(argc, argv);
	stack_a = init_stack(argc, argv);
	to_sorted_array(argc, argv, stack_a);
	if (stack_a == NULL)
	{
		ft_printf("Error Stack init");
		free(stack_a);
		return (1);
	}
	if ((check_sort(stack_a)) == 1)
	{
		//stack_b = init_empty_stack();
		choose_logic(&stack_a, stack_b, argc);
		check_sort(stack_a);
		// free_stack(stack_a);
		free_stack(stack_b);
	}
	free_stack(stack_a);
	return (0);
}
