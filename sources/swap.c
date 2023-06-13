/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 09:50:23 by mhoyer            #+#    #+#             */
/*   Updated: 2023/05/24 09:50:24 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **top)
{
	t_list	*tmp;

	if (ft_lstsize(*top) <= 1)
		return ;
	tmp = (*top)->next;
	(*top)->next = tmp->next;
	tmp->next = *top;
	*top = tmp;
}

void	swap_both(t_list **top_a, t_list **top_b)
{
	swap(top_a);
	swap(top_b);
}
