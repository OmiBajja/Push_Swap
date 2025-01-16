/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo_bis.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obajja <obajja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 20:59:14 by obajja            #+#    #+#             */
/*   Updated: 2025/01/15 13:38:56 by obajja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_a(t_liste **stack_a)
{
	ft_rotator(stack_a);
	ft_printf("ra\n");
}
void	ft_rotate_b(t_liste **stack_b)
{
	ft_rotator(stack_b);
	ft_printf("rb\n");
}
void	ft_rotate_rr(t_liste **stack_a, t_liste **stack_b)
{
	ft_rotator(stack_a);
	ft_rotator(stack_b);
	ft_printf("rr\n");
}
