/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 08:29:40 by mmoussou          #+#    #+#             */
/*   Updated: 2023/07/26 07:08:12 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	return (rst);
}
