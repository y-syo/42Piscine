/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgramati <rgramati@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 09:01:48 by rgramati          #+#    #+#             */
/*   Updated: 2023/07/30 09:04:11 by rgramati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

int		ft_strlen(char *str);
char	*ft_strcpy(char *str);
char	**ft_split(char *str, char sep);
void	*ft_realloc(void *ptr, int size);
int		ft_atoi(char *str);

#endif
