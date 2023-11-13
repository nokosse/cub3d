/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvisouth <kvisouth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:28:55 by kvisouth          #+#    #+#             */
/*   Updated: 2023/11/13 16:52:08 by kvisouth         ###   ########.fr       */
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
	int	j;

	j = 0;
	if (game->file_cont[i][j] == '\n')
		return (1);
	return (0);
}

int	set_map_end(t_game *game, int *i)
{
	int	j;

	j = 0;
	while (game->file_cont[*i] != NULL)
	{
		
	}
	game->map.map_end = *i - 1;
	return (1);
	(void)game;
	(void)j;
}

int	parse_map(t_game *game)
{
	int	i;
	int	j;

	set_last_line(game);
	i = game->parse.last_elem + 1;
	skip_newlines(game, &i);
	if (set_map_start(game, i) == 0)
		return (0);
	if (set_map_end(game, &i) == 0)
		return (0);
	printf("map start = %d\n", game->map.map_start);
	printf("map end = %d\n", game->map.map_end);
	while (game->file_cont[i] != NULL)
	{
		i++;
	}
	return (1);
	(void)j;
	(void)game;
}
