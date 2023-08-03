/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 11:31:28 by mmoussou          #+#    #+#             */
/*   Updated: 2023/07/27 20:10:51 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_len(char *src);

char	*ft_strcat(char *dest, char *src)
{
	unsigned int	i;
	unsigned int	dest_size;

	i = 0;
	while (dest[i])
		i++;
	dest_size = i;
	i = 0;
	while (src[i])
	{
		dest[dest_size + i] = src[i];
		i++;
	}
	dest[dest_size + i] = '\0';
	return (dest);
}

int	ft_baselen(int nbr, char *base)
{
	int	i;

	i = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
		i++;
	}
	while (nbr > 0)
	{
		nbr /= ft_len(base);
		i++;
	}
	return (i);
}

char	*ft_dectobase(int nbr, char *base, char *r)
{
	if (r == NULL)
		return (NULL);
	if (nbr == -2147483648)
	{
		r[0] = '-';
		r[1] = base[nbr % ft_len(base)];
		nbr /= ft_len(base);
		nbr *= -1;
		return (ft_dectobase (nbr, base, &r[2]));
	}
	if (nbr < 0)
	{
		nbr *= -1;
		r[0] = '-';
		return (ft_dectobase(nbr, base, &r[1]));
	}
	if (nbr < ft_len(base))
	{
		r[0] = base[nbr];
		return (r);
	}
	r[0] = base[nbr % ft_len(base)];
	return (ft_dectobase(nbr / ft_len(base), base, &r[1]));
}

void	ft_rev_str(char *str)
{
	int		i;
	char	temp;

	i = 0;
	if (str[0] == '-')
		ft_rev_str(&str[1]);
	else
	{
		while (i < ft_len(str) / 2)
		{
			temp = str[i];
			str[i] = str[ft_len(str) - i - 1];
			str[ft_len(str) - i - 1] = temp;
			i++;
		}
	}
}
