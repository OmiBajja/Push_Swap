/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sorts.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obajja <obajja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 20:59:14 by obajja            #+#    #+#             */
/*   Updated: 2025/01/20 23:09:42 by obajja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swapper(t_liste **stack)
{
	int	temp;

	temp = 0;
	if (*stack && (*stack)->next != NULL)
	{
		temp = (*stack)->number;
		(*stack)->number = (*stack)->next->number;
		(*stack)->next->number = temp;
	}
}
short	ft_pusher(t_liste **stack_1, t_liste **stack_2)
{
	t_liste	*new;
	t_liste	*temp;
	int		nb;

	nb = 0;
	temp = NULL;
	new = NULL;
	if (*stack_2)
	{
		temp = (*stack_2)->next;
		nb = (*stack_2)->number;
		free(*stack_2);
		(*stack_2) = temp;
		ft_index_decalator(stack_2, -1);
	}
	new = ft_lstnew_push(nb, 0);
	if (!new)
		return 1;
	if (stack_1 && *stack_1)
	{
		new->next = *stack_1;
		ft_index_decalator(stack_1, 1);
	}
	*stack_1 = new;
	return 0;
}

short	ft_rotator(t_liste **stack)
{
	t_liste	*temp;
	t_liste	*new;
	int		val;

	val = 0;
	if (*stack)
	{
		temp = (*stack)->next;
		val = (*stack)->number;
		free(*stack);
		*stack = temp;
	}
	new = ft_lstnew_push(val, 0);
	if (!new)
		return 1;
	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
	val = temp->index + 1;
	new->index = val;
	ft_index_decalator(stack, -1);
	return 0;
}
short	ft_reverse_rotator(t_liste **stack)
{
	t_liste	*temp;
	t_liste	*rip;
	t_liste	*new;
	int		val;

	val = 0;
	temp = *stack;
	while (temp->next->next != NULL)
		temp = temp->next;
	rip = temp->next;
	val = rip->number;
	free(rip);
	temp->next = NULL;
	new = ft_lstnew_push(val, 0);
	if (!new)
		return 1;
	new->next = *stack;
	ft_index_decalator(stack, 1);
	*stack = new;
	return 0;
}

void	ft_index_decalator(t_liste **stack, int decal)
{
	t_liste	*temp;

	temp = *stack;
	while (temp != NULL)
	{
		temp->index += decal;
		temp = temp->next;
	}
}
