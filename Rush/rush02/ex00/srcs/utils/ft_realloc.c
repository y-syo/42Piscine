/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgramati <rgramati@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 16:00:35 by rgramati          #+#    #+#             */
/*   Updated: 2023/07/30 18:12:14 by rgramati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_realloc(char *ptr, int size)
{
	char	*new;
	int		i;	

	i = 0;
	if (ptr == NULL)
		return (NULL);
	new = malloc(size * sizeof(char));
	if (new == NULL)
		return (NULL);
	while (ptr[i])
	{
		new[i] = ptr[i];
		i++;
	}
	return (new);
}
