/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgramati <rgramati@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 11:17:12 by rgramati          #+#    #+#             */
/*   Updated: 2023/07/30 16:57:32 by rgramati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_dict
{
	int			key;
	char		*value;
}	t_dict;

char	**ft_split_file(int file_d);

void	ft_format(char *str, int *nb, char **name);

t_dict	ft_new_entry(int nb, char *word);
t_dict	*ft_init_dict(char **file);

void	ft_displaytab(t_dict *dict);

void	ft_print_word(t_dict *dict, char *curr, int i, int *bool_triplet);
void	ft_get_word(t_dict *dict, int src_key, int is_last);

#endif
