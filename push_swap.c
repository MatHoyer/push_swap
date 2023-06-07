/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 09:18:15 by mhoyer            #+#    #+#             */
/*   Updated: 2023/06/07 14:26:27 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	check_tri(t_list *a)
// {
// 	while (a->next)
// 	{
// 		if (a->content > a->next->content)
// 			return (1);
// 		a = a->next;
// 	}
// 	return (0);
// }

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

// void	test_step(t_list **a, t_list **b, t_list *mediane)
// {
// 	int	below;
// 	int	content;

// 	below = mediane->below;
// 	content = mediane->content;
// 	while (below >= 0)
// 	{
// 		if ((*b)->content <= content)
// 		{
// 			ft_printf("pa\n");
// 			push(b, a);
// 			below--;
// 		}
// 		else if (check_way(*b, find_next(*b, below)))
// 		{
// 			ft_printf("rrb\n");
// 			reverse_rotate(b);
// 		}
// 		else
// 		{
// 			ft_printf("rb\n");
// 			rotate(b);
// 		}
// 	}
// }

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
		else if ((*b)->next == mem)
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
	}
}

void	tri(t_list **a, t_list **b)
{
	int taille_pack;

	taille_pack = ft_lstsize(*a) / 10;
	while ((*a))
	{
		calc_above_below(a);
		first_step(a, b, find_mediane(*a, taille_pack), 0);
	}
	// while (*b)
	// {
	// 	calc_above_below(b);
	// 	test_step(a, b, find_mediane(*b, 15));
	// }
	// while (*a)
	// {
	// 	calc_above_below(a);
	// 	first_step(a, b, find_mediane(*a, 5), 1);
	// }
	while (*b)
	{
		calc_above_below(b);
		second_step(a, b);
	}
}

