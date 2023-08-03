/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_dict.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 15:33:23 by lauger            #+#    #+#             */
/*   Updated: 2023/07/30 16:16:47 by rgramati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/utils.h"
#include "../includes/rush02.h"

t_dict	ft_new_entry(int nb, char *word)
{
	t_dict	elem;

	elem.key = nb;
	elem.value = word;
	return (elem);
}

t_dict	*ft_init_dict(char **file)
{
	int		i;
	int		nb;
	char	*word;
	t_dict	*dict;

	word = NULL;
	nb = 0;
	i = 0;
	dict = malloc(sizeof(t_dict) * (ft_strlen(*file) + 1));
	while (file[i] != 0)
	{
		ft_format(file[i], &nb, &word);
		if (word == NULL)
			return (dict);
		if (nb != -1)
			dict[i] = ft_new_entry(nb, word);
		i++;
	}
	dict[i] = ft_new_entry(-1, 0);
	return (dict);
}
