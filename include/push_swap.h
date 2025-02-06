/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obajja <obajja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 20:59:14 by obajja            #+#    #+#             */
/*   Updated: 2025/02/05 15:50:08 by obajja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

typedef struct s_liste
{
	int				number;
	int				index;
	struct s_liste	*next;
}					t_liste;

void				ft_lstclear_push(t_liste **lst, t_liste **lst2);
t_liste				*ft_lstnew_push(int nb, int i);
void				ft_swapper(t_liste **stack);
short				ft_pusher(t_liste **stack_1, t_liste **stack_2);
short				ft_rotator(t_liste **stack);
short				ft_reverse_rotator(t_liste **stack);
int					ft_sorting(t_liste **stack_a, t_liste **stack_b, int *array,
						int size);
void				ft_index_decalator(t_liste **stack, int decal);
void				ft_rotate_rr(t_liste **stack_a, t_liste **stack_b);
void				ft_rotate_b(t_liste **stack_b);
void				ft_rotate_a(t_liste **stack_a);
void				ft_reverse_rotate_a(t_liste **stack_a);
void				ft_reverse_rotate_b(t_liste **stack_b);
void				ft_reverse_rotate_rr(t_liste **stack_a, t_liste **stack_b);
void				ft_swap_a(t_liste **stack_a);
void				ft_swap_b(t_liste **stack_b);
void				ft_swap_ss(t_liste **stack_a, t_liste **stack_b);
short				ft_push_a(t_liste **stack_a, t_liste **stack_b);
int					ft_push_b(t_liste **stack_a, t_liste **stack_b);
void				ft_min_max_calculator(t_liste **stack, int *min, int *max);
void				ft_target_in_b_calculator(int b_value, t_liste **stack_a,
						int max);
void				ft_target_in_b_calculator(int a_value, t_liste **stack_b,
						int max);
int					*ft_array(char **tab, int size);
short				is_sorted(t_liste **stack_a, int n);
int					get_closest_small(int mid, t_liste **stack);
int					ft_stacksize(t_liste *stack);
void				ft_3sorter(t_liste **stack_a);
int					get_index(int to_find, t_liste **stack);
void				ft_pushmax(t_liste **stack_a, t_liste **stack_b, int index2,
						int index);
void				ft_pushopti(t_liste **stack_a, t_liste **stack_b, int max,
						int index);
short				ft_relative_index(int index, int index2, int size);
void				ft_max_two_calculator(t_liste **stack, int max,
						int *max_two);
short				ft_firsthalf(t_liste **stack_a, t_liste **stack_b,
						int mediane, int quartile);
void				ft_secondhalf(t_liste **stack_a, t_liste **stack_b,
						int mediane, int quartile);
int					ft_findqoneqthree(int *arr, int *q1, int *q3, int size);
void				ft_firstquarter(t_liste **stack_a, t_liste **stack_b,
						int q1, int mediane);
int					ft_findmidthird(int *arr, int *q1, int *q3, int size);
int					ft_lastthird(t_liste **stack_a, t_liste **stack_b,
						int mediane, int quartile);
int					ft_findsmallest(int *arr, int *q1, int *q3, int size);
int					ft_lastchecker(t_liste **stack);
int					ft_small_sorter(t_liste **stack_a, t_liste **stack_b,
						int *array, int size);
int					ft_big_sorter(t_liste **stack_a, t_liste **stack_b,
						int *array, int size);
int					ft_most_opti(t_liste **stack_b, int max2, int max3, int max4);

#endif
