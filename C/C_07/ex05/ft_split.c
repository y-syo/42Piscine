/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <malik.moussouni@proton.me>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:02:01 by mmoussou          #+#    #+#             */
/*   Updated: 2023/07/31 15:21:41 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_not_charset(char ch, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (ch == charset[i])
			return (0);
		i++;
	}
	return (1);
}

int	word_counter(char *str, char *charset)
{
	int	i;
	int	c;
	int	bool_c;

	i = 0;
	c = 0;
	bool_c = 1;
	while (str[i])
	{
		if (!is_not_charset(str[i], charset))
		{
			bool_c = 1;
		}
		else if (is_not_charset(str[i], charset) && bool_c)
		{
			c++;
			bool_c = 0;
		}
		i++;
	}
	return (c);
}

int	per_word_fill(char **result, char *str, char *charset)
{
	int	i;
	int	j;
	int	c;

	i = -1;
	j = 0;
	while (str[++i])
	{
		c = 0;
		while (is_not_charset(str[i], charset) && str[i])
		{
			c++;
			i++;
		}
		if (c != 0)
		{
			result[j] = malloc(sizeof(char) * c);
			if (result[j] == NULL)
				return (1);
			j++;
		}
	}
	result[j] = NULL;
	return (0);
}

void	ft_split_resolver(char **result, char *str, char *charset)
{
	int	i;
	int	j;
	int	wi;
	int	bool_w;

	i = -1;
	j = 0;
	wi = 0;
	bool_w = 0;
	while (str[++i])
	{
		if (!is_not_charset(str[i], charset) && bool_w)
		{
			bool_w = 0;
			wi = 0;
			j++;
		}
		if (is_not_charset(str[i], charset))
		{
			bool_w = 1;
			result[j][wi++] = str[i];
		}
	}
}

char	**ft_split(char *str, char *charset)
{
	char	**result;

	result = malloc(sizeof(char *) * (word_counter(str, charset) + 1));
	if (result == NULL)
		return (NULL);
	if (per_word_fill(result, str, charset))
		return (NULL);
	ft_split_resolver(result, str, charset);
	return (result);
}
