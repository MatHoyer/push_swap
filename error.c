/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 13:10:31 by mhoyer            #+#    #+#             */
/*   Updated: 2023/05/24 13:10:32 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_doublon(t_list *pile)
{
	t_list	*a_check;
	t_list	*parc;

	a_check = pile;
	while (a_check->next)
	{
		parc = a_check->next;
		while (parc)
		{
			if (parc->content == a_check->content)
				exit(ft_printf("Erreur\n"));
			parc = parc->next;
		}
		a_check = a_check->next;
	}
}
#include <stdio.h>
void	check_digit(int ac, char **av)
{
	int	i;
	int	num;

	num = 1;
	while (num < ac)
	{
		i = 0;
		while (av[num][i])
		{
			if (i == 0 && av[num][i] == '-')
				i++;
			if (!ft_isdigit(av[num][i]))
				exit(ft_printf("Erreur\n"));
			i++;
			printf("(%ld)", ft_atoi(av[num]));
			if (ft_atoi(av[num]) > 2147483647 ||
				ft_atoi(av[num]) < -2147483648)
				exit(ft_printf("Erreur\n"));
		}
		num++;
	}
}

t_list	*check_error(int ac, char **av)
{
	t_list	*pile;

	check_digit(ac, av);
	pile = init(ac, av);
	check_doublon(pile);
	return (pile);
}
