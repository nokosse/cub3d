/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvisouth <kvisouth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:09:34 by kvisouth          #+#    #+#             */
/*   Updated: 2023/11/13 18:38:31 by kvisouth         ###   ########.fr       */
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
		printf("Error in parsing\n");
		free_elem(&game);
		return (1);
	}
	printf("Parsing OK\n");
	free_elem(&game);
	return (0);
}
