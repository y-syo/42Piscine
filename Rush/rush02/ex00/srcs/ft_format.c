/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 12:05:53 by mmoussou          #+#    #+#             */
/*   Updated: 2023/07/30 15:11:45 by rgramati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/utils.h"
#include "../includes/rush02.h"

int	ft_is_not_space(char a)
{
	if (a != ' ' && !(a <= 13 && a >= 7))
		return (1);
	return (0);
}

int	ft_atoa_len(char *str)
{
	int	i;
	int	c;
	int	bool_c;

	i = 0;
	c = 0;
	bool_c = 0;
	while (str[i])
	{
		if (ft_is_not_space(str[i]))
		{
			bool_c = 1;
			c++;
		}
		else if (bool_c)
		{
			bool_c = 0;
			c++;
		}
		i++;
	}
	return (c);
}

char	*ft_trim(char *str)
{
	int		i;
	int		ri;
	int		bool_c;
	char	*r;

	i = 0;
	ri = 0;
	bool_c = 0;
	r = malloc(sizeof(char) * (ft_atoa_len(str) + 1));
	while (str[i])
	{
		if (ft_is_not_space(str[i]))
		{
			r[ri++] = str[i];
			bool_c = 1;
		}
		else if (bool_c)
		{
			r[ri++] = ' ';
			bool_c = 0;
		}
		i++;
	}
	r[ri] = '\0';
	return (r);
}

void	ft_format(char *str, int *nb, char **name)
{
	int	i;

	*nb = ft_atoi(str);
	i = 0;
	while (str[i] != ':' && str[i])
		i++;
	if (str[i])
		*name = ft_trim(&str[i + 1]);
}
