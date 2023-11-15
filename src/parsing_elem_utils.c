/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_elem_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvisouth <kvisouth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 18:00:24 by kvisouth          #+#    #+#             */
/*   Updated: 2023/11/15 16:21:32 by kvisouth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// This function will skip all the lines but will free the lines as well
void	skip_lines_end(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
	}
}

// This function will skip all the lines but will not free the lines
void	skip_lines(int fd)
{
	while (get_next_line(fd) != NULL)
		;
}

// This function will skip all the spaces in a line
void	skip_spaces(char *line, int *i)
{
	if (line == NULL)
		return ;
	if (line[*i] == '\0')
		return ;
	if (line[*i] == '\n')
		return ;
	while (line[*i] == ' ')
	{
		if (line[*i] == '\0')
			return ;
		(*i)++;
	}
}

// This function will free a char ** AND free the array itself
void	free_array(char	**array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

// This function initializes elem_lines.
void	init_t_parse(t_game *game)
{
	game->parse.elem_lines[0] = 0;
	game->parse.elem_lines[1] = 0;
	game->parse.elem_lines[2] = 0;
	game->parse.elem_lines[3] = 0;
	game->parse.elem_lines[4] = 0;
	game->parse.elem_lines[5] = 0;
}
