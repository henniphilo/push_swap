/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 13:34:13 by hwiemann          #+#    #+#             */
/*   Updated: 2024/02/10 19:06:03 by hwiemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int argc, char **argv)
{
	struct s_stack	*stack_a;
	struct s_stack	*stack_b;
	int				size;
	int				min;

	if (argc < 2)
	{
		ft_printf("not enough arrguments");
		return (1);
	}
	check_args(argc, argv);
	stack_a = init_stack(argc, argv);
	to_sorted_array(argc, argv, stack_a);
	size = stacksize(stack_a);
	min = find_min(stack_a);
	if (stack_a == NULL)
	{
		ft_printf("Error Stack init");
		return (1);
	}
	if ((check_sort(stack_a)) == 1)
	{
		if (argc == 4)
		{
			sort_three(&stack_a);
		}
		else if (argc == 6)
		{
			stack_b = init_empty_stack();
			sort_five(&stack_a, &stack_b);
		}
		else
		{
			stack_b = init_empty_stack();
			wtf(&stack_a, &stack_b, argc);
		}
		check_sort(stack_a);
	}
	return (0);
}
