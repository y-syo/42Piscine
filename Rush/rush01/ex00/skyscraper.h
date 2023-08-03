/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skyscraper.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 17:32:57 by kiroussa          #+#    #+#             */
/*   Updated: 2023/07/23 15:43:04 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SKYSCRAPER_H
# define SKYSCRAPER_H

# include <unistd.h>
# include <stdlib.h>

int		ft_parser(int ac, char **av, int ***inputs);

void	ft_error(char *reason);

int		ft_strlen(char *str);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_print_board(int **board, int size);

void	ft_optimize_line(int *line, int size, int bounds[2]);
void	ft_optimize(int **board, int **inputs, int size);

void	ft_optimize_completion(int *line, int size, int bounds[2]);
void	ft_optimize_bounds(int *line, int size, int bounds[2]);
void	ft_optimize_max_two(int *line, int size, int bounds[2]);
int		ft_is_solved(int **board, int **inputs, int size);
int		ft_check_views_colup(int **board, int **inputs, int size);
int		ft_check_views_coldown(int **board, int **inputs, int size);
int		ft_solve(int **board, int **inputs, int size);

void	ft_free_skyscraper(int **board, int **inputs, int size);

#endif
