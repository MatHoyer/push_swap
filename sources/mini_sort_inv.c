/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort_inv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:35:56 by mhoyer            #+#    #+#             */
/*   Updated: 2023/06/13 11:39:58 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mini_sort_2_inv(t_list **a, char ft)
{
	if ((*a)->content < (*a)->next->content)
	{
		swap(a);
		ft_printf("s%c\n", ft);
	}
}

void	mini_sort_3_inv(t_list **a, char ft)
{
	if ((*a)->content < (*a)->next->content)
	{
		swap(a);
		ft_printf("s%c\n", ft);
	}
	if ((*a)->next->content < (*a)->next->next->content)
	{
		reverse_rotate(a);
		ft_printf("rr%c\n", ft);
	}
	if ((*a)->content < (*a)->next->content)
	{
		swap(a);
		ft_printf("s%c\n", ft);
	}
}

void	mini_sort_inv(t_list **lst, char ft)
{
	int	taille;

	taille = ft_lstsize(*lst);
	if (taille == 2)
		mini_sort_2_inv(lst, ft);
	else if (taille  == 3)
		mini_sort_3_inv(lst, ft);
}
