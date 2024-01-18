/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 11:44:25 by hwiemann          #+#    #+#             */
/*   Updated: 2024/01/18 19:16:09 by hwiemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "./libft/libft.h"

typedef struct s_stack
{
	int	data;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;


//void	pb(t_Stack *stackA, t_Stack *stackB);
//void	pa(t_Stack *stackA, t_Stack *stackB);
//void	sa(t_Stack *stackA);
long int	atoi_ps(const char *str);
void	check_args(int argc, char **argv);


//int	pop(t_Stack *stack);
int	stacksize(struct s_stack *stack);
int	stackempty(struct s_stack *stack);
void	printstack(struct s_stack *head);
struct s_stack	*sa(struct s_stack *stackA);
struct s_stack *init_stack(int argc, char **argv);
struct s_stack *create_node(int data);
struct s_stack	*pop(struct s_stack *head);
struct s_stack	*push(struct s_stack *head, int data);
struct s_stack	*pb(struct s_stack *stackA, struct s_stack *stackB);


#endif
