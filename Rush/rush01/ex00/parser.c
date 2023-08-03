/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 09:50:47 by brguicho          #+#    #+#             */
/*   Updated: 2023/07/23 15:43:29 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "skyscraper.h"

int	check_inputs(int argc, char **argv)
{
	int	index;

	index = 0;
	if (argc > 2 || argc == 1)
	{
		ft_error("Argument Error (too much arguments)\n");
		return (0);
	}
	while (argv[1][index])
	{
		if (!(argv[1][index] >= '1'
			&& argv[1][index] <= (ft_strlen(argv[1]) / 2) + 48)
			&& index % 2 == 0)
		{
			ft_error("Argument Error (bad argument)\n");
			return (0);
		}
		if (!(argv[1][index] == ' ') && index % 2 == 1)
		{
			ft_error("Argument Error (bad argument)\n");
			return (0);
		}
		index++;
	}
	return (1);
}

void	inputs_filler(int *size, char **av, int ***inputs)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	j = 0;
	c = *size;
	while (av[1][i] && j < *size)
	{
		(*inputs)[j][(i / 2) % *size] = av[1][i] - '0';
		i += 2;
		c--;
		if (c == 0)
		{
			j++;
			c = *size;
		}
	}
}

int	ft_parser(int ac, char **av, int ***inputs)
{
	int	i;
	int	size;

	if (check_inputs(ac, av))
	{
		size = ((ft_strlen(av[1]) + 1) / 4) / 2;
		(*inputs) = (int **) malloc(sizeof(int *) * size);
		i = 0;
		while (i < 4)
			(*inputs)[i++] = (int *) malloc(sizeof(int) * size);
		inputs_filler(&size, av, inputs);
		return (size);
	}
	return (0);
}
