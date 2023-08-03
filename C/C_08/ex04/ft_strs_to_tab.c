/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 17:41:13 by mmoussou          #+#    #+#             */
/*   Updated: 2023/07/27 19:03:25 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*rst;
	int		i;

	i = 0;
	rst = malloc(sizeof(src) * ft_strlen(src));
	if (rst == NULL)
		return (NULL);
	while (src[i])
	{
		rst[i] = src[i];
		i++;
	}
	rst[i] = '\0';
	return (rst);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*tab;
	int			i;

	tab = malloc(sizeof(t_stock_str) * (ac + 1));
	if (tab == NULL)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		tab[i].str = av[i];
		tab[i].size = ft_strlen(av[i]) - 1;
		tab[i].copy = ft_strdup(av[i]);
		i++;
	}
	tab[i].str = 0;
	return (tab);
}
