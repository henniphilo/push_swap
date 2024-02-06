/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:20:17 by hwiemann          #+#    #+#             */
/*   Updated: 2024/02/06 09:41:26 by hwiemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	stackempty(struct s_stack *stack)
{
	return (stack->next == NULL);
}

int	stacksize(struct s_stack *stack)
{
	int	i;

	i = 0;
	if (stackempty(stack))
		return (1);
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

