/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 18:37:42 by ahiguera          #+#    #+#             */
/*   Updated: 2024/03/18 15:57:58 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../Libft_2.0/src/libft.h"
# include <stddef.h>
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

//cost
void		cost(t_stack **stack_a, t_stack **stack_b);
void		cheapest_move(t_stack **stack_a, t_stack **stack_b);

//moves
void		move(t_stack **a, t_stack **b, int box_a, int box_b);

//position
int			position_lowest_index(t_stack **stack);
void		get_target_position(t_stack **stack_a, t_stack **stack_b);

//push_swap
int			is_sorted(t_stack *stack);
void		get_numbers(char *av, t_stack **stack_a);

//push
void		pa(t_stack **stack_a, t_stack **stack_b);
void		pb(t_stack **stack_a, t_stack **stack_b);

//reverse_rotate
void		rra(t_stack **stack_a);
void		rrb(t_stack **stack_b);
void		rrr(t_stack **stack_a, t_stack **stack_b);

//rotate
void		ra(t_stack **stack_a);
void		rb(t_stack **stack_b);
void		rr(t_stack **stack_a, t_stack **stack_b);

//sort
void		sort(t_stack **stack_a, t_stack **stack_b);
void		sort_three(t_stack **stack);

//stack
t_stack		*new_stack(int value);
void		add_stack(t_stack **stack, t_stack *new);
t_stack		*get_bottom(t_stack *stack);
t_stack		*before_bottom(t_stack *stack);
int			get_size_stack(t_stack	*stack);

//start
long		input_is_correct(char *av);
int			is_duplicate(t_stack *column);
void		get_index(t_stack *stack_a, int stack_size);

//swap
void		sa(t_stack **stack_a);
void		ss(t_stack **stack_a, t_stack **stack_b);

//utils
void		free_stack(t_stack **stack);
void		error_exit(t_stack **stack_a, t_stack **stack_b);
void		ft_putstr(char *str);
int			abs(int nb);

#endif
