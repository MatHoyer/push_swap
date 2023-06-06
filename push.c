/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:23:48 by mhoyer            #+#    #+#             */
/*   Updated: 2023/06/06 11:38:43 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **move, t_list **to)
{
	t_list	*tmp;

	tmp = *move;
	ft_lstadd_front(to, ft_lstnew((*move)->content));
	*move = (*move)->next;
	ft_lstdelone(tmp);
}
