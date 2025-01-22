/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo_ter.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obajja <obajja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 20:59:14 by obajja            #+#    #+#             */
/*   Updated: 2025/01/22 17:56:00 by obajja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate_a(t_liste **stack_a)
{
	ft_reverse_rotator(stack_a);
	ft_printf("rra\n");
}

void	ft_reverse_rotate_b(t_liste **stack_b)
{
	ft_reverse_rotator(stack_b);
	ft_printf("rrb\n");
}

void	ft_reverse_rotate_rr(t_liste **stack_a, t_liste **stack_b)
{
	ft_reverse_rotator(stack_a);
	ft_reverse_rotator(stack_b);
	ft_printf("rrr\n");
}
