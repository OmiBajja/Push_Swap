/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_calc_bis.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obajja <obajja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 20:59:14 by obajja            #+#    #+#             */
/*   Updated: 2025/02/12 00:28:20 by obajja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_index(int to_find, t_liste **stack)
{
	t_liste	*temp;

	if (!stack || !(*stack))
		return (-1);
	temp = *stack;
	while (temp->next != NULL && temp->number != to_find)
		temp = temp->next;
	if (temp->next == NULL && temp->number != to_find)
		return (-1);
	else
		return (temp->index);
}

void	ft_max_two_calculator(t_liste **stack, int max, int *max_two)
{
	t_liste	*temp;

	temp = *stack;
	*max_two = -2147483648;
	while (temp != NULL)
	{
		if (temp->number > *max_two && temp->number < max)
			*max_two = temp->number;
		temp = temp->next;
	}
}

short	ft_relative_index(int index, int index2, int size)
{
	if (index2 == -1)
		return (0);
	if (index > size / 2)
		index = (size - index) + 1;
	if (index2 > size / 2)
		index2 = (size - index2) + 1;
	if (index <= index2)
		return (0);
	else
		return (1);
}

void	ft_pushopti(t_liste **stack_a, t_liste **stack_b, int max, int index)
{
	int	size;

	if (!stack_b || !(*stack_b))
		return ;
	size = ft_stacksize(*stack_b);
	if (index == -1 || size == 0)
		return ;
	if (index <= size / 2 || size == 1)
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

void	ft_pushmax(t_liste **stack_a, t_liste **stack_b, int index2, int index)
{
	int	max;
	int	max2;
	int	size;

	while (ft_stacksize(*stack_b) != 0)
	{
		index2 = -1;
		size = ft_stacksize(*stack_b);
		ft_min_max_calculator(stack_b, &index, &max);
		index = get_index(max, stack_b);
		if (ft_stacksize(*stack_b) > 1)
		{
			ft_max_two_calculator(stack_b, max, &max2);
			index2 = get_index(max2, stack_b);
		}
		if (!ft_relative_index(index, index2, size))
			ft_pushopti(stack_a, stack_b, max, index);
		else if (ft_relative_index(index, index2, size) == 1)
		{
			ft_pushopti(stack_a, stack_b, max2, index2);
			index = get_index(max, stack_b);
			ft_pushopti(stack_a, stack_b, max, index);
			ft_swap_a(stack_a);
		}
	}
}
