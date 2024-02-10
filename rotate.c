/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:47:13 by hwiemann          #+#    #+#             */
/*   Updated: 2024/02/10 18:49:18 by hwiemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

//rotate stack moves first element to the bottom

struct s_stack *rota_stack(struct s_stack **head)
{
	struct s_stack	*current;
	struct s_stack	*new_top;

	current = *head;
	new_top = (*head)->next;

	if(*head == NULL || (*head)->next == NULL)
	{
		ft_printf("Error\n");
		return(*head);
	}
	while(current->next != NULL)
	{
		current = current->next;
	}
	(*head)->next = NULL;
	current->next = *head;
	*head = new_top;
	return (*head);
}

struct s_stack	*ra(struct s_stack **stack_a)
{
	if(*stack_a == NULL)
	{
		return(*stack_a);
	}
	rota_stack(stack_a);
	ft_printf("ra\n");
	return(*stack_a);
}

struct s_stack	*rb(struct s_stack **stack_b)
{
	if(*stack_b == NULL)
	{
		return(*stack_b);
	}
	rota_stack(stack_b);
	ft_printf("rb\n");
	return(*stack_b);
}

int	rr(struct s_stack **stack_a, struct s_stack **stack_b)
{
	if(*stack_a == NULL || *stack_b == NULL)
	{
		return(1);
	}
	rota_stack(stack_a);
	rota_stack(stack_b);
	ft_printf("rr");
	return(0);
}
