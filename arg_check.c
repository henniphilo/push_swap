/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 12:27:42 by hwiemann          #+#    #+#             */
/*   Updated: 2024/02/15 12:19:23 by hwiemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	check_duplicates(char **argv, int index, long num)
{
	int	i;

	i = 1;
	while (i < index)
	{
		if (ft_atoi(argv[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

static int	check_num(char *argument)
{
	int	i;

	i = 0;
	if (argument[i] == '-' || argument[i] == '+')
		i++;
	while (argument[i])
	{
		if (!(argument[i] >= '0' && argument[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

void	check_args(int argc, char **argv)
{
	char	**arguments;
	int		i;
	long	num;

	if (argc >= 2)
	{
		i = 1;
		arguments = argv;
		while (arguments[i])
		{
			num = ft_atoi(arguments[i]);
			if ((!check_num(arguments[i]))
				|| (!(num >= -2147483648 && num <= 2147483647))
				|| check_duplicates(arguments, i, num))
			{
				ft_printf("Error\n");
				exit(-1);
			}
			i++;
		}
	}
}

int	check_sort(struct s_stack *stack)
{
	struct s_stack	*head;

	head = stack;
	while (head->next)
	{
		if (head->data > head->next->data)
		{
			return (1);
		}
		head = head->next;
	}
	return (0);
}
