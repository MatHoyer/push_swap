/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 09:17:30 by mhoyer            #+#    #+#             */
/*   Updated: 2023/06/13 12:03:03 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mini_sort_2(t_list **a, char ft)
{
	if ((*a)->content > (*a)->next->content)
	{
		swap(a);
		ft_printf("s%c\n", ft);
	}
}

void	mini_sort_3(t_list **a, char ft)
{
	if ((*a)->content > (*a)->next->content)
	{
		swap(a);
		ft_printf("s%c\n", ft);
	}
	if ((*a)->next->content > (*a)->next->next->content)
	{
		reverse_rotate(a);
		ft_printf("rr%c\n", ft);
	}
	if ((*a)->content > (*a)->next->content)
	{
		swap(a);
		ft_printf("s%c\n", ft);
	}
}

void	mini_sort(t_list **a, t_list **b, char ft);

void	mini_sort_else(t_list **a, t_list **b)
{
	t_list	*med;
	int		taille_pac;
	int		comp;

	calc_above_below(a);
	taille_pac = ft_lstsize(*a) / 2;
	med = find_mediane(*a, taille_pac);
	comp = 0;
	while (comp != taille_pac)
	{
		if ((*a)->content < med->content)
		{
			push_b(a, b);
			comp++;
		}
		else
			rotate_a(a);
	}
	mini_sort(a, b, 'a');
	mini_sort_inv(b, 'b');
	while (*b)
		push_a(b, a);
}

void	mini_sort(t_list **a, t_list **b, char ft)
{
	int	taille;

	taille = ft_lstsize(*a);
	if (taille == 2)
		mini_sort_2(a, ft);
	else if (taille == 3)
		mini_sort_3(a, ft);
	else
		mini_sort_else(a, b);
}
