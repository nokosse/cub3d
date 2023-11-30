#include "../inc/cub3d.h"

void draw_filled_circle(t_img *data, int xc, int yc, int radius, int color)
{
	int x = 0, y = radius;
	int d = 3 - 2 * radius;

	while (x <= y)
	{
		// Dessine la ligne horizontale entre les points symétriques
		for (int i = xc - x; i <= xc + x; i++)
		{
			my_mlx_pixel_put(data, i, yc + y, color);
			my_mlx_pixel_put(data, i, yc - y, color);
		}

		// Dessine la ligne horizontale entre les points symétriques
		for (int i = xc - y; i <= xc + y; i++)
		{
			my_mlx_pixel_put(data, i, yc + x, color);
			my_mlx_pixel_put(data, i, yc - x, color);
		}

		x++;

		if (d > 0)
		{
			y--;
			d = d + 4 * (x - y) + 10;
		}
		else
		{
			d = d + 4 * x + 6;
		}
	}
}

void draw_line_dda(t_img *data, int x1, int y1, int x2, int y2, int color)
{
	int dx = x2 - x1;
	int dy = y2 - y1;

	int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

	float xIncrement = (float)dx / (float)steps;
	float yIncrement = (float)dy / (float)steps;

	float x = x1, y = y1;

	for (int i = 0; i <= steps; i++)
	{
		my_mlx_pixel_put(data, round(x), round(y), color);
		x += xIncrement;
		y += yIncrement;
	}
}

void draw_perso(t_game *game)
{
	double x;
	double y;
	double tmp;
	// int px;
	// int py;

	// px = x - 50;
	// py = y + 0;
	if (game->mouv.rotate_left)
		game->ray.rotation_angle += -1 * ROTATION_SPEED;
	if (game->mouv.rotate_right)
		game->ray.rotation_angle += 1 * ROTATION_SPEED;
	if (game->mouv.go_straigth)
	{
		tmp = cos(game->ray.rotation_angle) * 0.1;
		if (game->map.map[(int)game->ray.posx][(int)(game->ray.posy + tmp)] != '1')
			game->ray.posy += tmp;
		tmp = sin(game->ray.rotation_angle) * 0.1;
		if (game->map.map[(int)(game->ray.posx + tmp)][(int)game->ray.posy] != '1')
			game->ray.posx += tmp;
		// printf("posx = %d et posy = %d et la case = %c\n", (int)game->ray.posx, (int)game->ray.posy, game->map.map[(int)game->ray.posx][(int)game->ray.posy]);
	}
	if (game->mouv.go_backward)
	{
		tmp = cos(game->ray.rotation_angle) * -0.1;
		if (game->map.map[(int)game->ray.posx][(int)(game->ray.posy + tmp)] != '1')
			game->ray.posy += tmp;
		tmp = sin(game->ray.rotation_angle) * -0.1;
		if (game->map.map[(int)(game->ray.posx + tmp)][(int)game->ray.posy] != '1')
			game->ray.posx += tmp;
		// printf("posx = %d et posy = %d et la case = %c\n", (int)game->ray.posx, (int)game->ray.posy, game->map.map[(int)game->ray.posx][(int)game->ray.posy]);
	}
	x = game->ray.posx * MINI_BLOCK;
	y = game->ray.posy * MINI_BLOCK;

	draw_filled_circle(&game->image, game->ray.posy * MINI_BLOCK, game->ray.posx * MINI_BLOCK, 5, MINI_PERSO_COLOR);
	draw_line_dda(&game->image, y, x, y + cos(game->ray.rotation_angle) * 20, x + sin(game->ray.rotation_angle) * 20, MINI_PERSO_COLOR);
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
	int x;
	int y;

	x = 0;
	y = 0;
	while (game->map.map[y] && y * MINI_BLOCK <= game->win.w)
	{
		x = 0;
		while (game->map.map[y][x] && x * MINI_BLOCK <= game->win.h)
		{
			if (game->map.map[y][x] == '1')
				draw_cub(&(game->image), y * MINI_BLOCK, x * MINI_BLOCK, MINI_WALL_COLOR);
			else if (game->map.map[y][x] == '0' || game->map.map[y][x] == 'N' || game->map.map[y][x] == 'S' || game->map.map[y][x] == 'E' || game->map.map[y][x] == 'W')
				draw_cub(&game->image, y * MINI_BLOCK, x * MINI_BLOCK, MINI_FLOOR_COLOR);
			x++;
		}
		y++;
	}
	draw_perso(game);
	mlx_put_image_to_window(game->mlx, game->win.mlx_w, game->image.img, 0, 0);
}

void two_dim(t_game *game)
{
	draw_map(game);
}

int the_game(t_game *game)
{
	/*game->ray.dirx = -1;
	game->ray.diry = 0;
	game->ray.planex = 0;
	game->ray.planey = 0.66;*/
	two_dim(game);

	return (0);
}