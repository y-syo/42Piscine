/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 12:54:54 by kiroussa          #+#    #+#             */
/*   Updated: 2023/08/01 14:20:16 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# include "libft.h"
# include "board.h"
# include "error.h"

# define MAP_ERROR "map error\n"

t_error	ft_read_file(int fd, char **contents, size_t *size);

#endif
