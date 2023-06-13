/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 08:58:51 by mhoyer            #+#    #+#             */
/*   Updated: 2023/06/13 08:59:10 by mhoyer           ###   ########.fr       */
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