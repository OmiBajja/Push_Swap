/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sorting_bis.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obajja <obajja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 20:59:14 by obajja            #+#    #+#             */
/*   Updated: 2025/01/23 15:42:34 by obajja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_findsmallest(int *arr, int *q1, int *q3, int size)
{
	*q1 = arr[(size * 1) / 25];
	*q3 = arr[(size - 3)];
	return (arr[(size * 1) / 15]);
}

int	ft_findmidthird(int *arr, int *q1, int *q3, int size)
{
	*q1 = arr[(size * 1) / 2];
	*q3 = arr[(size - 3)];
	return (arr[(size * 3) / 4]);
}

void	ft_lastthird(t_liste **stack_a, t_liste **stack_b, int mediane,
		int quartile)
{
	while (ft_stacksize(*stack_a) != 3 && get_closest_small(quartile,
			stack_a) != -1)
	{
		if ((*stack_a)->number < quartile)
		{
			ft_push_b(stack_a, stack_b);
			if ((*stack_b)->next
				&& (*stack_b)->number < (*stack_b)->next->number)
			{
				if ((*stack_a)->number > (*stack_a)->next->number)
					ft_swap_ss(stack_a, stack_b);
				else
					ft_swap_b(stack_b);
			}
		}
		else if ((*stack_a)->number >= quartile)
			ft_rotate_a(stack_a);
	}
	(void)mediane;
}

int	ft_lastchecker(t_liste **stack)
{
	t_liste	*node;

	node = *stack;
	while (node->next != NULL)
		node = node->next;
	return (node->number);
}
