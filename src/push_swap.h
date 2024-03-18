/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 18:37:42 by ahiguera          #+#    #+#             */
/*   Updated: 2024/03/16 17:54:46 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../Libft_2.0/src/libft.h"
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target;
	int				box_a;
	int				box_b;
	struct s_stack	*next;
}	t_stack;

long		input_is_correct(char *av);
void		error_exit(t_stack **stack_a, t_stack **stack_b);
void		free_stack(t_stack **stack);
void		get_index(t_stack *stack_a, int stack_size);
t_stack		*stack_new(int value);
void		stack_add(t_stack **stack, t_stack *new);
t_stack		*get_bottom(t_stack *stack);
int			get_stack_size(t_stack	*stack);
int			is_sorted(t_stack *stack);
void		sort_three(t_stack **stack);
void		do_sa(t_stack **stack_a);
void		do_sa(t_stack **stack_b);
void		do_ss(t_stack **stack_a, t_stack **stack_b);
void		ft_putstr(char *str);
void		do_ra(t_stack **stack_a);
void		do_rb(t_stack **stack_b);
void		do_rr(t_stack **stack_a, t_stack **stack_b);
t_stack		*before_bottom(t_stack *stack);
void		do_rra(t_stack **stack_a);
void		do_rrb(t_stack **stack_b);
void		do_rrr(t_stack **stack_a, t_stack **stack_b);
void		do_pa(t_stack **stack_a, t_stack **stack_b);
void		do_pb(t_stack **stack_a, t_stack **stack_b);
void		sort(t_stack **stack_a, t_stack **stack_b);
void		get_target_position(t_stack **stack_a, t_stack **stack_b);
void		cost(t_stack **stack_a, t_stack **stack_b);
void		cheapest_move(t_stack **stack_a, t_stack **stack_b);
int			abs(int nb);
void		do_move(t_stack **a, t_stack **b, int box_a, int box_b);
int			position_lowest_index(t_stack **stack);
void		get_numbers(char *av, t_stack **stack_a);
int			is_duplicate(t_stack *column);

#endif
