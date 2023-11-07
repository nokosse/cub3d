/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvisouth <kvisouth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:09:34 by kvisouth          #+#    #+#             */
/*   Updated: 2023/11/07 16:23:07 by kvisouth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	main(int ac, char **av)
{
	t_game	game;

	if (ft_parse(ac, av, &game) == 0)
	{
		printf("Error in parsing\n");
		return (0);
	}
	printf("Parsing OK\n");
	printf("NO = %s\n", game.no);
	printf("SO = %s\n", game.so);
	printf("WE = %s\n", game.we);
	printf("EA = %s\n", game.ea);
	free(game.no);
	free(game.so);
	free(game.we);
	free(game.ea);
	return (0);
}
