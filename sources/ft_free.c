/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 09:01:27 by mhoyer            #+#    #+#             */
/*   Updated: 2023/06/13 11:59:58 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	printf_error(char *str)
{
	ft_putendl_fd(str, 2);
	return (1);
}

void	free_lst(t_list *lst)
{
	t_list	*tmp;

	while (lst)
	{
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
}

void	free_av(char **av)
{
	int	i;

	i = -1;
	while (av[++i])
	{
		free(av[i]);
	}
	free(av);
}
