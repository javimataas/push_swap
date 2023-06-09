/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 16:28:53 by jmatas-p          #+#    #+#             */
/*   Updated: 2023/05/11 18:19:07 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}				t_stack;

int				ft_argv_check(char **argv, int is_formatted);

int				ft_count_strings(char **strs);
char			**ft_format(char **argv);

void			ft_free_stack(t_stack **stack);
t_stack			*ft_fill_stack(char **argv, int parsed);
void			ft_set_idx(t_stack *stack, int size);

void			ft_rx(t_stack **stack, char x);
void			ft_rr(t_stack **stack_a, t_stack **stack_b, char should_write);
void			ft_rrx(t_stack **stack, char x);
void			ft_rrr(t_stack **stack_a, t_stack **stack_b, char should_write);
void			ft_px(t_stack **src, t_stack **dest, char dx);

void			ft_sx(t_stack *stack, char x);
void			ft_ss(t_stack **stack_a, t_stack **stack_b, char should_write);

void			ft_sort_three(t_stack **stack);
void			ft_push_all_minus_three(t_stack **stack_a, t_stack **stack_b);
void			ft_rev_stack(t_stack **stack_a);
int				ft_is_sorted(t_stack *stack);
void			ft_sort_left(t_stack **stack_a, t_stack **stack_b);
void			ft_sort(t_stack **stack_a, t_stack **stack_b, int s_size);

int				ft_stack_size(t_stack *stack);
t_stack			*ft_last_value(t_stack *stack);
t_stack			*ft_before_last_value(t_stack *stack);
void			ft_add_stack(t_stack **stack, t_stack *new);
t_stack			*ft_new_value(int value);

void			ft_set_cost(t_stack **stack_a, t_stack **stack_b);
void			ft_set_cheapest(t_stack **stack_a, t_stack **stack_b);

void			ft_execute_rr(t_stack **a, t_stack **b, int *c_a, int *c_b);
void			ft_execute_rrr(t_stack **a, t_stack **b, int *c_a, int *c_b);
void			ft_execute_rr_or_rrr(char c_stack, t_stack **stack, int *cost);
void			ft_execute_rotation(t_stack **a, t_stack **b, int c_a, int c_b);

void			ft_set_pos(t_stack **stack);
int				ft_get_lowest_idx_pos(t_stack **stack);
int				ft_get_target(t_stack **a, int b_idx, int t_idx, int t_pos);
void			ft_set_target_pos(t_stack **stack_a, t_stack **stack_b);

#endif
