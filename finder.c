/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finder.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 16:33:19 by hwiemann          #+#    #+#             */
/*   Updated: 2024/02/11 16:35:52 by hwiemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	find_min(struct s_stack *stack)
{
	struct s_stack	*head;
	int				min;

	head = stack;
	min = head->data;
	if (stack == NULL)
	{
		return (1);
	}
	while (head != NULL)
	{
		if (head->data < min)
		{
			min = head->data;
		}
		head = head->next;
	}
	return (min);
}

int	find_num_position(struct s_stack *stack, int num, int part)
{
	struct s_stack	*head;
	int				current_pos;
	int				num_pos;

	head = stack;
	num_pos = 0;
	current_pos = 0;
	if (stack == NULL)
	{
		return (1);
	}
	while (head != NULL && current_pos < part)
	{
		if (head->data == num)
		{
			num = head->data;
			num_pos = current_pos;
		}
		head = head->next;
		current_pos++;
	}
	return (num_pos);
}

int	find_min_position(struct s_stack *stack)
{
	struct s_stack	*head;
	int				min;
	int				current_pos;
	int				min_pos;

	head = stack;
	min = head->data;
	min_pos = 0;
	current_pos = 0;
	if (stack == NULL)
	{
		return (1);
	}
	while (head != NULL)
	{
		if (head->data < min)
		{
			min = head->data;
			min_pos = current_pos;
		}
		head = head->next;
		current_pos++;
	}
	return (min_pos);
}

int	find_max(struct s_stack *stack)
{
	struct s_stack	*head;
	int				max;

	head = stack;
	if (head == NULL)
	{
		return (1);
	}
	max = head->data;
	while (head != NULL)
	{
		if (head->data > max)
		{
			max = head->data;
		}
		head = head->next;
	}
	return (max);
}

int	find_min_in_part(struct s_stack *stack, int part)
{
	struct s_stack	*head;
	int				min;
	int				current_pos;
	int				min_pos;

	head = stack;
	min = head->data;
	min_pos = 0;
	current_pos = 0;
	while (stack && current_pos < part)
	{
		if (head->data < min)
		{
			min = head->data;
			min_pos = current_pos;
		}
		head = head->next;
		current_pos++;
	}
	return (min_pos);
}
