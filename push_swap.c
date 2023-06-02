/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 09:18:15 by mhoyer            #+#    #+#             */
/*   Updated: 2023/05/24 09:18:19 by mhoyer           ###   ########.fr       */
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

int	part(t_list **a, t_list **b, int pivot)
{
	if ((*a)->content < pivot)
	{
		rotate(a);
		ft_printf("ra\n");
	}
	else if ((*a)->content > pivot)
	{
		push(a, b);
		ft_printf("pa\n");
	}
	else
	{
		rotate(a);
		ft_printf("ra\n");
		while (*b)
		{
			push(b, a);
			ft_printf("pb\n");
			rotate(a);
			ft_printf("ra\n");
		}
		return (0);
	}
	return (1);
}

void	tri(t_list **a, t_list **b)
{
	int piv = ft_lstlast(*a)->content;
	//while (check_tri(*a))
	//{	
		while (part(a, b, piv))
		{
		}
	//}
}

