/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_b.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 10:16:13 by mhoyer            #+#    #+#             */
/*   Updated: 2023/06/13 10:19:38 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_b(t_list **b)
{
	rotate(b);
	ft_printf("rb\n");
}

void	reverse_rotate_b(t_list **b)
{
	reverse_rotate(b);
	ft_printf("rrb\n");
}

void	push_b(t_list **a, t_list **b)
{
	push(a, b);
	ft_printf("pb\n");
}

void	swap_b(t_list **b)
{
	swap(b);
	ft_printf("sb\n");
}
