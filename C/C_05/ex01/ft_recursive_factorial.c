/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 08:29:34 by mmoussou          #+#    #+#             */
/*   Updated: 2023/07/21 17:37:41 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb > 1)
		return (nb * ft_recursive_factorial(nb - 1));
	else if (nb == 1 || nb == 0)
		return (1);
	return (0);
}
