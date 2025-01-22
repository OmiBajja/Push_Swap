/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sorter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obajja <obajja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 20:59:14 by obajja            #+#    #+#             */
/*   Updated: 2025/01/22 18:40:12 by obajja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_findqoneqthree(int *arr, int *q1, int *q3, int size)
{
	*q1 = arr[(size * 1) / 4];
	*q3 = arr[(size - 3)];
	return (arr[size / 2]);
}

void	ft_firstquarter(t_liste **stack_a, t_liste **stack_b, int q1)
{
	while (ft_stacksize(*stack_a) != 3 && get_closest_small(q1, stack_a) != -1)
	{
		if ((*stack_a)->number <= q1)
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
		if ((*stack_a)->number > q1)
			ft_rotate_a(stack_a);
	}
}

void	ft_secondhalf(t_liste **stack_a, t_liste **stack_b, int mediane,
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
		if ((*stack_a)->number >= quartile)
			ft_rotate_a(stack_a);
	}
	(void)mediane;
}

void	ft_firsthalf(t_liste **stack_a, t_liste **stack_b, int mediane,
		int quartile)
{
	while (ft_stacksize(*stack_a) != 3 && get_closest_small(mediane,
			stack_a) != -1)
	{
		if ((*stack_a)->number <= mediane)
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
		if ((*stack_a)->number > mediane)
			ft_rotate_a(stack_a);
	}
	(void)quartile;
}

void	ft_sorting(t_liste **stack_a, t_liste **stack_b, int *array, int size)
{
	t_liste	*temp;
	int		mediane;
	int		quartile1;
	int		quartile2;

	temp = *stack_a;
	if (is_sorted(stack_a) == 0)
	{
		ft_printf("Sorted\n");
		return ;
	}
	else
	{
		mediane = ft_findqoneqthree(array, &quartile1, &quartile2, size);
		ft_firstquarter(stack_a, stack_b, quartile1);
		ft_firsthalf(stack_a, stack_b, mediane, quartile2);
		ft_secondhalf(stack_a, stack_b, mediane, quartile2);
	}
	ft_3sorter(stack_a);
	size = ft_stacksize(*stack_b);
	ft_pushmax(stack_a, stack_b, size, -1);
	free(array);
}
