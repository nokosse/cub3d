#include "../inc/cub3d.h"

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
		if (game->map.map[(int)game->ray.posx][(int)(game->ray.posy + tmp)] != '1')
			game->ray.posy += tmp;
		tmp = sin(game->ray.rotation_angle) * 0.1;
		if (game->map.map[(int)(game->ray.posx + tmp)][(int)game->ray.posy] != '1')
			game->ray.posx += tmp;
	}
	if (game->mouv.go_backward)
	{
		tmp = cos(game->ray.rotation_angle) * -0.1;
		if (game->map.map[(int)game->ray.posx][(int)(game->ray.posy + tmp)] != '1')
			game->ray.posy += tmp;
		tmp = sin(game->ray.rotation_angle) * -0.1;
		if (game->map.map[(int)(game->ray.posx + tmp)][(int)game->ray.posy] != '1')
			game->ray.posx += tmp;
	}
	if (game->mouv.go_left)
	{
		tmp = cos(game->ray.rotation_angle - (PI / 2)) * 0.1 ;
		if (game->map.map[(int)game->ray.posx][(int)(game->ray.posy + tmp)] != '1')
			game->ray.posy += tmp;
		tmp = sin(game->ray.rotation_angle - (PI / 2)) * 0.1;
		if (game->map.map[(int)(game->ray.posx + tmp)][(int)game->ray.posy] != '1')
			game->ray.posx += tmp;
	}
	if (game->mouv.go_right)
	{
		tmp = cos(game->ray.rotation_angle + (PI / 2)) * 0.1 ;
		if (game->map.map[(int)game->ray.posx][(int)(game->ray.posy + tmp)] != '1')
			game->ray.posy += tmp;
		tmp = sin(game->ray.rotation_angle + (PI / 2)) * 0.1;
		if (game->map.map[(int)(game->ray.posx + tmp)][(int)game->ray.posy] != '1')
			game->ray.posx += tmp;
	}
}

void draw_perso(t_game *game)
{
	double x;
	double y;
	
	update_move_perso(game);
	x = game->ray.posx * MINI_BLOCK;
	y = game->ray.posy * MINI_BLOCK;

	draw_filled_circle(&game->image, game->ray.posy * MINI_BLOCK, game->ray.posx * MINI_BLOCK, 5, MINI_PERSO_COLOR);
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

	x = 0;
	y = 0;
	back_ground(game);
	while (game->map.map[y] && y * MINI_BLOCK + MINI_BLOCK < game->win.w)
	{
		x = 0;
		while (game->map.map[y][x] && x * MINI_BLOCK + MINI_BLOCK < game->win.h)
		{
			if (game->map.map[y][x] == '1')
				draw_cub(&(game->image), y * MINI_BLOCK, x * MINI_BLOCK, MINI_WALL_COLOR);
			else if (game->map.map[y][x] == '0' || game->map.map[y][x] == 'N' || game->map.map[y][x] == 'S' || game->map.map[y][x] == 'E' || game->map.map[y][x] == 'W')
				draw_cub(&game->image, y * MINI_BLOCK, x * MINI_BLOCK, MINI_FLOOR_COLOR);
			x++;
		}
		y++;
	}
}

void two_dim(t_game *game)
{
	draw_map(game);
	draw_perso(game);
	mlx_put_image_to_window(game->mlx, game->win.mlx_w, game->image.img, 0, 0);
}

int the_game(t_game *game)
{
	/*game->ray.dirx = -1;
	game->ray.diry = 0;
	game->ray.planex = 0;
	game->ray.planey = 0.66;*/
	two_dim(game);
	//printf("w = %d et h = %d\n",game->image.width, game->image.height);
	return (0);
}