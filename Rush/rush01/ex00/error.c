/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 09:50:47 by brguicho          #+#    #+#             */
/*   Updated: 2023/07/22 19:40:10 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "skyscraper.h"

#define BETTER_ERROR 1

#if BETTER_ERROR

void	ft_error(char *reason)
{
	ft_putstr("An unexpected error occured.\n\t");
	ft_putstr(reason);
}

#else

void	ft_error(char *reason)
{
	(void) reason;
	ft_putstr("Error!\n");
}

#endif
