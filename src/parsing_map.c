/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kscordel <kscordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:28:55 by kvisouth          #+#    #+#             */
/*   Updated: 2023/11/11 20:15:28 by kscordel         ###   ########.fr       */
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
	if (game->file_cont[i][j] == '1')
	{
		game->map.map_start = i;
		return (1);
	}
	return (0);
}

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

int	set_map_end(t_game *game, int *i)
{
	int	j;

	j = 0;
	(*i)++;
	while (game->file_cont[*i] != NULL)
	{
		printf("%s\n", game->file_cont[*i]);
		while (game->file_cont[*i][j] == ' ')
			j++;
		
		if (game->file_cont[*i][j] == '1')
			return (0);
		(*i)++;
	}
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
		return (1);
	if (set_map_end(game, &i) == 0)
		return (1);
	printf("map start = %d\n", game->map.map_start);
	printf("map end = %d\n", game->map.map_end);
	while (game->file_cont[i] != NULL)
	{
		i++;
	}
	return (0);
	(void)j;
	(void)game;
}
