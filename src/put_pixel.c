#include "../inc/cub3d.h"

int	makecolor(int t, int red, int green, int blue)
{
	/*if (red > 255)
		red = 255;
	if (green > 255)
		green = 255;
	if (blue > 255)
		blue = 255;*/
	return (t << 24 | red << 16 | green << 8 | blue);
}

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	int	pix;

	pix = y * data->line_length + x * (data->bits_per_pixel / 8);
	if (pix >= 0 && pix <= data->height * data->width * 4)
		*(unsigned int *)(data->addr + pix) = color;
}