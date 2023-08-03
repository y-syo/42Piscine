/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 10:35:45 by mmoussou          #+#    #+#             */
/*   Updated: 2023/08/02 11:43:51 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_dectobase(int nb, char *base, char *r);

int		ft_baselen(int nbr, char *base);

void	ft_rev_str(char *str);

int	ft_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_find(char to_find, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == to_find)
			return (i);
		i++;
	}
	return (0);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	sign = 1;
	while (str[i] && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	result = 0;
	while (str[i])
	{
	result = (result * ft_len(base)) + (ft_find(str[i], base));
		i++;
	}
	return (result * sign);
}

int	ft_verif_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == 32
			|| (base[i] >= 9 && base[i] <= 13))
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

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		v;
	char	*r;

	if (ft_verif_base(base_from) || ft_verif_base(base_to))
		return (NULL);
	v = ft_atoi_base(nbr, base_from);
	r = malloc(sizeof(char) * ft_baselen(v, base_to));
	if (r == NULL)
		return (NULL);
	ft_dectobase(v, base_to, r);
	ft_rev_str(r);
	return (r);
}
