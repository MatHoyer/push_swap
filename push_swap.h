/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 09:08:16 by mhoyer            #+#    #+#             */
/*   Updated: 2023/06/10 21:19:28 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

t_list	*check_error(int ac, char **av);

t_list	*init(int ac, char **av, int end);

void	swap(t_list **top);
void	swap_both(t_list **top_a, t_list **top_b);

void	push(t_list **move, t_list **to);

void	rotate(t_list **top);
void	reverse_rotate(t_list **top);
void	rotate_both(t_list **top_a, t_list **top_b);
void	reverse_rotate_both(t_list **top_a, t_list **top_b);

int		check_tri(t_list *a);
void	calc_above_below(t_list **lst);
t_list	*find_mediane(t_list *lst, int taille_pac);
t_list	*find_next(t_list *lst, int seektaille);
t_list	*find_next_last(t_list *lst, int seektaille);
int		check_way(t_list *lst, t_list *elem);

void	tri(t_list **a, t_list **b);

void	free_lst(t_list *lst);

#endif