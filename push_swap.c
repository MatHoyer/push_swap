/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 09:18:15 by mhoyer            #+#    #+#             */
/*   Updated: 2023/06/07 10:31:21 by mhoyer           ###   ########.fr       */
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

// t_list	*find_mediane(t_list *lst)
// {
// 	t_list	*mem;
// 	int		min;
// 	int		tmp;

// 	min = ft_lstsize(lst);
// 	while (lst)
// 	{
// 		tmp = lst->above - lst->below;
// 		if (tmp < 0)
// 			tmp = -tmp;
// 		if (tmp < min)
// 		{
// 			min = tmp;
// 			mem = lst;
// 		}
// 		lst = lst->next;
// 	}
// 	return (mem);
// }

t_list	*find_mediane(t_list *lst)
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
	seektaille = ft_lstsize(lst) / 10;
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

int	check_way(t_list *lst, t_list *elem)
{
	int	count;

	count = 0;
	while (lst != elem)
	{
		lst = lst->next;
		count++;
	}
	if (count > ft_lstsize(lst) / 2)
		return (1);
	return (0);
}

void	first_step(t_list **a, t_list **b, t_list *mediane)
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
		// else if (check_way(*a, find_next(*a, below)))
		// {
		// 	ft_printf("rra\n");
		// 	reverse_rotate(a);
		// }
		else
		{
			ft_printf("ra\n");
			rotate(a);
		}
	}
}

void	second_step(t_list **a, t_list **b)
{
	t_list	*parc;
	t_list	*mem;
	int		value;
	int		memr;

	parc = *b;
	value = 1;
	memr = 0;
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
		else if ((*b)->next == mem)
		{
			swap(b);
			push(b, a);
			value--;
			ft_printf("sb\n");
			ft_printf("pa\n");
		}
		else
		{
			rotate(b);
			memr++;
			ft_printf("rb\n");
		}
	}
	while (memr)
	{
		reverse_rotate(b);
		memr--;
		ft_printf("rrb\n");
	}
	
}

void	tri(t_list **a, t_list **b)
{
	while ((*a))
	{
		calc_above_below(a);
		first_step(a, b, find_mediane(*a));
	}
	while (*b)
	{
		calc_above_below(b);
		second_step(a, b);
	}
}

