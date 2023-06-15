/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 11:30:40 by mhoyer            #+#    #+#             */
/*   Updated: 2023/06/15 13:07:31 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_str_isdigit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) || (str[i] == '-' && !ft_isdigit(str[i + 1]))
			|| (str[i] == '+' && !ft_isdigit(str[i + 1])))
			return (0);
		i++;
	}
	return (1);
}

int	ft_isdigit(int c)
{
	if ((c < '0' || c > '9'))
		return (0);
	return (1);
}

int	ft_isdigit_sign_1(int space, int sign, int c)
{
	if (ft_isdigit(sign))
		return (1);
	if (sign != '-' && sign != '+')
		return (0);
	if (space != ' ')
		return (0);
	if (!ft_isdigit(c))
		return (0);
	return (1);
}

int	ft_isdigit_sign(int sign, int c)
{
	if (ft_isdigit(sign))
		return (1);
	if (sign != '-' && sign != '+')
		return (0);
	if (!ft_isdigit(c))
		return (0);
	return (1);
}
