/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 09:08:16 by mhoyer            #+#    #+#             */
/*   Updated: 2023/06/13 11:39:45 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

int		check_tri(t_list *a);

void	calc_above_below(t_list **lst);
t_list	*find_mediane(t_list *lst, int taille_pac);
t_list	*find_next(t_list *lst, int seektaille);
t_list	*find_next_last(t_list *lst, int seektaille);
int		check_way(t_list *lst, t_list *elem);

void	rotate_a(t_list **a);
void	reverse_rotate_a(t_list **a);
void	push_a(t_list **b, t_list **a);
void	swap_a(t_list **a);

void	rotate_b(t_list **b);
void	reverse_rotate_b(t_list **b);
void	push_b(t_list **a, t_list **b);
void	swap_b(t_list **b);

int		printf_error(char *str);
void	free_lst(t_list *lst);
void	free_av(char **av);

t_list	*init(int ac, char **av, int end);

void	mini_sort_inv(t_list **lst, char ft);

void	mini_sort(t_list **aa, t_list **b, char ft);

t_list	*parsing(int ac, char **av);

void	push(t_list **move, t_list **to);

void	reverse_rotate(t_list **top);
void	rotate(t_list **top);
void	rotate_both(t_list **top_a, t_list **top_b);
void	reverse_rotate_both(t_list **top_a, t_list **top_b);

void	sort(t_list **a, t_list **b);

void	swap(t_list **top);
void	swap_both(t_list **top_a, t_list **top_b);

#endif