/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 13:34:13 by hwiemann          #+#    #+#             */
/*   Updated: 2024/02/11 17:10:54 by hwiemann         ###   ########.fr       */
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
		//stack_b = init_empty_stack();
		sort_five(stack_a, &stack_b);
	}
	else
	{
		//stack_b = init_empty_stack();
		wtf(stack_a, &stack_b, argc);
	}
}

int	main(int argc, char **argv)
{
	struct s_stack	*stack_a;
	struct s_stack	*stack_b;

	if (argc < 2)
	{
		ft_printf("not enough arrguments");
		return (1);
	}
	check_args(argc, argv);
	stack_a = init_stack(argc, argv);
	to_sorted_array(argc, argv, stack_a);
	if (stack_a == NULL)
	{
		ft_printf("Error Stack init");
		return (1);
	}
	if ((check_sort(stack_a)) == 1)
	{
		stack_b = init_empty_stack();
		choose_logic(&stack_a, stack_b, argc);
		check_sort(stack_a);
	}
	return (0);
}
