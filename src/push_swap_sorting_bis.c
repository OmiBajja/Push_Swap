/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sorting_bis.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obajja <obajja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 20:59:14 by obajja            #+#    #+#             */
/*   Updated: 2025/02/12 14:23:42 by obajja           ###   ########.fr       */
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
	if (*q3 != (size * 3) / 4)
		return (arr[(size * 3) / 4]);
	else
		return (size - 4);
}

int	ft_lastthird(t_liste **stack_a, t_liste **stack_b, int mediane,
		int quartile)
{
	while (ft_stacksize(*stack_a) != 3 && get_closest_small(quartile,
			stack_a) != -1)
	{
		if ((*stack_a)->number < quartile)
		{
			mediane = ft_push_b(stack_a, stack_b);
			if (mediane == 1)
				return (-1);
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
	return (0);
}

int	ft_lastchecker(t_liste **stack)
{
	t_liste	*node;

	node = *stack;
	while (node->next != NULL)
		node = node->next;
	return (node->number);
}

int	ft_small_sorter(t_liste **stack_a, t_liste **stack_b, int *array, int size)
{
	int	q3;
	int	n;

	n = ft_findmidthird(array, &q3, &q3, size);
	n = ft_lastthird(stack_a, stack_b, size, q3);
	if (n == -1)
		return (-1);
	ft_3sorter(stack_a);
	if (ft_stacksize(*stack_b) > 0)
	{
		if (ft_stacksize(*stack_b) == 1)
			ft_push_a(stack_a, stack_b);
		else if ((*stack_b)->number > (*stack_b)->next->number)
		{
			ft_push_a(stack_a, stack_b);
			ft_push_a(stack_a, stack_b);
		}
		else
		{
			ft_push_a(stack_a, stack_b);
			ft_push_a(stack_a, stack_b);
			ft_swap_a(stack_a);
		}
	}
	return (0);
}
