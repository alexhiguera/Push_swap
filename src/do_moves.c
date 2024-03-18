/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiguera <ahiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 18:36:51 by ahiguera          #+#    #+#             */
/*   Updated: 2024/03/11 18:36:51 by ahiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_both(t_stack **a, t_stack **b, int *box_a, int *box_b)
{
	while (*box_a < 0 && *box_b < 0)
	{
		(*box_a)++;
		(*box_b)++;
		rrr(a, b);
	}
}

static void	rotate_both(t_stack **a, t_stack **b, int *box_a, int *box_b)
{
	while (*box_a > 0 && *box_b > 0)
	{
		(*box_a)--;
		(*box_b)--;
		rr(a, b);
	}
}

static void	rotate_a(t_stack **a, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			ra(a);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			rra(a);
			(*cost)++;
		}
	}
}

static void	rotate_b(t_stack **b, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			rb(b);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			rrb(b);
			(*cost)++;
		}
	}
}

void	move(t_stack **a, t_stack **b, int box_a, int box_b)
{
	if (box_a < 0 && box_b < 0)
		reverse_both(a, b, &box_a, &box_b);
	else if (box_a > 0 && box_b > 0)
		rotate_both(a, b, &box_a, &box_b);
	rotate_a(a, &box_a);
	rotate_b(b, &box_b);
	pa(a, b);
}
