/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 13:10:31 by mhoyer            #+#    #+#             */
/*   Updated: 2023/06/07 15:40:40 by mhoyer           ###   ########.fr       */
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
		}
		if (ft_atoi(av[num]) > 2147483647
			|| ft_atoi(av[num]) < -2147483648)
			exit(ft_printf("Erreur\n"));
		num++;
	}
}

char	**check_av(char *av)
{
	char	**new_av;
	int		i;
	int		check;

	i = -1;
	check = 0;
	while (av[++i])
	{
		if (av[i] == ' ')
			check = 1;
		else if (!ft_isdigit(av[i]) && av[i] != '-')
			exit(ft_printf("Error\n"));
	}
	if (!check)
		exit(ft_printf("Error\n"));
	new_av = ft_split(av, ' ');
	return (new_av);
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

t_list	*check_error(int ac, char **av)
{
	t_list	*pile;
	int		check;

	check = 0;
	if (ac != 2)
	{
		check_digit(ac, av);
		pile = init(ac, av, 1);
	}
	else
	{
		av = check_av(av[1]);
		pile = init(ft_strlen_mat(av), av, 0);
		check = 1;
	}
	check_doublon(pile);
	if (check)
		free_av(av);
	return (pile);
}
