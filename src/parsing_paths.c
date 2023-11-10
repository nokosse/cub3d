/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_paths.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvisouth <kvisouth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:57:10 by kvisouth          #+#    #+#             */
/*   Updated: 2023/11/10 13:39:04 by kvisouth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	check_xpm_extention(t_game *game)
{
	if (ft_strnstr(game->no, ".xpm", ft_strlen(game->no)) == NULL)
		return (0);
	if (ft_strnstr(game->so, ".xpm", ft_strlen(game->so)) == NULL)
		return (0);
	if (ft_strnstr(game->we, ".xpm", ft_strlen(game->we)) == NULL)
		return (0);
	if (ft_strnstr(game->ea, ".xpm", ft_strlen(game->ea)) == NULL)
		return (0);
	return (1);
}

int	check_file_exist(t_game *game)
{
	if (open(game->no, O_RDONLY) == -1)
		return (0);
	if (open(game->so, O_RDONLY) == -1)
		return (0);
	if (open(game->we, O_RDONLY) == -1)
		return (0);
	if (open(game->ea, O_RDONLY) == -1)
		return (0);
	return (1);
}

int	check_correct_paths(t_game *game)
{
	if (check_file_exist(game) == 0)
		return (0);
	if (check_xpm_extention(game) == 0)
		return (0);
	return (1);
	(void)game;
}
