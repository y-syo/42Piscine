/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 14:51:38 by mmoussou          #+#    #+#             */
/*   Updated: 2023/07/18 15:40:30 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	if (size == 0)
	{
		i = 0;
		while (src[i])
			i++;
		return (i);
	}
	i = 0;
	while (src[i] && i < size)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < size)
		dest[i] = '\0';
		i++;
	return (i);
}
