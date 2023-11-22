/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kscordel <kscordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:09:34 by kvisouth          #+#    #+#             */
/*   Updated: 2023/11/17 19:47:35 by kscordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"




int	load_element(t_game *game)
{
	game->no.img = mlx_xpm_file_to_image(game->mlx, game->parse.no,
			&game->no.width, &game->no.height);
	if (!game->no.img)
		return (perror("mlx_xpm_file_to_image"), 1);
	game->so.img = mlx_xpm_file_to_image(game->mlx, game->parse.so,
			&game->so.width, &game->so.height);
	if (!game->so.img)
		return (perror("mlx_xpm_file_to_image"), 1);
	game->we.img = mlx_xpm_file_to_image(game->mlx, game->parse.we,
			&game->we.width, &game->we.height);
	if (!game->we.img)
		return (perror("mlx_xpm_file_to_image"), 1);
	game->ea.img = mlx_xpm_file_to_image(game->mlx, game->parse.ea,
			&game->ea.width, &game->ea.height);
	if (!game->ea.img)
		return (perror("mlx_xpm_file_to_image"), 1);
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
	printf("player posx = %d posy = %d et orient = %c\n", game.player.pos_x, game.player.pos_y, game.player.orient);
	the_game(&game);
	mlx_key_hook(game.win.mlx_w, &key_hook, &game);
	mlx_hook(game.win.mlx_w, 17, 1L << 0, quit, &game);
	mlx_loop(game.mlx);
	return (free_all(&game), 0);
}
