/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 09:18:15 by mhoyer            #+#    #+#             */
/*   Updated: 2023/06/12 13:44:03 by mhoyer           ###   ########.fr       */
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
			ft_printf("pb\n");
			push(a, b);
			below--;
		}
		else if (check_way(*a, find_next(*a, below)) && val)
		{
			ft_printf("rra\n");
			reverse_rotate(a);
		}
		else
		{
			ft_printf("ra\n");
			rotate(a);
		}
	}
}

int	second_step_annexe(t_list **a, t_list **b, int value, t_list *mem)
{
	if ((*b)->next == mem)
	{
		swap(b);
		push(b, a);
		value--;
		ft_printf("sb\n");
		ft_printf("pa\n");
	}
	else if (check_way(*b, find_next_last(*b, mem->below)))
	{
		ft_printf("rrb\n");
		reverse_rotate(b);
	}
	else
	{
		ft_printf("rb\n");
		rotate(b);
	}
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
			push(b, a);
			value--;
			ft_printf("pa\n");
		}
		else
			value = second_step_annexe(a, b, value, mem);
	}
}

void	mini_tri(t_list **a)
{
	t_list	*first;

	first = *a;
	while (check_tri(*a))
	{
		if ((*a)->content > (*a)->next->content && (*a)->next != first)
		{
			swap(a);
			ft_printf("sa\n");
		}
		else
		{
			rotate(a);
			ft_printf("ra\n");
		}
	}
}

void	tri(t_list **a, t_list **b)
{
	int taille_pack;

	if (ft_lstsize(*a) < 10)
	{
		mini_tri(a);
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

