/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_displaytab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 18:53:38 by lauger            #+#    #+#             */
/*   Updated: 2023/07/29 19:15:32 by rgramati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/utils.h"
#include "../includes/rush02.h"

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
	}
	else if (nb < 0)
	{
		write(1, "-", 1);
		ft_putnbr(-nb);
	}
	else if (nb < 10)
	{
		write(1, &(char){nb + 48}, 1);
	}
	else
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

void	ft_displaytab(t_dict *dict)
{
	int		i;

	i = 0;
	while (dict[i].key != -1)
	{
		ft_putnbr(dict[i].key);
		write(1, "\n", 1);
		ft_putstr(dict[i].value);
		write(1, "\n", 1);
		i++;
	}
}
