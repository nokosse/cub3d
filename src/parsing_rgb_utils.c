/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_rgb_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvisouth <kvisouth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:20:23 by kvisouth          #+#    #+#             */
/*   Updated: 2023/10/27 16:20:45 by kvisouth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	store_rgb(t_game *game, char *elem, char **rgb_split)
{
	if (elem[0] == 'F')
	{
		game->floor.r = ft_atoi(rgb_split[0]);
		game->floor.g = ft_atoi(rgb_split[1]);
		game->floor.b = ft_atoi(rgb_split[2]);
	}
	else if (elem[0] == 'C')
	{
		game->ceil.r = ft_atoi(rgb_split[0]);
		game->ceil.g = ft_atoi(rgb_split[1]);
		game->ceil.b = ft_atoi(rgb_split[2]);
	}
	free(rgb_split[0]);
	free(rgb_split[1]);
	free(rgb_split[2]);
	free(rgb_split);
}

int	check_rgb_ints(t_game *game, char *elem)
{
	if (elem[0] == 'F')
	{
		if (game->floor.r < 0 || game->floor.r > 255)
			return (0);
		if (game->floor.g < 0 || game->floor.g > 255)
			return (0);
		if (game->floor.b < 0 || game->floor.b > 255)
			return (0);
	}
	else if (elem[0] == 'C')
	{
		if (game->ceil.r < 0 || game->ceil.r > 255)
			return (0);
		if (game->ceil.g < 0 || game->ceil.g > 255)
			return (0);
		if (game->ceil.b < 0 || game->ceil.b > 255)
			return (0);
	}
	return (1);
}
