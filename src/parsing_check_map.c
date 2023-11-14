/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_check_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvisouth <kvisouth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:13:19 by kvisouth          #+#    #+#             */
/*   Updated: 2023/11/14 15:45:21 by kvisouth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// Checks if the map only contains authorized characters : '0', '1', '2', 'N'
// 'S', 'E', 'W' and ' '
int	check_characters(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map.map[i] != NULL)
	{
		j = 0;
		while (game->map.map[i][j] != '\n')
		{
			if (game->map.map[i][j] != '1' && game->map.map[i][j] != '0'
				&& game->map.map[i][j] != 'N' && game->map.map[i][j] != 'S'
				&& game->map.map[i][j] != 'E' && game->map.map[i][j] != 'W'
				&& game->map.map[i][j] != ' ')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

// Checks if there is only ONE player in the map. (Which can be N, S, E or W)
int	check_player_count(t_game *game)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (game->map.map[i] != NULL)
	{
		j = 0;
		while (game->map.map[i][j] != '\n')
		{
			if (game->map.map[i][j] == 'N' || game->map.map[i][j] == 'S'
				|| game->map.map[i][j] == 'E' || game->map.map[i][j] == 'W')
			{
				count++;
				game->player.pos_x = i;
				game->player.pos_y = j;
				game->player.orient = game->map.map[i][j];
			}
			j++;
		}
		i++;
	}
	if (count != 1)
		return (1);
	return (0);
}

// Checks if the player is in a valid position.
// game->player.orient char must be surrounded by `1` and/or `0`
int	check_player_position(t_game *game)
{
	return (1);
	(void)game;
}

int	check_player(t_game *game)
{
	if (check_player_count(game))
		return (1);
	if (check_player_position(game))
		return (1);
	// faire la fct flood fill ici
	return (0);
}

int	check_map(t_game *game)
{
	if (check_characters(game))
		return (0);
	if (check_player(game))
		return (0);
	return (1);
}
