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
void				ft_sorting(t_liste **stack_a, t_liste **stack_b,
						int mediane, int quartile);
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
void				ft_push_a(t_liste **stack_a, t_liste **stack_b);
void				ft_push_b(t_liste **stack_a, t_liste **stack_b);
void				ft_min_max_calculator(t_liste **stack, int *min, int *max);
void				ft_target_in_b_calculator(int b_value, t_liste **stack_a,
						int max);
void				ft_target_in_b_calculator(int a_value, t_liste **stack_b,
						int max);
int					ft_quartile(char **tab, int size, int *mediane);
short				is_sorted(t_liste **stack_a);
int					get_closest_small(int mid, t_liste **stack);
int					ft_stacksize(t_liste *stack);
void				ft_3sorter(t_liste **stack_a);
int					get_index(int to_find, t_liste **stack);
void				ft_pushmax(t_liste **stack_a, t_liste **stack_b, int size);
void				ft_pushopti(t_liste **stack_a, t_liste **stack_b, int max,
						int index);
short				ft_relative_index(int index, int index2, int size);
void				ft_max_two_calculator(t_liste **stack, int max,
						int *max_two);
void				ft_firsthalf(t_liste **stack_a, t_liste **stack_b,
						int mediane, int quartile);
void				ft_secondhalf(t_liste **stack_a, t_liste **stack_b,
						int mediane, int quartile);

#endif
