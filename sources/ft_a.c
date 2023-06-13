/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_a.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 10:12:43 by mhoyer            #+#    #+#             */
/*   Updated: 2023/06/13 10:22:36 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_list **a)
{
	rotate(a);
	ft_printf("ra\n");
}

void	reverse_rotate_a(t_list **a)
{
	reverse_rotate(a);
	ft_printf("rra\n");
}

void	push_a(t_list **b, t_list **a)
{
	push(b, a);
	ft_printf("pa\n");
}

void	swap_a(t_list **a)
{
	swap(a);
	ft_printf("sa\n");
}
