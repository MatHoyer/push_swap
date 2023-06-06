/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 09:18:15 by mhoyer            #+#    #+#             */
/*   Updated: 2023/06/06 12:12:38 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_tri(t_list *a)
{
	while (a->next)
	{
		if (a->content > a->next->content)
			return (1);
		a = a->next;
	}
	return (0);
}

void	calc_above_below(t_list **lst)
{
	t_list	*parc;
	t_list	*cmp;

	parc = *lst;
	while (parc)
	{
		cmp = *lst;
		while (cmp)
		{
			if (cmp ->content > parc->content)
				parc->above++;
			else if (cmp ->content < parc->content)
				parc->below++;
			cmp = cmp->next;
		}
		parc = parc->next;
	}
}

t_list	*find_mediane(t_list *lst)
{
	t_list	*mem;
	int		min;
	int		tmp;

	min = ft_lstsize(lst);
	while (lst)
	{
		tmp = lst->above - lst->below;
		if (tmp < 0)
			tmp = -tmp;
		if (tmp < min)
		{
			min = tmp;
			mem = lst;
		}
		lst = lst->next;
	}
	return (mem);
}

void	tri(t_list **a, t_list **b)
{
	calc_above_below(a);
	calc_above_below(b);
	ft_printf("(%d)", find_mediane(*a)->content);
}

