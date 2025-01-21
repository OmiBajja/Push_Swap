/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_calc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obajja <obajja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 20:59:14 by obajja            #+#    #+#             */
/*   Updated: 2025/01/21 20:40:50 by obajja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_closest_small(int mid, t_liste **stack)
{
	t_liste	*temp;

	temp = *stack;
	while (temp->next != NULL && temp->number > mid)
		temp = temp->next;
	if (temp->next == NULL && temp->number > mid)
		return (-1);
	else
		return (temp->index);
}
void	ft_min_max_calculator(t_liste **stack, int *min, int *max)
{
	t_liste	*temp;

	temp = *stack;
	*min = temp->number;
	*max = temp->number;
	while (temp != NULL)
	{
		if (temp->number < *min)
			*min = temp->number;
		else if (temp->number > *max)
			*max = temp->number;
		temp = temp->next;
	}
}

short	is_sorted(t_liste **stack_a)
{
	t_liste	*temp;

	temp = *stack_a;
	while (temp->next != NULL)
	{
		if (temp->number > temp->next->number)
			return (-1);
		temp = temp->next;
	}
	return (0);
}

int	ft_stacksize(t_liste *stack)
{
	int	i;

	i = 0;
	while (stack != NULL)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

void	ft_3sorter(t_liste **stack_a)
{
	int	max;
	int	min;

	min = 0;
	max = 0;
	ft_min_max_calculator(stack_a, &min, &max);
	if ((*stack_a)->number == max)
	{
		ft_rotate_a(stack_a);
		if ((*stack_a)->number != min)
			ft_swap_a(stack_a);
	}
	else if ((*stack_a)->next->number == max)
	{
		ft_reverse_rotate_a(stack_a);
		if ((*stack_a)->number != min)
			ft_swap_a(stack_a);
	}
	else
	{
		if (is_sorted(stack_a) == -1)
			ft_swap_a(stack_a);
	}
}
