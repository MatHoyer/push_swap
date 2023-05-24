/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 09:08:16 by mhoyer            #+#    #+#             */
/*   Updated: 2023/05/24 09:08:17 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

t_list	*check_error(int ac, char **av);

t_list	*init(int ac, char **av);

t_list	*swap(t_list *top);
void	swap_both(t_list **top_a, t_list **top_b);

void	push(t_list **move, t_list **to);

t_list	*rotate(t_list *top);
t_list	*reverse_rotate(t_list *top);
void	rotate_both(t_list **top_a, t_list **top_b);
void	reverse_rotate_both(t_list **top_a, t_list **top_b);

#endif