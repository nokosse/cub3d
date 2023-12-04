#include "../inc/cub3d.h"

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

void	update_move_perso(t_game *game)
{
	double	tmp;

	if (game->mouv.rotate_left)
		game->ray.rotation_angle += -2 * ROTATION_SPEED;
	if (game->mouv.rotate_right)
		game->ray.rotation_angle += 2 * ROTATION_SPEED;
	if (game->mouv.go_straigth)
	{
		tmp = cos(game->ray.rotation_angle) * 0.1;
		if (game->map.map[(int)game->ray.posy][(int)(game->ray.posx + tmp)] != '1')
			game->ray.posx += tmp;
		tmp = sin(game->ray.rotation_angle) * 0.1;
		if (game->map.map[(int)(game->ray.posy + tmp)][(int)game->ray.posx] != '1')
			game->ray.posy += tmp;
	}
	if (game->mouv.go_backward)
	{
		tmp = cos(game->ray.rotation_angle) * -0.1;
		if (game->map.map[(int)game->ray.posy][(int)(game->ray.posx + tmp)] != '1')
			game->ray.posx += tmp;
		tmp = sin(game->ray.rotation_angle) * -0.1;
		if (game->map.map[(int)(game->ray.posy + tmp)][(int)game->ray.posx] != '1')
			game->ray.posy += tmp;
	}
	if (game->mouv.go_left)
	{
		tmp = cos(game->ray.rotation_angle - (PI / 2)) * 0.1 ;
		if (game->map.map[(int)game->ray.posy][(int)(game->ray.posx + tmp)] != '1')
			game->ray.posx += tmp;
		tmp = sin(game->ray.rotation_angle - (PI / 2)) * 0.1;
		if (game->map.map[(int)(game->ray.posy + tmp)][(int)game->ray.posx] != '1')
			game->ray.posy += tmp;
	}
	if (game->mouv.go_right)
	{
		tmp = cos(game->ray.rotation_angle + (PI / 2)) * 0.1 ;
		if (game->map.map[(int)game->ray.posy][(int)(game->ray.posx + tmp)] != '1')
			game->ray.posx += tmp;
		tmp = sin(game->ray.rotation_angle + (PI / 2)) * 0.1;
		if (game->map.map[(int)(game->ray.posy + tmp)][(int)game->ray.posx] != '1')
			game->ray.posy += tmp;
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

void	back_ground(t_game *game)
{
	int	i;
	int	max;
	int	middle;
	int	floor;
	int	ceil;

	i = 0;
	max = game->win.h  * game->win.w;
	middle = max / 2;
	ceil = makecolor(255, game->ceil.r, game->ceil.g, game->ceil.b);
	floor = makecolor(255, game->floor.r, game->floor.g, game->floor.b);
	while (i < middle)
		*(unsigned int *)(game->image.addr + i++ * 4) = ceil;
	while (i < max)
		*(unsigned int *)(game->image.addr + i++ * 4) = floor;
}



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
}

void two_dim(t_game *game)
{
	back_ground(game);
	update_move_perso(game);
	draw_map(game);
	draw_perso(game);
	mlx_put_image_to_window(game->mlx, game->win.mlx_w, game->image.img, 0, 0);
}

int the_game(t_game *game)
{
	two_dim(game);
	//printf("w = %d et h = %d\n",game->image.width, game->image.height);
	return (0);
}