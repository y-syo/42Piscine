/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 18:05:00 by mmoussou          #+#    #+#             */
/*   Updated: 2023/07/30 18:10:49 by rgramati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/utils.h"
#include "../includes/rush02.h"

void	ft_print_thousands(t_dict *dict, char *curr, int i, int *bool_triplet);

void	ft_get_word(t_dict *dict, int src_key, int is_last)
{
	int		i;
	char	*word;

	i = 0;
	while (dict[i].key != src_key)
		i++;
	word = dict[i].value;
	write(1, word, ft_strlen(word));
	if (!is_last)
		write(1, " ", 1);
}

void	ft_print_word(t_dict *dict, char *curr, int i, int *bool_triplet)
{
	int	mod_i;
	int	index;

	index = ft_strlen(curr) - i - 1;
	mod_i = index % 3;
	if (curr[i] != '0')
	{
		*bool_triplet = 1;
		if (mod_i != 1 && curr[i + 1])
			ft_get_word(dict, (int){curr[i] - 48}, 0);
		else if (mod_i != 1)
			ft_get_word(dict, (int){curr[i] - 48}, 1);
		else
		{
			if (curr[i] == '1')
				ft_get_word(dict, (int){10 * (curr[i] + curr[i + 1] - 96)}, 0);
			else
				ft_get_word(dict, (int){10 * (curr[i] - 48)}, 0);
		}
	}
	if (mod_i == 2 && curr[i] != '0')
		ft_get_word(dict, 100, 0);
	ft_print_thousands(dict, curr, i, bool_triplet);
}

int	ft_check_last_thousands(char *curr, int i)
{
	while (curr[i])
	{
		if (curr[i] != '0')
			return (0);
		i++;
	}
	return (1);
}

void	ft_print_thousands(t_dict *dict, char *curr, int i, int *bool_triplet)
{
	if ((ft_strlen(curr) -i -1) == 3 && *bool_triplet)
	{
		if (ft_check_last_thousands(curr, i))
			ft_get_word(dict, 1000, 1);
		else
			ft_get_word(dict, 1000, 0);
		*bool_triplet = 0;
	}
	if ((ft_strlen(curr) -i -1) == 6 && *bool_triplet)
	{
		if (ft_check_last_thousands(curr, i))
			ft_get_word(dict, 1000000, 1);
		else
			ft_get_word(dict, 1000000, 0);
		*bool_triplet = 0;
	}
	if ((ft_strlen(curr) -i -1) == 9 && *bool_triplet)
	{
		if (ft_check_last_thousands(curr, i))
			ft_get_word(dict, 1000000000, 1);
		else
			ft_get_word(dict, 1000000000, 0);
		*bool_triplet = 0;
	}
}
