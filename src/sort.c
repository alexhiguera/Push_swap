/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 18:38:24 by ahiguera          #+#    #+#             */
/*   Updated: 2024/03/20 13:45:39 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_init(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_size;
	int	pushes;
	int	i;

	stack_size = get_size_stack(*stack_a);
	pushes = 0;
	i = 0;
	while (stack_size > 6 && i < stack_size && pushes < stack_size / 2)
	{
		if ((*stack_a)->index <= stack_size / 2)
		{
			pb(stack_a, stack_b);
			pushes++;
		}
		else
			ra(stack_a);
		i++;
	}
	while (stack_size - pushes > 3)
	{
		pb(stack_a, stack_b);
		pushes++;
	}
}

static void	sort_stack(t_stack **stack_a)
{
	int	lowest_p;
	int	stack_size;

	stack_size = get_size_stack(*stack_a);
	lowest_p = position_lowest_index(stack_a);
	if (lowest_p > stack_size / 2)
	{
		while (lowest_p < stack_size)
		{
			rra(stack_a);
			lowest_p++;
		}
	}
	else
	{
		while (lowest_p > 0)
		{
			ra(stack_a);
			lowest_p--;
		}
	}
}

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	push_init(stack_a, stack_b);
	sort_three(stack_a);
	while (*stack_b)
	{
		get_target_position(stack_a, stack_b);
		calculate_move_cost(stack_a, stack_b);
		best_move(stack_a, stack_b);
	}
	if (!is_sorted(*stack_a))
		sort_stack(stack_a);
}

static int	biggest_index(t_stack *stack)
{
	int	index;

	index = stack->index;
	while (stack)
	{
		if (stack->index > index)
			index = stack->index;
		stack = stack->next;
	}
	return (index);
}

void	sort_three(t_stack **stack)
{
	int	biggest;

	if (is_sorted(*stack))
		return ;
	biggest = biggest_index(*stack);
	if ((*stack)->index == biggest)
		ra(stack);
	else if ((*stack)->next->index == biggest)
		rra(stack);
	if ((*stack)->index > (*stack)->next->index)
		sa(stack);
}
