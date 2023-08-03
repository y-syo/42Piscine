/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgramati <rgramati@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 11:18:53 by rgramati          #+#    #+#             */
/*   Updated: 2023/07/30 18:30:36 by rgramati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/utils.h"
#include "../includes/rush02.h"

void	ft_free_tab(char **tab)
{
	int i;
	
	i = 0;
	while (tab[i] != 0)
	{
		free(tab[i]);
		i++;
	}
}

int	ft_check_args(int ac, char **av, char **nb, char **dict_name)
{
	if (ac > 3 || ac < 2)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (ac == 3)
		*dict_name = av[1];
	*nb = av[ac - 1];
	if (ft_strlen(*nb) > 12)
	{
		write(2, "Dict Error\n", 11);
		return (0);
	}
	return (1);
}

void	ft_display(t_dict *dict, char *nb, int nb_len)
{
	int	i;
	int	bool_t;

	i = 0;
	while (nb[i] == '0')
		i++;
	if (!nb[i])
	{
		ft_get_word(dict, 0, 1);
		return ;
	}
	while (nb[i + 1])
	{
		ft_print_word(dict, nb, i, &bool_t);
		if (nb[i] == '1' && (nb_len - i - 1) % 3 == 1 && i != nb_len - 2)
			i++;
		i++;
	}
	if (nb[i - 1] != '1')
		ft_print_word(dict, nb, i, &bool_t);
}

int	main(int argc, char **argv)
{
	char	*nb;
	char	*dict_name;
	int		fd;
	char	**f_lines;
	t_dict	*dict;

	dict_name = "numbers.dict";
	if (!ft_check_args(argc, argv, &nb, &dict_name))
		return (-1);
	fd = open(dict_name, O_RDONLY);
	if (fd < 0)
	{
		write(2, "Error", 5);
		return (-1);
	}
	f_lines = ft_split_file(fd);
	dict = ft_init_dict(f_lines);
	ft_free_tab(f_lines);
	free(f_lines);
	ft_display(dict, nb, ft_strlen(nb));
	write(1, "\n", 1);
	return (0);
}
