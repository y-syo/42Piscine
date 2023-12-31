/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 08:16:09 by mmoussou          #+#    #+#             */
/*   Updated: 2023/07/21 17:35:07 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	rst;

	rst = 1;
	if (nb < 0)
		return (0);
	while (nb > 0)
	{
		rst *= nb;
		nb--;
	}
	return (rst);
}
