/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvisouth <kvisouth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:09:34 by kvisouth          #+#    #+#             */
/*   Updated: 2023/11/16 15:42:03 by kvisouth         ###   ########.fr       */
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

void	init_elem(t_game *game)
{
	game->elem.no = NULL;
	game->elem.so = NULL;
	game->elem.we = NULL;
	game->elem.ea = NULL;
	game->map.map = NULL;
}

int	main(int ac, char **av)
{
	t_game	game;
	void	*mlx_win;

	init_elem(&game);
	if (ft_parse(ac, av, &game))
	{
		free_elem(&game);
		return (1);
	}
	printf("Parsing OK\n");
	game.mlx = mlx_init();
	mlx_win = mlx_new_window(game.mlx, 1600, 900, "Hello world!");
	mlx_loop(game.mlx);
	free_elem(&game);
	return (0);
	(void)mlx_win;
}
