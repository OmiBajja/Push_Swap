/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sorting_extra.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obajja <obajja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 20:59:14 by obajja            #+#    #+#             */
/*   Updated: 2025/02/14 00:37:04 by obajja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_big_sorter(t_liste **stack_a, t_liste **stack_b, int *array, int size)
{
	int	q1;
	int	i;
	int	mediane;
	int	n;

	i = 1;
	while (i < 18)
	{
		mediane = ft_findbs1(array, &q1, i, size);
		n = ft_firsthalf(stack_a, stack_b, mediane, q1);
		if (n == -1)
			return (free(array), 1);
		i++;
	}
	mediane = ft_findbs2(array, &q1, &i, size);
	n = ft_firsthalf(stack_a, stack_b, mediane, i);
	if (n == -1)
		return (free(array), 1);
	ft_3sorter(stack_a);
	ft_pushmax(stack_a, stack_b, -1, -1);
	return (0);
}

int	ft_medium_sorter(t_liste **stack_a, t_liste **stack_b, int *array, int size)
{
	int	q1;
	int	i;
	int	mediane;
	int	n;

	i = 1;
	while (i < 6)
	{
		mediane = ft_findbs_small(array, &q1, i, size);
		n = ft_firsthalf(stack_a, stack_b, mediane, q1);
		if (n == -1)
			return (free(array), 1);
		i++;
	}
	mediane = ft_findbs_small2(array, &q1, &i, size);
	n = ft_firsthalf(stack_a, stack_b, mediane, i);
	if (n == -1)
		return (free(array), 1);
	ft_3sorter(stack_a);
	ft_pushmax(stack_a, stack_b, -1, -1);
	return (0);
}

int	ft_medium_small_sorter(t_liste **stack_a, t_liste **stack_b, int *array,
		int size)
{
	int		mediane;
	int		quartile1;
	int		quartile2;
	short	n;

	mediane = ft_findmidthird(array, &quartile1, &quartile2, size);
	n = ft_firsthalf(stack_a, stack_b, mediane, quartile1);
	if (n == -1)
		return (-1);
	n = ft_lastthird(stack_a, stack_b, mediane, quartile2);
	if (n == -1)
		return (-1);
	ft_3sorter(stack_a);
	ft_pushmax(stack_a, stack_b, -1, -1);
	return (0);
}

int	ft_check_double(char **tab, int *tester)
{
	int	i;
	int	j;
	int	index;
	int	*tester2;

	i = -1;
	while (tab[++i])
		tester[i] = ft_atoi(tab[i]);
	tester2 = tester;
	index = i;
	i = -1;
	while (++i < index)
	{
		j = -1;
		while (++j < index)
		{
			if (i != j && tester2[j] == tester[i])
				return (-2);
		}
	}
	return (free(tester), 0);
}
