/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 14:01:49 by mmoussou          #+#    #+#             */
/*   Updated: 2023/07/26 08:06:48 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	return (-1);
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

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	sign;
	int	result;

	if (ft_verif_base(base))
		return (0);
	i = 0;
	while (str[i] == 32)
		i++;
	while ((str[i] >= 7 && str[i] <= 13))
		i++;
	sign = 1;
	while (str[i] && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	result = 0;
	while (str[i] && ft_find(str[i], base) != -1)
	{
		result = (result * ft_strlen(base)) + (ft_find(str[i], base));
		i++;
	}
	return (result * sign);
}
