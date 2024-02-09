/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 11:44:25 by hwiemann          #+#    #+#             */
/*   Updated: 2024/02/09 12:49:13 by hwiemann         ###   ########.fr       */
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
	int	data;
	struct s_stack	*next;
	struct s_stack	*prev;
	int	index;
}	t_stack;

long int	atoi_ps(const char *str);
char	**args_array(int argc, char **argv);
void	check_args(int argc, char **argv);
//void	stack_index(struct s_stack *stack);
void	array_index(char **array, int n);
void	array_sort(char **array, int n);
void	to_sorted_array(int argc, char **argv);

void	chunky(struct s_stack **stack, int max_b);


int	stacksize(struct s_stack *stack);
int	stackempty(struct s_stack *stack);
int	check_sort(struct s_stack *stack);
int	find_min(struct s_stack *stack);
int	find_max(struct s_stack *stack);
int	find_min_position(struct s_stack *stack);
int	find_min_in_part(struct s_stack *stack, int part);
int	check_reversed_order(struct s_stack *stack);
int	check_max(struct s_stack **stack);
int	find_num_position(struct s_stack *stack, int num, int part);


void	printstack(struct s_stack *stack);
struct s_stack *init_stack(int argc, char **argv);
struct s_stack *create_node(int data);
struct s_stack	*pop(struct s_stack *head);
struct s_stack	*push(struct s_stack *head, int data);
void	push_stack(struct s_stack **stack_from, struct s_stack **stack_to);
struct s_stack	*swap_stack(struct s_stack **stack);
struct s_stack *rota_stack(struct s_stack **head);
struct s_stack *reverse_rotation(struct s_stack **stack);
void	sort(struct s_stack **stack_a, struct s_stack **stack_b);
void	sort_back(struct s_stack **stack_a, struct s_stack **stack_b);
void	little_logic(struct s_stack **stack_a, struct s_stack **stack_b);
void	push_min(struct s_stack **stack_a, struct s_stack **stack_b);
void	sort_three(struct s_stack **stack_a);
void	sort_five(struct s_stack **stack_a, struct s_stack **stack_b);
void	sort_hundert(struct s_stack **stack_a, struct s_stack **stack_b);
void	push_part_min(struct s_stack **stack_a, struct s_stack **stack_b, int part);
void	hin_her(struct s_stack **stack_a, struct s_stack **stack_b);
void	put_on_top_a(struct s_stack **stack, int num);
void	put_on_top_b(struct s_stack **stack, int num);
void	presort_back(struct s_stack **stack_a, struct s_stack **stack_b);
void	smart_top(struct s_stack **stack_a, struct s_stack **stack_b);
void	wtf(struct s_stack **stack_a, struct s_stack **stack_b);
void	push_max(struct s_stack **stack_a, struct s_stack **stack_b);
void	sort_max(struct s_stack **stack_a, struct s_stack **stack_b);
void	reverse_compare(struct s_stack **stack_a, struct s_stack **stack_b, int part);


void	pa(struct s_stack **stack_a, struct s_stack **stack_b);
void	pb(struct s_stack **stack_a, struct s_stack **stack_b);
struct s_stack	*sa(struct s_stack **stack_a);
struct s_stack	*sb(struct s_stack **stack_b);
int	ss(struct s_stack **stack_a, struct s_stack **stack_b);
struct s_stack	*ra(struct s_stack **stack_a);
struct s_stack	*rb(struct s_stack **stack_b);
int	rr(struct s_stack **stack_a, struct s_stack **stack_b);
struct s_stack	*rra(struct s_stack **stack_a);
struct s_stack	*rrb(struct s_stack **stack_b);
int	rrr(struct s_stack **stack_a, struct s_stack **stack_b);



#endif
