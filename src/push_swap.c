/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obajja <obajja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 20:59:14 by obajja            #+#    #+#             */
/*   Updated: 2025/01/22 01:48:08 by obajja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long int	ft_atoi_long(const char *str)
{
	int			i;
	long int	n;
	int			s;

	i = 0;
	n = 0;
	s = 1;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' '))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-' && str[i])
			s *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + (str[i] - '0');
		i++;
	}
	return (n * s);
}

int	ft_lister(char **tab, t_liste **stack_a, t_liste **stack_b, int mediane)
{
	struct s_liste	*new_node;
	struct s_liste	*node;
	int				i;
	int				nb;

	i = 0;
	nb = 0;
	node = NULL;
	nb = ft_atoi(tab[i]);
	*stack_a = ft_lstnew_push(nb, i);
	if (!(*stack_a))
		return (-1);
	node = *stack_a;
	while (tab[++i])
	{
		nb = ft_atoi(tab[i]);
		new_node = ft_lstnew_push(nb, i);
		if (!new_node)
			return (-1);
		node->next = new_node;
		node = node->next;
	}
	nb = ft_quartile(tab, i, &mediane);
	node = *stack_a;
	i = -1;
	while (tab[++i])
	{
		//ft_printf("Index: %d, Numero: %d\n", node->index, node->number);
		node = node->next;
	}
	ft_sorting(stack_a, stack_b, mediane, nb);
	node = *stack_a;
	i = -1;
	ft_printf("\n\n");
	while (node)
	{
		//ft_printf("Stack A:\n");
		//ft_printf("Index: %d, Numero: %d\n", node->index, node->number);
		node = node->next;
	}
	node = *stack_b;
	i = -1;
	//ft_printf("\n\n");
	while (node)
	{
		//ft_printf("Stack B:\n");
		//ft_printf("Index: %d, Numero: %d\n", node->index, node->number);
		node = node->next;
	}
	return (0);
}

int	ft_check_digit(char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		if (j == 0 && tab[i][j] == '-' && tab[i][j + 1])
			j++;
		while (tab[i][j])
		{
			if (!ft_isdigit(tab[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_check_error(char **tab)
{
	char		**tester;
	long int	nb;
	int			i;
	int			j;

	tester = tab;
	i = -1;
	if (!ft_check_digit(tab))
		return (-1);
	while (tab[++i])
	{
		j = i;
		while (tester[++j])
		{
			if (ft_strncmp(tester[j], tab[i], 18) == 0)
				return (-2);
		}
	}
	while (i-- > 0)
	{
		nb = ft_atoi_long(tab[i]);
		if (nb > 2147483647)
			return (-3);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	char	**tab;
	int		i;
	t_liste	*stack_a;
	t_liste	*stack_b;

	i = -1;
	tab = NULL;
	stack_a = NULL;
	stack_b = NULL;
	if (argc == 2)
		tab = ft_split(argv[1], ' ');
	else if (argc > 2)
		tab = ft_strsdup(&argv[1], argc - 1);
	if (tab)
	{
		i = ft_check_error(tab);
		if (i < 0)
			ft_printf("Error: %d", i);
		else
			ft_lister(tab, &stack_a, &stack_b, i);
		ft_freestrs(tab);
		ft_lstclear_push(&stack_a, &stack_b);
		return (0);
	}
	return (1);
}
