/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_info.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvisouth <kvisouth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:28:34 by kvisouth          #+#    #+#             */
/*   Updated: 2023/10/27 16:55:37 by kvisouth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	store_elem(char	*path, t_game *game, char *elem)
{
	if (elem[0] == 'N' && elem[1] == 'O')
		game->no = path;
	else if (elem[0] == 'S' && elem[1] == 'O')
		game->so = path;
	else if (elem[0] == 'W' && elem[1] == 'E')
		game->we = path;
	else if (elem[0] == 'E' && elem[1] == 'A')
		game->ea = path;
	else if (elem[0] == 'F' || elem[0] == 'C')
		parse_rgb(path, game, elem);
}

// This function will store the string (elem) in t_game.
// It will store every character until it encounters a space, tab, \n or \0.
static int	get_path(char *str, t_game *game, char *elem)
{
	int		i;
	char	*path;
	char	*path_cpy;

	i = 0;
	while (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i] != '\0')
		i++;
	path = malloc(sizeof(char) * (i + 1));
	if (path == NULL)
		return (0);
	i = 0;
	while (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i] != '\0')
	{
		path[i] = str[i];
		i++;
	}
	path[i] = '\0';
	path_cpy = ft_strdup(path);
	free(path);
	store_elem(path_cpy, game, elem);
	return (1);
}

static int	process_element(char *line, t_game *game, char *elem, int *i)
{
	skip_spaces_tabs(line, i);
	if (line[*i] == elem[0] && line[*i + 1] == elem[1])
	{
		*i += 2;
		skip_spaces_tabs(line, i);
		if (line[*i] == '\0' || line[*i] == '\n')
			return (0);
		if (get_path(&line[*i], game, elem) == 0)
			return (0);
		return (1);
	}
	return (0);
}

int	search_elem(int fd, char *elem, t_game *game)
{
	char	*line;
	int		result;
	int		i;

	line = NULL;
	i = 0;
	line = get_next_line(fd);
	if (line == NULL)
		return (0);
	while (line != NULL)
	{
		result = process_element(line, game, elem, &i);
		free(line);
		if (result == 1)
			return (1);
		line = get_next_line(fd);
		if (line == NULL)
			break ;
	}
	skip_lines(fd);
	if (line != NULL)
		free(line);
	return (0);
}

// This function will search for each element and store then in t_game.
// It will use get_next_line in a loop until it finds NO, then store it.
//
// For each lines in the file :
// We skip spaces and tabs until we find the first character of the element.
// When it finds an element, a 'N' for example, it will look for the second
// character, so the 'O' in this case. Then it will skip spaces and tabs util
// we encounter something else that is not a : space, tab, \n or \0.
// At this moment, it means that we have found the path of the texture.
// We store the content of the string (which is the path) to t_game.
// We store that string until we encounter a space, tab, \n or \0.
//
// Then it will use a loop with GNL again until the end of the file to avoid
// still reachable leaks.
// Then we do the same for  SO, WE, EA.

int	parse_map_info(t_game *game)
{
	int		fd;

	fd = open(game->map_name, O_RDONLY);
	if (fd == -1)
		return (0);
	if (search_elem(fd, "NO", game) == 0)
		return (close(fd), 0);
	if (search_elem(fd, "SO", game) == 0)
		return (close(fd), 0);
	if (search_elem(fd, "WE", game) == 0)
		return (close(fd), 0);
	if (search_elem(fd, "EA", game) == 0)
		return (close(fd), 0);
	if (search_rgb(fd, "F", game) == 0)
		return (close(fd), 0);
	if (search_rgb(fd, "C", game) == 0)
		return (close(fd), 0);
	skip_lines_end(fd);
	close(fd);
	return (1);
}
