/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiguera <ahiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 18:36:38 by ahiguera          #+#    #+#             */
/*   Updated: 2024/03/11 18:36:38 by ahiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		size_a;
	int		size_b;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	size_a = get_size_stack(tmp_a);
	size_b = get_size_stack(tmp_b);
	while (tmp_b)
	{
		tmp_b->box_b = tmp_b->pos;
		if (tmp_b->pos > size_b / 2)
			tmp_b->box_b = (size_b - tmp_b->pos) * -1;
		tmp_b->box_a = tmp_b->target;
		if (tmp_b->target > size_a / 2)
			tmp_b->box_a = (size_a - tmp_b->target) * -1;
		tmp_b = tmp_b->next;
	}
}

void	cheapest_move(t_stack **stack_a, t_stack **stack_b)
{
	t_stack		*temp;
	int			cheapest;
	int			box_a;
	int			box_b;

	temp = *stack_b;
	cheapest = INT_MAX;
	while (temp)
	{
		if (abs(temp->box_a) + abs(temp->box_b) < cheapest)
		{
			cheapest = abs(temp->box_a) + abs(temp->box_b);
			box_a = temp->box_a;
			box_b = temp->box_b;
		}
		temp = temp->next;
	}
	move(stack_a, stack_b, box_a, box_b);
}
