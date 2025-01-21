/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sorter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obajja <obajja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 20:59:14 by obajja            #+#    #+#             */
/*   Updated: 2025/01/22 00:37:34 by obajja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sorting(t_liste **stack_a, t_liste **stack_b, int size, int quartile)
{
	t_liste	*temp;

	temp = *stack_a;
	if (is_sorted(stack_a) == 0)
	{
		ft_printf("Sorted\n");
		return ;
	}
	else
	{
		while (ft_stacksize(*stack_a) != 3 && get_closest_small(quartile, stack_a) != -1)
		{
			if ((*stack_a)->number < quartile)
				ft_push_b(stack_a, stack_b);
			if ((*stack_a)->number >= quartile)
				ft_rotate_a(stack_a);
		}
	}
	ft_3sorter(stack_a);
	size = ft_stacksize(*stack_b);
	ft_pushmax(stack_a, stack_b, size);
}

