/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 19:36:48 by mmoussou          #+#    #+#             */
/*   Updated: 2023/07/12 20:39:41 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	triple_print(char a, char b, char c)
{
	if (a != b && a != c && b != c)
	{
		write(1, &a, 1);
		write(1, &b, 1);
		write(1, &c, 1);
		if (a != '7')
		{
			write(1, ", ", 2);
		}
	}
}

void	ft_print_comb(void)
{
	char	a;
	char	b;
	char	c;

	a = '0';
	while (a <= '7')
	{
	b = a + 1;
		while (b <= '8')
		{
		c = b + 1;
			while (c <= '9')
			{
				triple_print(a, b, c);
			c++;
			}
		b++;
		}
	a++;
	}
}
