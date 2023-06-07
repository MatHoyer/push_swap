/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 14:24:02 by mhoyer            #+#    #+#             */
/*   Updated: 2023/06/07 14:25:43 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calc_above_below(t_list **lst)
{
	t_list	*parc;
	t_list	*cmp;

	parc = *lst;
	while (parc)
	{
		parc->below = 0;
		parc->above = 0;
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

t_list	*find_mediane(t_list *lst, int taille_pac)
{
	t_list	*mem;
	t_list	*start;
	int		seektaille;
	
	start = lst;
	while (start)
	{
		if (start->below == 0)
			mem = start;
		start = start->next;
	}
	seektaille = /*ft_lstsize(lst) /*/ taille_pac;
	while (lst)
	{
		if (lst->below > mem->below && lst->below <= seektaille)
			mem = lst;
		lst = lst->next;
	}
	return (mem);
}

t_list	*find_next(t_list *lst, int seektaille)
{
	while (lst)
	{
		if (lst->below <= seektaille)
			return (lst);
		lst = lst->next;
	}
	return (0);
}

t_list	*find_next_last(t_list *lst, int seektaille)
{
	while (lst)
	{
		if (lst->below == seektaille)
			return (lst);
		lst = lst->next;
	}
	return (0);
}

int	check_way(t_list *lst, t_list *elem)
{
	int	count;

	count = 0;
	while (lst != elem)
	{
		lst = lst->next;
		count++;
	}
	if (count >= ft_lstsize(lst) / 2)
		return (1);
	return (0);
}

