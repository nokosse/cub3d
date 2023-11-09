/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_info.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvisouth <kvisouth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:28:34 by kvisouth          #+#    #+#             */
/*   Updated: 2023/11/09 17:18:06 by kvisouth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	store_path(char *path, t_game *game, char *elem)
{
	if (elem[0] == 'N' && elem[1] == 'O')
		game->no = path;
	else if (elem[0] == 'S' && elem[1] == 'O')
		game->so = path;
	else if (elem[0] == 'W' && elem[1] == 'E')
		game->we = path;
	else if (elem[0] == 'E' && elem[1] == 'A')
		game->ea = path;
}

int	parse_path(char *str, t_game *game, char *elem)
{
	int		i;
	int		j;
	char	*path;

	i = 0;
	path = NULL;
	while (str[i] != '\n' && str[i] != '\0' && str[i] != ' ')
		i++;
	path = malloc(sizeof(char) * (i + 1));
	j = 0;
	while (j < i)
	{
		path[j] = str[j];
		j++;
	}
	path[j] = '\0';
	store_path(path, game, elem);
	return (1);
}

int	rgb_or_path(t_game *game, char *elem, int i, int j)
{
	if (elem[0] != 'F' && elem[0] != 'C')
	{
		if (parse_path(game->file_cont[i] + j, game, elem) == 0)
			return (0);
	}
	else
	{
		if (parse_rgb(game->file_cont[i] + j, game, elem) == 0)
			return (0);
	}
	return (1);
}

// Will search in game->file_cont (is a char**) for *elem.
// If it finds it, it will parse the path.
int	search_elem(char *elem, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->file_cont[i] != NULL)
	{
		j = 0;
		skip_spaces(game->file_cont[i], &j);
		if ((ft_strncmp(game->file_cont[i] + j, elem, ft_strlen(elem)) == 0)
			&& (game->file_cont[i][j + ft_strlen(elem)] == ' '))
		{
			j += ft_strlen(elem);
			skip_spaces(game->file_cont[i], &j);
			if (rgb_or_path(game, elem, i, j) == 0)
				return (0);
			set_line(elem, game, i);
			return (1);
		}
		i++;
	}
	return (0);
}

int	parse_map_info(t_game *game)
{
	init_t_parse(game);
	if (search_elem("NO", game) == 0)
		return (0);
	if (search_elem("SO", game) == 0)
		return (0);
	if (search_elem("WE", game) == 0)
		return (0);
	if (search_elem("EA", game) == 0)
		return (0);
	if (search_elem("F", game) == 0)
		return (0);
	if (search_elem("C", game) == 0)
		return (0);
	if (check_empty_lines(game) == 0)
		return (0);
	free(game->parse.elem_lines);
	return (1);
}
