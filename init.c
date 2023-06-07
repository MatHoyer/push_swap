/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 09:51:12 by mhoyer            #+#    #+#             */
/*   Updated: 2023/06/07 15:37:50 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*init(int ac, char **av, int end)
{
	t_list	*lst;
	int		i;

	lst = NULL;
	i = ac - 1;
	while (i >= end)
	{
		ft_lstadd_front(&lst, ft_lstnew((int)ft_atoi(av[i])));
		i--;
	}
	return (lst);
}
