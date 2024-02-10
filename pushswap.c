/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 13:34:13 by hwiemann          #+#    #+#             */
/*   Updated: 2024/02/10 17:19:31 by hwiemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int main(int argc, char **argv)
{
	struct s_stack	*head;
	struct s_stack	*stackB;
	int	size;
	int	min;

	if (argc < 2)
	{
		ft_printf("not enough arrguments");
		return 1;
	}
	check_args(argc, argv);

	head = init_stack(argc, argv);

	to_sorted_array(argc, argv, head);

	size = stacksize(head);
	min = find_min(head);

	if (head == NULL)
	{
		ft_printf("Error Stack init");
		return 1;
	}

 	if((check_sort(head)) == 1)
	{
		if(argc == 4)
		{
			sort_three(&head);
		}
		else if(argc == 6)
		{
			stackB = init_empty_stack();
			sort_five(&head, &stackB);
		}
		else
		{
			stackB = init_empty_stack();
			wtf(&head, &stackB, argc);
		}
		check_sort(head);
	}
	return (0);
}





