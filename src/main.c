/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kscordel <kscordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:09:34 by kvisouth          #+#    #+#             */
/*   Updated: 2023/12/02 13:23:17 by kscordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

t_img	load_texture(t_game *game, char *file)
{
	t_img img;

	img.img = mlx_xpm_file_to_image(game->mlx, file,
			&img.width, &img.height);
	if (!img.img)
		return (img);
	img.addr = mlx_get_data_addr(img.img, \
	&img.bits_per_pixel, &img.line_length, &img.endian);
	return (img);
}

int	load_element(t_game *game)
{
	game->no = load_texture(game, game->parse.no);
	game->so = load_texture(game, game->parse.so);
	game->we = load_texture(game, game->parse.we);
	game->ea = load_texture(game, game->parse.ea);
	if (!game->ea.img || !game->we.img || !game->so.img || !game->no.img)
		return (perror("mlx_xpm_file_to_img"), 1);
	game->image.img = mlx_new_image(game->mlx, game->win.w, game->win.h);
	if (!game->image.img)
		return (perror("mlx_new_img"), 1);
	game->image.addr = mlx_get_data_addr(game->image.img, \
	&game->image.bits_per_pixel, &game->image.line_length, &game->image.endian);
	game->image.width = game->win.w;
	game->image.height = game->win.h;
	return (0);
}


int	init_struct(t_game *game)
{
	ft_bzero(game, sizeof(t_game));
	game->mlx = mlx_init();
	if (!game->mlx)
		return (free_elem(game), 1);
	mlx_get_screen_size(game->mlx, &game->win.w, &game->win.h);
	game->win.w /= 2;
	game->win.h -= 100;
	return (0);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (init_struct(&game))
		return (1);
	if (ft_parse(ac, av, &game))
		return (free_all(&game), 1);
	printf("Parsing OK\n");
	if (load_element(&game))
		return (free_all(&game), 1);
	game.win.mlx_w = mlx_new_window(game.mlx, game.win.w, game.win.h, "cub3d");
	if (!game.win.mlx_w)
		return (free_all(&game), 1);
	printf("player posx = %lf posy = %lf et orient = %c\n", game.ray.posx, game.ray.posy, game.orient);
	//the_game(&game);
	//mlx_key_hook(game.win.mlx_w, &key_hook, &game);
	game.ray.rotation_angle = PI / 2;
	mlx_loop_hook(game.mlx, the_game, &game);
	mlx_hook(game.win.mlx_w, 2, 1L << 0, key_down_hook, &game);
	mlx_hook(game.win.mlx_w, 3, 1L << 1, key_up_hook, &game);
	mlx_hook(game.win.mlx_w, 17, 1L << 0, quit, &game);
	mlx_loop(game.mlx);
	return (free_all(&game), 0);
}
