/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ratoi_ull.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 18:49:58 by kiroussa          #+#    #+#             */
/*   Updated: 2023/08/01 16:16:49 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ratoi_ull(char *str, unsigned long *resptr)
{
	unsigned long	result;
	int				i;
	unsigned long	new;

	result = 0;
	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] && (str[i] == '+' || str[i] == '-'))
		if (str[i++] == '-')
			return (3);
	if (str[i] && (str[i] == '+' || str[i] == '-'))
		return (2);
	while (str[i] && ft_isdigit(str[i]))
	{
		new = result * 10 + (str[i] - '0');
		if (new < result)
			return (4);
		result = new;
		i++;
	}
	*resptr = result;
	return (str[i] && str[i] != '\0');
}
