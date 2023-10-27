/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvisouth <kvisouth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:09:34 by kvisouth          #+#    #+#             */
/*   Updated: 2023/10/27 15:50:19 by kvisouth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	main(int ac, char **av)
{
	t_game	game;

	if (ft_parse(ac, av, &game) == 0)
	{
		if (game.no != NULL)
			free(game.no);
		if (game.so != NULL)
			free(game.so);
		if (game.we != NULL)
			free(game.we);
		if (game.ea != NULL)
			free(game.ea);
		return (0);
	}
	printf("The parsing is all good !\n");
	printf("game->no : %s\n", game.no);
	printf("game->so : %s\n", game.so);
	printf("game->we : %s\n", game.we);
	printf("game->ea : %s\n", game.ea);
	printf("game->floor : %d, %d, %d\n", game.floor.r, game.floor.g, game.floor.b);
	printf("game->ceil : %d, %d, %d\n", game.ceil.r, game.ceil.g, game.ceil.b);
	free(game.no);
	free(game.so);
	free(game.we);
	free(game.ea);
	return (0);
}
