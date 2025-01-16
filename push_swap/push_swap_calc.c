/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_calc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obajja <obajja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 20:59:14 by obajja            #+#    #+#             */
/*   Updated: 2025/01/15 22:36:41 by obajja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_target_in_b_calculator(int a_value, t_liste **stack_b, int max)
{
	t_liste	*temp;
    int     target;
    int     t_target;
    int     p;

    p = 0;
	temp = *stack_b;
    while (temp->next != NULL)
	{
		if (a_value > (*stack_b)->number && a_value - (*stack_b)->number < t_target)
        {
            target = (*stack_b)->number;
            t_target = a_value - (*stack_b)->number;
            p = 1;
        }
		temp = temp->next;
	}
    if (p == 0)
        target = max;
}

void	ft_target_in_b_calculator(int b_value, t_liste **stack_a, int max)
{
	t_liste	*temp;
    int     target;
    int     t_target;
    int     p;

    p = 0;
	temp = *stack_a;
    while (temp->next != NULL)
	{
		if (b_value < (*stack_a)->number && (*stack_a)->number - b_value < t_target)
        {
            target = (*stack_a)->number;
            t_target = b_value - (*stack_a)->number;
            p = 1;
        }
		temp = temp->next;
	}
    if (p == 0)
        target = max;
}
void	ft_min_max_calculator(t_liste **stack_a, t_liste **stack_b, int *min, int *max)
{
	t_liste	*temp;

	temp = *stack_b;
    *min = temp->number;
    *max = temp->number;
    while (temp->next != NULL)
	{
		if (temp->number < *min)
            *min = temp->number;
        else if (temp->number > *max)
            *max = temp->number;
		temp = temp->next;
	}
}

void	ft_cost_calculator(t_liste **stack_a, t_liste **stack_b, int *min, int *max)
{
    

}