/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 09:51:12 by mhoyer            #+#    #+#             */
/*   Updated: 2023/05/24 09:51:13 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*init(int ac, char **av)
{
	t_list	*lst;
	int		i;

	lst = NULL;
	i = ac - 1;
	while (i > 0)
	{
		ft_lstadd_front(&lst, ft_lstnew((int)ft_atoi(av[i])));
		i--;
	}
	return (lst);
}
