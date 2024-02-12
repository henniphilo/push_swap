/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 13:34:13 by hwiemann          #+#    #+#             */
/*   Updated: 2024/02/12 17:57:21 by hwiemann         ###   ########.fr       */
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
	}
	else
	{
		wtf(stack_a, &stack_b, argc);
	}
}

int	main(int argc, char **argv)
{
	struct s_stack	*stack_a;
	struct s_stack	*stack_b;
	char			**arrguments;

	if (argc == 2)
	{
		arrguments = ft_split(argv[1], ' ');
		ft_printf("hi\n");
	}
	if (argc > 2)
		arrguments = argv;
	check_args(argc, arrguments);
	stack_a = init_stack(argc, arrguments);
	to_sorted_array(argc, arrguments, stack_a);
	if (stack_a == NULL)
	{
		ft_printf("Error Stack init");
		return (1);
	}
	if ((check_sort(stack_a)) == 1)
	{
		stack_b = init_empty_stack();
		ft_printf("stack ist: ");
		printstack(stack_a);
		choose_logic(&stack_a, stack_b, argc);
		check_sort(stack_a);
	}
	return (0);
}
