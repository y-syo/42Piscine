/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 07:57:52 by mmoussou          #+#    #+#             */
/*   Updated: 2023/07/27 11:04:12 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	seplen(char *str, int size)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (sizeof(char) * (i * (size - 1)));
}

char	*ft_strcat(char *dest, char *src)
{
	unsigned int	i;
	unsigned int	dest_size;

	i = 0;
	while (dest[i])
		i++;
	dest_size = i;
	i = 0;
	while (src[i])
	{
		dest[dest_size + i] = src[i];
		i++;
	}
	dest[dest_size + i] = '\0';
	return (dest);
}

int	malloc_size(int size, char **strs)
{
	int	i;
	int	j;
	int	rst;

	i = 0;
	rst = 0;
	while (i < size)
	{
		j = 0;
		while (strs[j])
			j++;
		rst += j;
		i++;
	}
	return (sizeof(char) * (rst + i));
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*fstr;
	int		i;

	i = 0;
	if (size == 0 || strs == NULL || sep == NULL)
	{
		fstr = malloc(sizeof(char));
		if (fstr == NULL)
			return (fstr);
		fstr[0] = 0;
		return (fstr);
	}
	fstr = malloc(malloc_size(size, strs) + seplen(sep, size) + sizeof(char));
	if (fstr == NULL)
		return (NULL);
	*fstr = 0;
	while (i < size)
	{
		ft_strcat(fstr, strs[i]);
		if (i < size - 1)
			ft_strcat(fstr, sep);
		i++;
	}
	return (fstr);
}
