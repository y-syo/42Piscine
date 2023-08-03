/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 23:28:18 by mmoussou          #+#    #+#             */
/*   Updated: 2023/07/19 13:05:48 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	dest_size;
	unsigned int	src_size;

	dest_size = 0;
	while (dest[dest_size])
		dest_size++;
	src_size = 0;
	while (src[src_size])
		src_size++;
	i = 0;
	while (src[i] && i < size - 1)
	{
		dest[dest_size + i] = src[i];
		i++;
	}
	dest[dest_size + i] = '\0';
	if (dest_size > src_size)
		return (src_size + size);
	return (dest_size + src_size);
}
