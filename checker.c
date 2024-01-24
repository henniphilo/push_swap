/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 12:27:42 by hwiemann          #+#    #+#             */
/*   Updated: 2024/01/24 12:19:56 by hwiemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//stacks bilden
// checken ob elemente valide sind
// in bereich von int min und max
// checken nach vorzeichen
// befehle implementieren
// dann logik

//checke ob es schon sortiert ist!

#include "pushswap.h"

static int	check_duplicates(char **argv, int index, long num)
{
	int	i;

	i = 1;
	while (i < index)
	{
		if (atoi_ps(argv[i]) == num)
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

// check if sorted

int	check_sort(struct s_stack *stack)
{
	struct s_stack	*head;

	head = stack;
	while(head && head->next)
	{
		if(head->data > head->next->data)
			return(0);
		head = head->next;
	}
	return(1);
}

void	check_args(int argc, char **argv)
{
	char	**arguments;
	int	i;
	long	num;

	if (argc >= 2)
	{
		printf("hallo flo");
		i = 1;
		arguments = argv;
		while (arguments[i])
		{
			if(!check_num(arguments[i]))
			{
				ft_printf("not num");
				exit(-1);
			}
			num = atoi_ps(arguments[i]);
			if (num < INT_MIN || num > INT_MAX)
			{
				ft_printf("not in the range");
				exit(-1);
			}
			if (check_duplicates(arguments, i, num))
			{
				ft_printf("dups");
				exit(-1);
			}
			i++;
		}
	}
}

