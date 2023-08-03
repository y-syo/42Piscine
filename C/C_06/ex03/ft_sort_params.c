/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:24:14 by mmoussou          #+#    #+#             */
/*   Updated: 2023/07/23 19:24:52 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void	ft_swap_str(char **argv, int i1, int i2)
{
	char	*temp;

	temp = argv[i1];
	argv[i1] = argv[i2];
	argv[i2] = temp;
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

void	ft_argv_sort(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[j + 1])
		{
			if (ft_strcmp(argv[j], argv[j + 1]) > 0)
				ft_swap_str(argv, j, j + 1);
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc < 2)
	{
		return (0);
	}
	ft_argv_sort(&argv[1]);
	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			write(1, &argv[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
