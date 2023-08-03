/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 12:41:27 by lboiteux          #+#    #+#             */
/*   Updated: 2023/07/29 19:19:10 by rgramati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/utils.h"
#include "../includes/rush02.h"

char	**ft_split_file(int file_d)
{
	int		cpt;
	char	c;
	char	*str;
	char	*old_str;
	char	**split;

	cpt = read(file_d, &c, 1);
	str = malloc((cpt + 2) * sizeof(char));
	if (str == NULL)
		return (NULL);
	*str = c;
	split = NULL;
	while (read(file_d, &c, 1))
	{
		old_str = str;
		str = ft_realloc(old_str, cpt + 2);
		free(old_str);
		str[cpt] = c;
		cpt++;
	}
	str[cpt] = 0;
	split = ft_split(str, '\n');
	free(str);
	return (split);
}
