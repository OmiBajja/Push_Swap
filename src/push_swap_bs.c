/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obajja <obajja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 20:59:14 by obajja            #+#    #+#             */
/*   Updated: 2025/02/13 16:06:53 by obajja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_findbs1(int *arr, int *q1, int i, int size)
{
	*q1 = arr[(size * i) / 20];
	return (arr[(size * i + 1) / 20]);
}

int	ft_findbs2(int *arr, int *q1, int *q3, int size)
{
	*q1 = arr[(size * 18) / 20];
	*q3 = arr[(size - 3)];
	return (arr[(size - 3)]);
}

int	ft_findbs_small(int *arr, int *q1, int i, int size)
{
	*q1 = arr[(size * i) / 8];
	return (arr[((size * i) / 8) + 1]);
}

int	ft_findbs_small2(int *arr, int *q1, int *q3, int size)
{
	*q1 = arr[(size * 7) / 8];
	*q3 = arr[(size - 3)];
	return (arr[(size - 4)]);
}
