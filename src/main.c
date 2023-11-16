/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvisouth <kvisouth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:09:34 by kvisouth          #+#    #+#             */
/*   Updated: 2023/11/16 18:17:47 by kvisouth         ###   ########.fr       */
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
	game->elem.no = NULL;
	game->elem.so = NULL;
	game->elem.we = NULL;
	game->elem.ea = NULL;
	game->map.map = NULL;
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
	game.win.mlx_w = mlx_new_window(game.mlx, game.win.w, game.win.h, "Cub3D");
	mlx_loop(game.mlx);
	return (free_elem(&game), 0);
}
