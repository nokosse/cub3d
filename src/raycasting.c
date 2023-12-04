#include "../inc/cub3d.h"

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
		//init();
		

		draw_line_dda(&game->image, y, x, y + cos(ray_angle) * 200, x + sin(ray_angle) * 200, MINI_PERSO_COLOR);
		ray_angle += FOV / game->image.width * 10;
		i++;
	}
}