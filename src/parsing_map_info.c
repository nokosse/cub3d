/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_info.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvisouth <kvisouth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:28:34 by kvisouth          #+#    #+#             */
/*   Updated: 2023/10/26 17:32:39 by kvisouth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// Reminder :
// GNL is a function that reads a file line by line.
// We read the file until we find a \n or the end of the file.
// And we return the line we just read.
// It returns NULL if there is nothing to read.

// This function uses GNL in a loop until the end of the file.
// We use it to avoid still reachable leaks.
void	skip_lines(int fd)
{
	while (get_next_line(fd) != NULL)
		;
}

void	skip_spaces_tabs(char *line, int *i)
{
	while (line[*i] == ' ' || line[*i] == '\t')
		(*i)++;
}

void	store_elem(char	*path, t_game *game, char *elem)
{
	if (elem[0] == 'N' && elem[1] == 'O')
	{
		game->no = path;
		printf("stored in game->no : %s\n", game->no);
	}
	else if (elem[0] == 'S' && elem[1] == 'O')
	{
		game->so = path;
		printf("stored in game->so : %s\n", game->so);
	}
	else if (elem[0] == 'W' && elem[1] == 'E')
	{
		game->we = path;
		printf("stored in game->we : %s\n", game->we);
	}
	else if (elem[0] == 'E' && elem[1] == 'A')
	{
		game->ea = path;
		printf("stored in game->ea : %s\n", game->ea);
	}
}

// This function will store the string (elem) in t_game.
// It will store every character until it encounters a space, tab, \n or \0.
int	get_path(char *str, t_game *game, char *elem)
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
	store_elem(path_cpy, game, elem);
	free(path);
	return (1);
}

// This function will search for 'elem' (it will be NO, SO, WE, EA)
int	search_elem(int fd, char *elem, t_game *game)
{
	char	*line;
	int		i;

	line = NULL;
	i = 0;
	line = get_next_line(fd);
	if (line == NULL)
		return (0);
	while (line != NULL)
	{
		skip_spaces_tabs(line, &i);
		if (line[i] == elem[0] && line[i + 1] == elem[1])
		{
			i += 2;
			skip_spaces_tabs(line, &i);
			if (line[i] == '\0' || line[i] == '\n')
				return (0);
			get_path(&line[i], game, elem);
			free(line);
			return (1);
		}
		free(line);
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
		return (0);
	if (search_elem(fd, "SO", game) == 0)
		return (0);
	if (search_elem(fd, "WE", game) == 0)
		return (0);
	if (search_elem(fd, "EA", game) == 0)
		return (0);
	close(fd);
	return (1);
}