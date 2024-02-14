/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 10:29:01 by hwiemann          #+#    #+#             */
/*   Updated: 2024/02/14 20:01:52 by hwiemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// void	free_node(struct s_stack *node)
// {
// 	free(node);
// }

// void	free_stack(struct s_stack *stack)
// {
// 	struct s_stack	*tmp;

// 	while(stack != NULL)
// 	{
// 		tmp = stack;
// 		stack = stack->next;
// 		free_node(tmp);
// 	}
// }

void	free_stack(struct s_stack *stack)
{
	struct s_stack	*current_node;
	struct s_stack	*next_node;

	current_node = stack;
	while (current_node)
	{
		next_node = current_node->next;
		free(current_node);
		current_node = next_node;
	}
}
