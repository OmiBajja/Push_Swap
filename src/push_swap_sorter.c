/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sorter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obajja <obajja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 20:59:14 by obajja            #+#    #+#             */
/*   Updated: 2025/01/23 17:34:36 by obajja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_findqoneqthree(int *arr, int *q1, int *q3, int size)
{
	*q1 = arr[(size * 1) / 6];
	*q3 = arr[(size - 3)];
	return (arr[(size * 1) / 3]);
}	

void	ft_firstquarter(t_liste **stack_a, t_liste **stack_b, int q1,
		int mediane)
{
	if ((*stack_a)->number <= q1)
	{
		ft_push_b(stack_a, stack_b);
		if (*stack_b && (*stack_b)->next)
		{
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

void	ft_firsthalf(t_liste **stack_a, t_liste **stack_b, int mediane, int q1)
{
	while (ft_stacksize(*stack_a) != 3 && get_closest_small(mediane, stack_a) !=
		-1)
	{
		if ((*stack_a)->number <= mediane)
		{
			if ((*stack_a)->number <= q1)
			{
				ft_firstquarter(stack_a, stack_b, q1, mediane);
			}
			else
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
		}
		else if ((*stack_a)->number > mediane)
			ft_rotate_a(stack_a);
	}
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
	if (ft_stacksize(*stack_a) > 100)
	{
		mediane = ft_findsmallest(array, &quartile1, &quartile2, size);
		ft_firsthalf(stack_a, stack_b, mediane, quartile1);
	}
	mediane = ft_findqoneqthree(array, &quartile1, &quartile2, size);
	ft_firsthalf(stack_a, stack_b, mediane, quartile1);
	mediane = ft_findmidthird(array, &quartile1, &quartile2, size);
	ft_firsthalf(stack_a, stack_b, mediane, quartile1);
	if (quartile1 != quartile2)
		ft_secondhalf(stack_a, stack_b, mediane, quartile1);
	ft_lastthird(stack_a, stack_b, mediane, quartile2);
	ft_3sorter(stack_a);
	ft_pushmax(stack_a, stack_b, -1);
	free(array);
}
