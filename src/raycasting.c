/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvisouth <kvisouth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:15:24 by kscordel          #+#    #+#             */
/*   Updated: 2023/12/06 14:31:05 by kvisouth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

//tout ce raycasting est fait pour la minimap

void	init(t_game *game, double ray_angle)
{
	// ray_angle %= 2 * PI;
	(void)game;
	ray_angle = ray_angle * PI / 180;
	if (ray_angle < 0)
		ray_angle = (2 * PI) + ray_angle;
	
}

void	raycasting(t_game *game)
{
	double	ray_angle;
	int		i;
	int		x;
	int		y;
	double	xs;
	double	ys;

	xs = 0;
	ys = 0;
	define_mid(game, &xs, &ys);

	y = (game->ray.posx - xs) * MINI_BLOCK;
	x = (game->ray.posy - ys) * MINI_BLOCK;
	ray_angle = game->ray.rotation_angle - (FOV / 2);
	i = 0;
	while (i < game->image.width / 10)
	{
		init(game, ray_angle);
		

		draw_line_dda(&game->image, y, x, y + cos(ray_angle) * 200, x + sin(ray_angle) * 200, MINI_PERSO_COLOR);
		ray_angle += FOV / game->image.width * 10;
		i++;
	}
}