/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 20:42:34 by mmoussou          #+#    #+#             */
/*   Updated: 2023/07/13 10:11:50 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	prints(int a, int b)
{
	write(1, &(char){a / 10 + 48}, 1);
	write(1, &(char){a % 10 + 48}, 1);
	write(1, " ", 1);
	write(1, &(char){b / 10 + 48}, 1);
	write(1, &(char){b % 10 + 48}, 1);
	if (a != 98)
	{
		write(1, ", ", 2);
	}
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	while (a <= 99)
	{
		b = a + 1;
		while (b <= 99)
		{
			prints(a, b);
			b++;
		}
		a++;
	}
}
