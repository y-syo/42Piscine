/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 08:37:18 by mmoussou          #+#    #+#             */
/*   Updated: 2023/07/19 08:54:46 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	rst;

	if (power < 0)
		return (0);
	rst = 1;
	while (power)
	{
		rst *= nb;
		power--;
	}
	return (rst);
}
