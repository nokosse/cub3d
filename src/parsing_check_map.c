/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_check_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvisouth <kvisouth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:13:19 by kvisouth          #+#    #+#             */
/*   Updated: 2023/11/14 16:40:17 by kvisouth         ###   ########.fr       */
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

int	check_map(t_game *game)
{
	if (check_characters(game))
		return (0);
	if (check_player(game))
		return (0);
	return (1);
}
