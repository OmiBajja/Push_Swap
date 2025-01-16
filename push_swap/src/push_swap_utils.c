/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obajja <obajja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 20:59:28 by obajja            #+#    #+#             */
/*   Updated: 2025/01/15 13:38:17 by obajja           ###   ########.fr       */
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
