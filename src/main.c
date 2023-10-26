/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvisouth <kvisouth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:09:34 by kvisouth          #+#    #+#             */
/*   Updated: 2023/10/26 16:59:19 by kvisouth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	main(int ac, char **av)
{
	t_game	game;

	if (ft_parse(ac, av, &game) == 0)
		return (0);
	printf("The parsing is all good !\n");
	printf("game->no : %s\n", game.no);
	printf("game->so : %s\n", game.so);
	printf("game->we : %s\n", game.we);
	printf("game->ea : %s\n", game.ea);
	// init t_game once parsing is all good
	return (0);
}
