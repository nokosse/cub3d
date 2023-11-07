/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvisouth <kvisouth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:21:53 by kvisouth          #+#    #+#             */
/*   Updated: 2023/11/07 17:35:12 by kvisouth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// Allowed functions :
// open, close, read, write, printf, malloc
// free, perror, strerror, exit
// all the lib math (-lm man man 3 math)
// all the mlx functions

# include "../libft/inc/libft.h"
# include "../libft/inc/get_next_line.h"
# include "../libft/inc/ft_printf.h"
# include "../minilibx-linux/mlx.h"
# include "defines.h"
# include "structs.h"

# include <math.h>
# include <stdio.h>     // printf
# include <stdlib.h>    // malloc, free, exit
# include <unistd.h>    // open, read, write, close
# include <string.h>    // strerror
# include <errno.h>     // perror

// PARSING FUNCTIONS
int		ft_parse(int ac, char **av, t_game *game);
int		argument_check(int ac, char **av);
int		parse_map_info(t_game *game);
void	skip_lines(int fd);
void	skip_lines_end(int fd);
void	skip_spaces_tabs(char *line, int *i);
void	free_array(char	**array);
int		parse_rgb(char *str, t_game *game, char *elem);

#endif