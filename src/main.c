/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kscordel <kscordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:09:34 by kvisouth          #+#    #+#             */
/*   Updated: 2023/11/11 18:01:58 by kscordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	free_elem(t_game *game)
{
	if (game->no != NULL)
		free(game->no);
	if (game->so != NULL)
		free(game->so);
	if (game->we != NULL)
		free(game->we);
	if (game->ea != NULL)
		free(game->ea);
}

void	init_elem(t_game *game)
{
	game->no = NULL;
	game->so = NULL;
	game->we = NULL;
	game->ea = NULL;
}

int	main(int ac, char **av)
{
	t_game	game;

	init_elem(&game);
	if (ft_parse(ac, av, &game))
	{
		//parse_error_msg();
		printf("NO = %s\n", game.no);
	printf("SO = %s\n", game.so);
	printf("WE = %s\n", game.we);
	printf("EA = %s\n", game.ea);
	printf("F = %d,%d,%d\n", game.floor.r, game.floor.g, game.floor.b);
	printf("C = %d,%d,%d\n", game.ceil.r, game.ceil.g, game.ceil.b);
		free_elem(&game);
		return (1);
	}
	printf("Parsing OK\n");
	printf("NO = %s\n", game.no);
	printf("SO = %s\n", game.so);
	printf("WE = %s\n", game.we);
	printf("EA = %s\n", game.ea);
	printf("F = %d,%d,%d\n", game.floor.r, game.floor.g, game.floor.b);
	printf("C = %d,%d,%d\n", game.ceil.r, game.ceil.g, game.ceil.b);
	free_elem(&game);
	return (0);
}
