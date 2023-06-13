/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 09:14:26 by mhoyer            #+#    #+#             */
/*   Updated: 2023/06/13 11:08:06 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	first_step(t_list **a, t_list **b, t_list *mediane, int val)
{
	int	below;
	int	content;

	below = mediane->below;
	content = mediane->content;
	while (below >= 0)
	{
		if ((*a)->content <= content)
		{
			push_b(a, b);
			below--;
		}
		else if (check_way(*a, find_next(*a, below)) && val)
			reverse_rotate_a(a);
		else
			rotate_a(a);
	}
}

int	second_step_annexe(t_list **a, t_list **b, int value, t_list *mem)
{
	if ((*b)->next == mem)
	{
		swap_b(b);
		push_a(b, a);
		value--;
	}
	else if (check_way(*b, find_next_last(*b, mem->below)))
		reverse_rotate_b(b);
	else
		rotate_b(b);
	return (value);
}

void	second_step(t_list **a, t_list **b)
{
	t_list	*parc;
	t_list	*mem;
	int		value;

	parc = *b;
	value = 1;
	mem = *b;
	while (parc)
	{
		if (mem->below < parc->below)
			mem = parc;
		parc = parc->next;
	}
	while (value)
	{
		if ((*b) == mem)
		{
			push_a(b, a);
			value--;
		}
		else
			value = second_step_annexe(a, b, value, mem);
	}
}

void	sort(t_list **a, t_list **b)
{
	int taille_pack;

	if (ft_lstsize(*a) <= 6)
	{
		mini_sort(a, b, 'a');
		return ;
	}
	taille_pack = ft_lstsize(*a) / 10;
	while ((*a))
	{
		calc_above_below(a);
		first_step(a, b, find_mediane(*a, taille_pack), 0);
	}
	while (*b)
	{
		calc_above_below(b);
		second_step(a, b);
	}
}