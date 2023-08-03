/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 20:27:02 by mmoussou          #+#    #+#             */
/*   Updated: 2023/07/17 16:32:34 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_not_alphanum(char ch)
{
	if (!(ch >= 'A' && ch <= 'Z') && !(ch >= 'a' && ch <= 'z') && \
			!(ch >= '0' && ch <= '9'))
	{
		return (1);
	}
	return (0);
}

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] += 32;
		}
		i++;
	}
	return (str);
}

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] -= 32;
		}
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	nw;

	i = 0;
	nw = 1;
	while (str[i])
	{
		if (!(ft_is_not_alphanum(str[i])) && nw)
		{
			ft_strupcase(&str[i]);
			nw = 0;
		}
		else if (ft_is_not_alphanum(str[i]))
			nw = 1;
		else
		{
			ft_strlowcase(&str[i]);
		}
		i++;
	}
	return (str);
}

#include <stdio.h>

int main()
{
    char    str[100] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+ET+un";
	ft_strcapitalize(str);
    printf("%s", str);
    return 0;
}
