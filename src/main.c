/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvisouth <kvisouth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:09:34 by kvisouth          #+#    #+#             */
/*   Updated: 2023/11/09 15:38:39 by kvisouth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	main(int ac, char **av)
{
	t_game	game;

	game.no = NULL;
	game.so = NULL;
	game.we = NULL;
	game.ea = NULL;
	if (ft_parse(ac, av, &game) == 0)
	{
		printf("Error in parsing\n");
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
	printf("Parsing OK\n");
	printf("NO = %s\n", game.no);
	printf("SO = %s\n", game.so);
	printf("WE = %s\n", game.we);
	printf("EA = %s\n", game.ea);
	printf("F = %d,%d,%d\n", game.floor.r, game.floor.g, game.floor.b);
	printf("C = %d,%d,%d\n", game.ceil.r, game.ceil.g, game.ceil.b);
	free(game.no);
	free(game.so);
	free(game.we);
	free(game.ea);
	return (0);
}
