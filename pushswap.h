/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 11:44:25 by hwiemann          #+#    #+#             */
/*   Updated: 2024/02/15 11:53:22 by hwiemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <string.h>
# include "./libft/libft.h"

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
	struct s_stack	*prev;
	int				index;
}	t_stack;

t_stack	*init_empty_stack(void);
t_stack	*init_stack(int argc, char **argv);
t_stack	*create_node(int data);
t_stack	*rota_stack(struct s_stack **head);
t_stack	*reverse_rotation(struct s_stack **stack);
t_stack	*sa(struct s_stack **stack_a);
t_stack	*sb(struct s_stack **stack_b);
t_stack	*ra(struct s_stack **stack_a);
t_stack	*rb(struct s_stack **stack_b);
t_stack	*rra(struct s_stack **stack_a);
t_stack	*rrb(struct s_stack **stack_b);

char	**args_array(int argc, char **argv);

void	swap_stack(struct s_stack **stack);
void	free_node(struct s_stack *node);
void	free_stack(struct s_stack *stack);
void	check_args(int argc, char **argv);
void	array_sort(char **array, int n);
void	to_sorted_array(int argc, char **argv, struct s_stack *stack);
void	printstack(struct s_stack *stack);
void	push_stack(struct s_stack **head_from, struct s_stack **head_to);
void	push_min(struct s_stack **stack_a, struct s_stack **stack_b);
void	sort_three(struct s_stack **stack_a);
void	sort_five(struct s_stack **stack_a, struct s_stack **stack_b);
void	part_min(struct s_stack **stack_a, struct s_stack **stack_b, int part);
void	hin_her(struct s_stack **stack_a, struct s_stack **stack_b, int chunk);
void	put_on_top_a(struct s_stack **stack, int num);
void	put_on_top_b(struct s_stack **stack, int num);

int		chunky(int argc);
int		stacksize(struct s_stack *stack);
int		check_sort(struct s_stack *stack);
int		find_min(struct s_stack *stack);
int		find_max(struct s_stack *stack);
int		find_min_position(struct s_stack *stack);
int		find_min_in_part(struct s_stack *stack, int part);
int		find_num_position(struct s_stack *stack, int num, int part);
int		ss(struct s_stack **stack_a, struct s_stack **stack_b);
int		rr(struct s_stack **stack_a, struct s_stack **stack_b);
int		rrr(struct s_stack **stack_a, struct s_stack **stack_b);

void	wtf(struct s_stack **stack_a, struct s_stack **stack_b, int argc);
void	push_max(struct s_stack **stack_a, struct s_stack **stack_b);
void	sort_max(struct s_stack **stack_a, struct s_stack **stack_b);
void	pa(struct s_stack **stack_a, struct s_stack **stack_b);
void	pb(struct s_stack **stack_a, struct s_stack **stack_b);

#endif
