/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sorting_extra.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obajja <obajja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 20:59:14 by obajja            #+#    #+#             */
/*   Updated: 2025/02/05 15:58:59 by obajja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_big_sorter(t_liste **stack_a, t_liste **stack_b, int *array, int size)
{
	int	q1;
	int	q3;
	int	n;
	int	mediane;

	mediane = ft_findsmallest(array, &q1, &q3, size);
	ft_firsthalf(stack_a, stack_b, mediane, q1);
	mediane = ft_findqoneqthree(array, &q1, &q3, size);
	n = ft_firsthalf(stack_a, stack_b, mediane, q1);
	if (n == -1)
		return (free(array), 1);
	return (0);
}

int	ft_most_opti(t_liste **stack_b, int max2, int max3, int max4)
{
	int	index2;
	int	index3;
	int	index4;
	int	result;

	if (ft_stacksize(*stack_b) > 1)
		index2 = get_index(max2, stack_b);
	if (ft_stacksize(*stack_b) > 2)
		index3 = get_index(max3, stack_b);
	if (ft_stacksize(*stack_b) > 3)
		index4 = get_index(max4, stack_b);
	if (index2 <= index3 && index2 <= index4)
		return (max2);
	else if (index3 <= index2 && index3 <= index4)
		return (max3);
	else
		return (max4);
}
