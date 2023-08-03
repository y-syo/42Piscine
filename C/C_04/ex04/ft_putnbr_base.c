/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 14:11:56 by mmoussou          #+#    #+#             */
/*   Updated: 2023/07/26 08:06:31 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_verif_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] <= 32)
			return (1);
		j = i + 1;
		while (base[j])
		{
			if (base[j] == base[i])
				return (1);
			j++;
		}
		i++;
	}
	if (i == 0 || i == 1)
		return (1);
	return (0);
}

void	ft_putnbr_base(int nbr, char *base)
{
	if (ft_verif_base(base))
	{
		return ;
	}
	if (nbr == -2147483648)
	{
		ft_putnbr_base(nbr / ft_strlen(base), base);
		write(1, &(char){base[nbr % ft_strlen(base)]}, 1);
		return ;
	}
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr *= -1;
	}
	if (nbr < ft_strlen(base))
	{
		write(1, &(char){base[nbr]}, 1);
	}
	else
	{
		ft_putnbr_base(nbr / ft_strlen(base), base);
		write(1, &(char){base[nbr % ft_strlen(base)]}, 1);
	}
}
