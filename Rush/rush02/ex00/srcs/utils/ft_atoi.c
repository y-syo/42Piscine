/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgramati <rgramati@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 13:22:23 by rgramati          #+#    #+#             */
/*   Updated: 2023/07/30 11:09:47 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	i;
	int	sum;

	i = 0;
	sum = -1;
	while ((str[i] >= 8 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			return (-1);
		i++;
	}
	if (str[i] >= '0' && str[i] <= '9')
		sum = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		sum = sum * 10;
		sum = sum + str[i] - 48;
		i++;
	}
	return (sum);
}
