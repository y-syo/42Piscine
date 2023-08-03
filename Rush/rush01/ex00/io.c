/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 17:52:59 by kiroussa          #+#    #+#             */
/*   Updated: 2023/07/23 11:41:54 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "skyscraper.h"

void	ft_putstr(char *str)
{
	while (*str++)
		write(1, str - 1, 1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}

void	ft_free_skyscraper(int **board, int **inputs, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		free(inputs[i]);
		free(board[i]);
	}
	free(inputs);
	free(board);
}
