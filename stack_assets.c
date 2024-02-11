/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_assets.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 16:48:54 by hwiemann          #+#    #+#             */
/*   Updated: 2024/02/11 16:49:15 by hwiemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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
