/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 09:50:55 by mhoyer            #+#    #+#             */
/*   Updated: 2023/05/24 09:50:56 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_list **top)
{
	t_list	*tmp;
	t_list	*parc;

	if (ft_lstsize(*top) <= 1)
		return ;
	tmp = ft_lstlast(*top);
	parc = *top;
	while (parc->next->content != tmp->content)
		parc = parc->next;
	parc->next = NULL;
	tmp->next = *top;
	*top = tmp;
}

void	rotate(t_list **top)
{
	t_list	*tmp;
	t_list	*mem_second;

	if (ft_lstsize(*top) <= 1)
		return ;
	tmp = ft_lstlast(*top);
	mem_second = (*top)->next;
	(*top)->next = NULL;
	tmp->next = *top;
	*top = mem_second;
}

void	rotate_both(t_list **top_a, t_list **top_b)
{
	rotate(top_a);
	rotate(top_b);
}

void	reverse_rotate_both(t_list **top_a, t_list **top_b)
{
	reverse_rotate(top_a);
	reverse_rotate(top_b);
}
