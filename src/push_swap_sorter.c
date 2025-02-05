/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sorter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obajja <obajja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 20:59:14 by obajja            #+#    #+#             */
/*   Updated: 2025/02/05 15:32:29 by obajja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_findqoneqthree(int *arr, int *q1, int *q3, int size)
{
	*q1 = arr[(size * 1) / 6];
	*q3 = arr[(size - 3)];
	return (arr[(size * 2) / 4]);
}

void	ft_firstquarter(t_liste **stack_a, t_liste **stack_b, int q1,
		int mediane)
{
	if ((*stack_a)->number <= q1)
	{
		ft_push_b(stack_a, stack_b);
		if (*stack_b && (*stack_b)->next)
		{
			if ((*stack_a)->number > mediane)
				ft_rotate_rr(stack_a, stack_b);
			else
				ft_rotate_b(stack_b);
		}
	}
	(void)mediane;
}

void	ft_secondhalf(t_liste **stack_a, t_liste **stack_b, int mediane,
		int quartile)
{
	while (ft_stacksize(*stack_a) != 3 && get_closest_small(quartile,
			stack_a) != -1)
	{
		if ((*stack_a)->number <= quartile)
		{
			ft_push_b(stack_a, stack_b);
			if ((*stack_b)->number < (*stack_b)->next->number
				&& (*stack_a)->number > (*stack_a)->next->number)
				ft_rotate_rr(stack_a, stack_b);
			if ((*stack_b)->next
				&& (*stack_b)->number < (*stack_b)->next->number)
			{
				if ((*stack_a)->number > (*stack_a)->next->number)
					ft_swap_ss(stack_a, stack_b);
				else
					ft_swap_b(stack_b);
			}
		}
		else if ((*stack_a)->number > quartile)
			ft_rotate_a(stack_a);
	}
	(void)mediane;
}

short	ft_firsthalf(t_liste **stack_a, t_liste **stack_b, int mediane, int q1)
{
	while (get_closest_small(mediane, stack_a) > -1)
	{
		if ((*stack_a)->number <= mediane)
		{
			if ((*stack_a)->number <= q1)
				ft_firstquarter(stack_a, stack_b, q1, mediane);
			else
			{
				q1 = ft_push_b(stack_a, stack_b);
				if (q1 == 1 || get_closest_small(mediane, stack_a) == -2)
					return (-1);
				if ((*stack_b) && (*stack_b)->next
					&& (*stack_b)->number < (*stack_b)->next->number)
				{
					if ((*stack_a) && (*stack_a)->next
						&& (*stack_a)->number > (*stack_a)->next->number)
						ft_swap_ss(stack_a, stack_b);
					else
						ft_swap_b(stack_b);
				}
			}
		}
		else if ((*stack_a)->number > mediane)
			ft_rotate_a(stack_a);
	}
	return (0);
}


int	ft_sorting(t_liste **stack_a, t_liste **stack_b, int *array, int size)
{
	int		mediane;
	int		quartile1;
	int		quartile2;
	short	n;

	if (is_sorted(stack_a, 1) == 0)
		return (0);
	if (ft_stacksize(*stack_a) < 6)
		ft_small_sorter(stack_a, stack_b, array, size);
	else if (size > 100)
		ft_big_sorter(stack_a, stack_b, array, size);
	if (size >= 6)
	{
		mediane = ft_findmidthird(array, &quartile1, &quartile2, size);
		n = ft_firsthalf(stack_a, stack_b, mediane, quartile1);
		if (n == -1)
			return (free(array), 1);
		if (quartile1 != quartile2)
			ft_secondhalf(stack_a, stack_b, mediane, quartile1);
		ft_lastthird(stack_a, stack_b, mediane, quartile2);
		ft_3sorter(stack_a);
		ft_pushmax(stack_a, stack_b, -1, -1);
	}
	return (free(array), 0);
}
