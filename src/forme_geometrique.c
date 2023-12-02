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
/*
void draw_line_dda(t_img *data, int *p1, int *p2, int color)
{
	int 	dx;
	int 	dy;
	int		d[2];
	int		steps;
	float	xIncrement;
	float	yIncrement;
	float	Increment[2];
	float	x;
	float	y;
	int		i;

	dx = p2[Y] - p1[X];
	dy = p2[Y] - p1[Y];
	steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

	xIncrement = (float)dx / (float)steps;
	yIncrement = (float)dy / (float)steps;

	x = p1[X];
	y = p1[Y];

	while (i <= steps)
	{
		my_mlx_pixel_put(data, round(x), round(y), color);
		x += xIncrement;
		y += yIncrement;
		i++;
	}
}*/