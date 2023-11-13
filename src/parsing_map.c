/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvisouth <kvisouth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:28:55 by kvisouth          #+#    #+#             */
/*   Updated: 2023/11/13 18:00:41 by kvisouth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	set_last_line(t_game *game)
{
	int	i;

	i = game->parse.last_elem;
	while (game->file_cont[i] != NULL)
		i++;
	game->parse.last_line = i;
}

void	skip_newlines(t_game *game, int *i)
{
	while (game->file_cont[*i][0] == '\n')
		(*i)++;
}

int	set_map_start(t_game *game, int i)
{
	int	j;

	j = 0;
	while (game->file_cont[i][j] == ' ')
		j++;
	if (game->file_cont[i][j] == '1' || game->file_cont[i][j] == '0')
	{
		game->map.map_start = i;
		return (1);
	}
	return (0);
}

// Will check if line (i) is empty but can contain spaces.
int	is_empty_line(t_game *game, int i)
{
	int	j;

	j = 0;
	while (game->file_cont[i][j] == ' ')
		j++;
	if (game->file_cont[i][j] == '\n')
		return (1);
	return (0);
}

// Will check if line (i) is completely empty (only \n at [0])
int	is_empty_line2(t_game *game, int i)
{
	if (game->file_cont[i][0] == '\n')
		return (1);
	return (0);
}

int	get_map_size(t_game *game, int i)
{
	int	j;
	int	size;

	j = 0;
	size = 0;
	while (game->file_cont[i] != NULL)
	{
		j = 0;
		skip_spaces(game->file_cont[i], &j);
		if (game->file_cont[i][j] != '1' && game->file_cont[i][j] != '0')
		{
			if (game->file_cont[i][0] == '\n')
			{
				game->map.map_height = size;
				return (size);
			}
			else
				return (0);
		}
		size++;
		i++;
	}
	game->map.map_height = size;
	return (size);
}

int	check_garbage(t_game *game, int a, int b)
{
	a++;
	while (a < b)
	{
		if (is_empty_line2(game, a) == 0)
		{
			return (0);
		}
		a++;
	}
	return (1);
}

int	get_map(t_game *game, int start, int end)
{
	int	i;
	int	j;

	i = start;
	j = 0;
	game->map.map = ft_calloc(sizeof(char *), (game->map.map_height + 1));
	if (game->map.map == NULL)
		return (0);
	while (i <= end)
	{
		game->map.map[j] = ft_strdup(game->file_cont[i]);
		if (game->map.map[j] == NULL)
		{
			free_array(game->map.map);
			return (0);
		}
		i++;
		j++;
	}
	return (1);
}

int	parse_map(t_game *game)
{
	int	i;

	set_last_line(game);
	i = game->parse.last_elem + 1;
	skip_newlines(game, &i);
	if (set_map_start(game, i) == 0)
		return (0);
	if (get_map_size(game, i) < 3)
		return (0);
	game->map.map_end = (game->map.map_start + game->map.map_height) - 1;
	if (check_garbage(game, game->map.map_end, game->parse.last_line) == 0)
		return (0);
	if (get_map(game, game->map.map_start, game->map.map_end) == 0)
		return (0);
	return (1);
}
