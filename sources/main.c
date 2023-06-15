/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 09:00:05 by mhoyer            #+#    #+#             */
/*   Updated: 2023/06/15 12:34:40 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	affiche(t_list *a, t_list *b)
{
	while (a || b)
	{
		if (!a)
			ft_printf("  ");
		else
		{
			ft_printf("%d ", a->content);
			a = a->next;
		}
		if (!b)
			ft_printf(" \n");
		else
		{
			ft_printf("%d\n", b->content);
			b = b->next;
		}
	}
	ft_printf("― ―\n");
}

int	check_av_vide(char *av)
{
	int	i;

	i = -1;
	while (av[++i])
	{
		if (av[i] != ' ')
			return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	if (ac < 2)
		exit(printf_error("Error"));
	if (ac == 2)
	{
		if (av[1][0] == '\0')
			return (0);
		if (check_av_vide(av[1]))
			return (0);
	}
	a = parsing(ac, av);
	if (!a)
		return (0);
	if (check_tri(a))
		sort(&a, &b);
	free_lst(a);
	return (0);
}
