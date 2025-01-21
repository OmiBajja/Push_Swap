/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_calc_bis.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obajja <obajja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 20:59:14 by obajja            #+#    #+#             */
/*   Updated: 2025/01/21 16:43:00 by obajja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_index(int to_find, t_liste **stack)
{
	t_liste	*temp;

	temp = *stack;
	while (temp->next != NULL && temp->number != to_find)
		temp = temp->next;
	if (temp->next == NULL && temp->number != to_find)
		return (-1);
	else
		return (temp->index);
}

void	ft_pushmax(t_liste **stack_a, t_liste **stack_b, int counter, int size)
{
	int	min;
	int	max;
	int	index;

	index = -1;
	counter = size + 1;
	while (--counter > 0)
	{
		size = ft_stacksize(*stack_b);
		ft_min_max_calculator(stack_b, &min, &max);
		index = get_index(max, stack_b);
		if (index <= size / 2)
		{
			while ((*stack_b)->number != max)
				ft_rotate_b(stack_b);
			ft_push_a(stack_a, stack_b);
		}
		else if (index > size / 2)
		{
			while ((*stack_b)->number != max)
				ft_reverse_rotate_b(stack_b);
			ft_push_a(stack_a, stack_b);
		}
	}
}
