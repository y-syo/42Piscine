/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 14:00:12 by mmoussou          #+#    #+#             */
/*   Updated: 2023/08/02 15:57:11 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#define BUFFER_SIZE 16384

t_error	ft_read_file(int fd, char **contents, size_t *size)
{
	char	buffer[BUFFER_SIZE];
	size_t	nread;
	size_t	content_size;

	content_size = 0;
	while (1)
	{
		nread = read(fd, &buffer, BUFFER_SIZE);
		if (nread <= 0)
			break ;
		*contents = ft_append(*contents, content_size, buffer, nread);
		content_size += nread;
	}
	*size = content_size;
	if (nread < 0)
		return (ERR);
	return (OK);
}
