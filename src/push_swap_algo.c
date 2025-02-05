/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obajja <obajja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 20:59:14 by obajja            #+#    #+#             */
/*   Updated: 2025/02/04 15:41:31 by obajja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_a(t_liste **stack_a)
{
	ft_swapper(stack_a);
	ft_printf("sa\n");
}

void	ft_swap_b(t_liste **stack_b)
{
	ft_swapper(stack_b);
	ft_printf("sb\n");
}

void	ft_swap_ss(t_liste **stack_a, t_liste **stack_b)
{
	ft_swapper(stack_a);
	ft_swapper(stack_b);
	ft_printf("ss\n");
}

short	ft_push_a(t_liste **stack_a, t_liste **stack_b)
{
	short	n;

	n = 0;
	n = ft_pusher(stack_a, stack_b);
	ft_printf("pa\n");
	return (n);
}

int	ft_push_b(t_liste **stack_a, t_liste **stack_b)
{
	short	n;

	n = 0;
	n = ft_pusher(stack_b, stack_a);
	if (n == (short)1)
		return (1);
	ft_printf("pb\n");
	return (0);
}
