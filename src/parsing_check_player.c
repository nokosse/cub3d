/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_check_player.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvisouth <kvisouth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:37:31 by kvisouth          #+#    #+#             */
/*   Updated: 2023/11/16 15:51:32 by kvisouth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// Checks if there is only ONE player in the map. (Which can be N, S, E or W)
int	check_player_count(t_game *game)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (i < game->map.map_height - 1)
	{
		j = -1;
		while (game->map.map[i][++j] != '\n')
		{
			if (game->map.map[i][j] == 'N' || game->map.map[i][j] == 'S'
				|| game->map.map[i][j] == 'E' || game->map.map[i][j] == 'W')
			{
				count++;
				game->player.pos_x = i;
				game->player.pos_y = j;
				game->player.orient = game->map.map[i][j];
			}
		}
		i++;
	}
	if (count != 1)
		return (1);
	return (0);
}

// Checks if the player is in a valid position.
// game->player.orient char must be surrounded by `1` and/or `0`.
// X is up and down, larger it is, lower it is.
// Y is left and right, larger it is, righter it is.
int	check_player_position(t_game *game)
{
	int	x;
	int	y;

	x = game->player.pos_x;
	y = game->player.pos_y;
	if (x <= 0 || y <= 0)
		return (1);
	if (x + 1 >= game->map.map_height || y > game->map.map_width)
		return (1);
	if (game->map.map[x - 1][y] != '1' && game->map.map[x - 1][y] != '0')
		return (1);
	if (game->map.map[x + 1][y] != '1' && game->map.map[x + 1][y] != '0')
		return (1);
	if (game->map.map[x][y - 1] != '1' && game->map.map[x][y - 1] != '0')
		return (1);
	if (game->map.map[x][y + 1] != '1' && game->map.map[x][y + 1] != '0')
		return (1);
	return (0);
}

int	check_player(t_game *game)
{
	if (check_player_count(game))
	{
		ft_putstr_fd("Error\nInvalid number of players\n", 2);
		return (1);
	}
	if (check_player_position(game))
	{
		ft_putstr_fd("Error\nInvalid player position\n", 2);
		return (1);
	}
	return (0);
}
