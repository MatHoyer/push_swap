/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 09:05:52 by mhoyer            #+#    #+#             */
/*   Updated: 2023/06/13 09:46:48 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_doublon(t_list *pile)
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
				return (1);
			parc = parc->next;
		}
		a_check = a_check->next;
	}
	return (0);
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
				exit(printf_error("Error"));
			i++;
		}
		if (ft_atoi(av[num]) > 2147483647
			|| ft_atoi(av[num]) < -2147483648)
			exit(printf_error("Error"));
		num++;
	}
}

char	**check_av(char *av)
{
	char	**new_av;
	int		i;
	int		j;

	i = -1;
	new_av = ft_split(av, ' ');
	if (!new_av)
		exit(printf_error("Error"));
	if (ft_strlen_mat(new_av) == 1)
	{
		free_av(new_av);
		exit (0);
	}
	while (new_av[++i])
	{
		j = -1;
		while (new_av[i][++j])
			if (!ft_isdigit(new_av[i][j]) || ft_atoi(new_av[i]) > INT_MAX
			|| ft_atoi(new_av[i]) < INT_MIN)
			{
				free_av(new_av);
				exit(printf_error("Error"));
			}
	}
	return (new_av);
}

t_list	*parsing(int ac, char **av)
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
	if (check)
		free_av(av);
	if (check_doublon(pile))
	{
		free_lst(pile);
		exit (printf_error("Error"));
	}
	return (pile);
}
