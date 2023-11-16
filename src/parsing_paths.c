/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_paths.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvisouth <kvisouth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:57:10 by kvisouth          #+#    #+#             */
/*   Updated: 2023/11/16 15:42:03 by kvisouth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// Checks if the paths have the extension .xpm
int	check_xpm_extention(t_game *game)
{
	if (ft_strnstr(game->elem.no, ".xpm", ft_strlen(game->elem.no)) == NULL)
		return (1);
	if (ft_strnstr(game->elem.so, ".xpm", ft_strlen(game->elem.so)) == NULL)
		return (1);
	if (ft_strnstr(game->elem.we, ".xpm", ft_strlen(game->elem.we)) == NULL)
		return (1);
	if (ft_strnstr(game->elem.ea, ".xpm", ft_strlen(game->elem.ea)) == NULL)
		return (1);
	return (0);
}

// Checks if the path is a directory
char	*check_is_directory(t_game *game)
{
	int	fds[4];

	fds[0] = open(game->elem.no, O_RDONLY | O_DIRECTORY);
	if (fds[0] > 0)
		return (close(fds[0]), game->elem.no);
	fds[1] = open(game->elem.so, O_RDONLY | O_DIRECTORY);
	if (fds[1] > 0)
		return (close(fds[1]), game->elem.so);
	fds[2] = open(game->elem.we, O_RDONLY | O_DIRECTORY);
	if (fds[2] > 0)
		return (close(fds[2]), game->elem.we);
	fds[3] = open(game->elem.ea, O_RDONLY | O_DIRECTORY);
	if (fds[3] > 0)
		return (close(fds[3]), game->elem.ea);
	return (NULL);
}

// Checks if the file exists
char	*check_file_exist(t_game *game)
{
	int	fds[4];

	fds[0] = open(game->elem.no, O_RDONLY);
	if (fds[0] == -1)
		return (game->elem.no);
	fds[1] = open(game->elem.so, O_RDONLY);
	if (fds[1] == -1)
		return (close(fds[1]), game->elem.so);
	fds[2] = open(game->elem.we, O_RDONLY);
	if (fds[2] == -1)
		return (close(fds[0]), close(fds[1]), game->elem.we);
	fds[3] = open(game->elem.ea, O_RDONLY);
	if (fds[3] == -1)
		return (close(fds[0]), close(fds[1]), close(fds[2]), game->elem.ea);
	return (close(fds[0]), close(fds[1]), close(fds[2]), close(fds[3]), NULL);
}

int	check_correct_paths(t_game *game)
{
	char	*ret;

	ret = check_is_directory(game);
	if (ret)
		return (ft_putstr_fd(ret, 2), ft_putstr_fd(" is a directory\n", 2), 1);
	ret = check_file_exist(game);
	if (ret)
	{
		ft_putstr_fd("Error\n", 2);
		return (perror(ret), 1);
	}
	if (check_xpm_extention(game))
		return (ft_putstr_fd("Error\nFile extention must be .xpm\n", 2), 1);
	return (0);
	(void)game;
}
