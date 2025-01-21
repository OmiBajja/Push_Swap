/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obajja <obajja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 20:59:28 by obajja            #+#    #+#             */
/*   Updated: 2025/01/21 16:58:01 by obajja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstclear_push(t_liste **lst, t_liste **lst2)
{
	t_liste	*temp;

	while (*lst)
	{
		temp = (*lst)->next;
		free(*lst);
		*lst = temp;
	}
	while (*lst2)
	{
		temp = (*lst2)->next;
		free(*lst2);
		*lst2 = temp;
	}
}

t_liste	*ft_lstnew_push(int nb, int i)
{
	struct s_liste	*new_node;

	new_node = (t_liste *)malloc(sizeof(t_liste));
	if (!new_node)
		return (NULL);
	new_node->number = nb;
	new_node->index = i;
	new_node->next = NULL;
	return (new_node);
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	t;
	int	taille;
	int	f;

	taille = size - 1;
	f = 0;
	while (f <= taille)
	{
		i = 0;
		while (i < taille)
		{
			if (tab[i] > tab[i + 1])
			{
				t = tab[i + 1];
				tab[i + 1] = tab[i];
				tab[i] = t;
				i++;
			}
			else
				i++;
		}
		f++;
	}
}

int	ft_quartile(char **tab, int size)
{
	int	i;
	int	*arr;

	i = -1;
	arr = malloc(size * sizeof(int));
	if (!arr)
		return (-1);
	while (tab[++i])
		arr[i] = ft_atoi(tab[i]);
	ft_sort_int_tab(arr, size);
	return (arr[size - 3]);
}