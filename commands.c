/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 11:45:50 by hwiemann          #+#    #+#             */
/*   Updated: 2023/10/06 12:15:44 by hwiemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


//pb | push the first element of stack a to the top of stack b.
void	pb(t_Stack *stackA, t_Stack *stackB)
{
	int	topElement;

	if(!stackempty(stackA))
	{
		topElement = pop(stackA);
		push(stackB, topElement);
	}
	else
	{
		ft_printf("Error");
	}
}

//pa | push the first element of stack b to the top of stack a.
void	pa(t_Stack *stackA, t_Stack *stackB)
{
	int	topElement;

	if(!stackempty(stackB))
	{
		topElement = pop(stackB);
		push(stackA, topElement);
	}
	else
	{
		ft_printf("Error");
	}
}
