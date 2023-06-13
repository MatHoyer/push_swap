/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 09:00:05 by mhoyer            #+#    #+#             */
/*   Updated: 2023/06/13 11:20:56 by mhoyer           ###   ########.fr       */
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

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (ac < 2)
		return (1);
	a = parsing(ac, av);
	if (!a)
		return (0);
	//affiche(a, b);
	if (check_tri(a))
	{
		sort(&a, &b);
		//affiche(a, b);
	}
	free_lst(a);
	return (0);
}