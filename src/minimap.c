/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kscordel <kscordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:15:16 by kscordel          #+#    #+#             */
/*   Updated: 2023/12/05 14:24:15 by kscordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
#include "limits.h"

void	define_mid(t_game *game, double *x, double *y)
{
	*x = 0;
	*y = 0;
	if (game->ray.posy > (MINI_T / 2))
		*y = game->ray.posy - (MINI_T / 2);
	else
		*y = 0;
	if (game->ray.posx > (MINI_T / 2))
		*x = game->ray.posx - (MINI_T / 2);
	else
		*x = 0;
	if (MINI_T < game->map.map_height)
	{
		if (MINI_T + *y > game->map.map_height)
		*y = game->map.map_height - MINI_T;
	}
	if (MINI_T < game->map.map_width)
	{
		if (MINI_T + *x > game->map.map_width)
		*x = game->map.map_width - MINI_T;
	}
}

void draw_perso(t_game *game)
{
	double	x;
	double	y;
	double	xs;
	double	ys;

	xs = 0;
	ys = 0;
	define_mid(game, &xs, &ys);
	y = (game->ray.posx - xs) * MINI_BLOCK;
	x = (game->ray.posy  - ys)* MINI_BLOCK;

	draw_filled_circle(&game->image, y, x, 5, MINI_PERSO_COLOR);
	draw_line_dda(&game->image, y, x, y + cos(game->ray.rotation_angle) * 200, x + sin(game->ray.rotation_angle) * 200, MINI_PERSO_COLOR);
	raycasting(game);
}


void draw_cub(t_img *img, int y, int x, int color)
{
	int a;
	int b;

	a = 0;
	while (a < MINI_BLOCK - 1)
	{
		b = 0;
		while (b < MINI_BLOCK - 1)
		{
			my_mlx_pixel_put(img, x + a, y + b, color);
			b++;
		}
		a++;
	}
}

void draw_map(t_game *game)
{
	double	x;
	double	y;
	double	xs;
	double	ys;
	double	ratio;
	static unsigned int	r = 0;

	x = 0;
	y = 0;
	r++;
	if (r == UINT_MAX)
		r = 0;
	ratio = 1.0 / (double)MINI_BLOCK;
	define_mid(game, &xs, &ys);
	x = xs;
	y = ys;
	
	//printf("ratio = %lf\n", ratio);
	while (game->map.map[(int)y] && y - ys < MINI_T)
	{
		x = xs;

		while (game->map.map[(int)y][(int)x] && x - xs < MINI_T)
		{
			
			if (game->map.map[(int)y][(int)x] == '1')
				my_mlx_pixel_put(&game->image, (x - xs) * MINI_BLOCK, (y - ys) * MINI_BLOCK, MINI_WALL_COLOR);
			else if (game->map.map[(int)y][(int)x] == '0' || game->map.map[(int)y][(int)x] == 'N' || game->map.map[(int)y][(int)x] == 'S' || game->map.map[(int)y][(int)x] == 'E' || game->map.map[(int)y][(int)x] == 'W')
				my_mlx_pixel_put(&game->image, (x - xs) * MINI_BLOCK, (y - ys) * MINI_BLOCK, MINI_FLOOR_COLOR);
			else
				printf("x == %d et y = %d", (int)x, (int)y);
			x += ratio;
		}
		
		y += ratio;
	}
}
/*
void draw_map(t_game *game)
{
	int x;
	int y;
	double	xs;
	double	ys;

	x = 0;
	y = 0;
	define_mid(game, &xs, &ys);
	x = xs;
	y = ys;
	while (game->map.map[y] && y - ys < MINI_T)
	{
		x = xs;
		while (game->map.map[y][x] && x - xs < MINI_T)
		{
			if (game->map.map[y][x] == '1')
				draw_cub(&(game->image), (y - ys) * MINI_BLOCK, (x - xs) * MINI_BLOCK, MINI_WALL_COLOR);
			else if (game->map.map[y][x] == '0' || game->map.map[y][x] == 'N' || game->map.map[y][x] == 'S' || game->map.map[y][x] == 'E' || game->map.map[y][x] == 'W')
				draw_cub(&game->image, (y - ys) * MINI_BLOCK, (x - xs) * MINI_BLOCK, MINI_FLOOR_COLOR);
			x++;
		}
		y++;
	}
}*/