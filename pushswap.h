/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 11:44:25 by hwiemann          #+#    #+#             */
/*   Updated: 2024/01/03 15:38:30 by hwiemann         ###   ########.fr       */
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

/*typedef struct s_Node
{
	int	data;
	struct	t_Node *next;
}	t_Node;

typedef struct s_Stack
{
	t_Node	*top;
	size_t	size;
	int		data[STACK_SIZE];
}	t_Stack; */

//void	pb(t_Stack *stackA, t_Stack *stackB);
//void	pa(t_Stack *stackA, t_Stack *stackB);
//void	sa(t_Stack *stackA);
long int	atoi_ps(const char *str);
void	check_args(int argc, char **argv);


//int	pop(t_Stack *stack);
int	stacksize(struct s_stack *stack);
int	stackempty(struct s_stack *stack);
void	printstack(struct s_stack *head);
struct s_stack *init_stack(int argc, char **argv);
struct s_stack *create_node(int data);
struct s_stack	*pop(struct s_stack *head);


#endif
