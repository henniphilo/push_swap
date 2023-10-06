/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_shwap.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 11:44:25 by hwiemann          #+#    #+#             */
/*   Updated: 2023/10/06 13:05:02 by hwiemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_Node
{
	int	data;
	struct	t_Node *next;
}	t_Node;

typedef struct s_Stack
{
	t_Node	*top;
	size_t	index;
}	t_Stack;

void	initialize(t_Stack *stack);
void	push(t_Stack *stack, int data);
void	pb(t_Stack *stackA, t_Stack *stackB);
void	pa(t_Stack *stackA, t_Stack *stackB);
void	sa(t_Stack *stackA);

int	pop(t_Stack *stack);
int	stackempty(t_Stack *stack);


#endif
