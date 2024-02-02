/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 11:44:25 by hwiemann          #+#    #+#             */
/*   Updated: 2024/02/02 17:23:32 by hwiemann         ###   ########.fr       */
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

long int	atoi_ps(const char *str);
void	check_args(int argc, char **argv);

int	stacksize(struct s_stack *stack);
int	stackempty(struct s_stack *stack);
int	check_sort(struct s_stack *stack);
int	find_min(struct s_stack *stack);
int	find_max(struct s_stack *stack);
int	find_min_position(struct s_stack *stack);
int	find_min_in_part(struct s_stack *stack, int part);


void	printstack(struct s_stack *head);
struct s_stack *init_stack(int argc, char **argv);
struct s_stack *create_node(int data);
struct s_stack	*pop(struct s_stack *head);
struct s_stack	*push(struct s_stack *head, int data);
struct s_stack	*push_stack(struct s_stack *stack_from, struct s_stack **stack_to);
struct s_stack	*swap_stack(struct s_stack **stack);
struct s_stack *rota_stack(struct s_stack **head);
struct s_stack *reverse_rotation(struct s_stack **stack);
void	sort(struct s_stack **stack_a, struct s_stack **stack_b);
void	sort_back(struct s_stack *stack_a, struct s_stack *stack_b);
void	little_logic(struct s_stack *stack_a, struct s_stack *stack_b);
void	push_min(struct s_stack **stack_a, struct s_stack **stack_b);
void	sort_three(struct s_stack **stack_a);
void	sort_five(struct s_stack **stack_a, struct s_stack **stack_b);
void	sort_hundert(struct s_stack **stack_a, struct s_stack **stack_b);
void	push_part_min(struct s_stack **stack_a, struct s_stack **stack_b);


struct s_stack	*pa(struct s_stack **stack_a, struct s_stack **stack_b);
struct s_stack	*pb(struct s_stack **stack_a, struct s_stack **stack_b);
struct s_stack	*sa(struct s_stack **stack_a);
int	sb(struct s_stack **stack_b);
int	ss(struct s_stack **stack_a, struct s_stack **stack_b);
int	ra(struct s_stack **stack_a);
int	rb(struct s_stack **stack_b);
int	rr(struct s_stack **stack_a, struct s_stack **stack_b);
struct s_stack	*rra(struct s_stack **stack_a);
struct s_stack	*rrb(struct s_stack **stack_b);
int	rrr(struct s_stack **stack_a, struct s_stack **stack_b);



#endif
