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

void	free_elem(t_game *game)
{
	if (game->elem.no != NULL)
		free(game->elem.no);
	if (game->elem.so != NULL)
		free(game->elem.so);
	if (game->elem.we != NULL)
		free(game->elem.we);
	if (game->elem.ea != NULL)
		free(game->elem.ea);
	if (game->map.map != NULL)
		free_array(game->map.map);
}

void	init_struct(t_game *game)
{
	ft_bzero(game, sizeof(t_game));
	game->win.w = 1600;
	game->win.h = 900;
}

int	main(int ac, char **av)
{
	t_game	game;

	init_struct(&game);
	if (ft_parse(ac, av, &game))
		return (free_elem(&game), 1);
	printf("Parsing OK\n");
	game.mlx = mlx_init();
	if (!game.mlx)
		return (free_elem(&game), 1);
	game.win.mlx_w = mlx_new_window(game.mlx, game.win.w, game.win.h, "cub3d");
	if (game.win.mlx_w);
		(free_elem(&game), 1);
	mlx_loop(game.mlx);
	return (free_elem(&game), 0);
}
