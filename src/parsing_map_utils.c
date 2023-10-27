/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvisouth <kvisouth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 18:00:24 by kvisouth          #+#    #+#             */
/*   Updated: 2023/10/27 17:00:00 by kvisouth         ###   ########.fr       */
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

void	skip_lines(int fd)
{
	while (get_next_line(fd) != NULL)
		;
}

void	skip_spaces_tabs(char *line, int *i)
{
	if (line == NULL)
		return ;
	if (line[*i] == '\0')
		return ;
	if (line[*i] == '\n')
		return ;
	while (line[*i] == ' ' || line[*i] == '\t')
	{
		if (line[*i] == '\0')
			return ;
		(*i)++;
	}
}
