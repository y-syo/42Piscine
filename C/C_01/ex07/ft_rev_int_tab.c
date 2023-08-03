/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 11:24:46 by mmoussou          #+#    #+#             */
/*   Updated: 2023/07/15 12:04:25 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	cur;
	int	temp;

	cur = 0;
	while (cur <= size / 2)
	{
		temp = tab[cur];
		tab[cur] = tab[size - cur];
		tab[size - cur] = temp;
		cur++;
	}
}
