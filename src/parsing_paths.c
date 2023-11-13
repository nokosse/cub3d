/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_paths.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: kvisouth <kvisouth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:57:10 by kvisouth          #+#    #+#             */
/*   Updated: 2023/11/10 13:39:04 by kvisouth         ###   ########.fr       */
=======
/*   By: kscordel <kscordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:57:10 by kvisouth          #+#    #+#             */
/*   Updated: 2023/11/11 21:00:50 by kscordel         ###   ########.fr       */
>>>>>>> kscordel
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	check_xpm_extention(t_game *game)
{
	if (ft_strnstr(game->no, ".xpm", ft_strlen(game->no)) == NULL)
<<<<<<< HEAD
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
=======
		return (1);
	if (ft_strnstr(game->so, ".xpm", ft_strlen(game->so)) == NULL)
		return (1);
	if (ft_strnstr(game->we, ".xpm", ft_strlen(game->we)) == NULL)
		return (1);
	if (ft_strnstr(game->ea, ".xpm", ft_strlen(game->ea)) == NULL)
		return (1);
	return (0);
}

/*check si le fichier est un repertoit et renvoie la string en cas d erreur*/
char*	check_is_directory(t_game *game)
{
	int	fds[4];
	
	fds[0] = open(game->no, O_RDONLY | O_DIRECTORY);
	if (fds[0] > 0)
		return (close(fds[0]), game->no);
	fds[1] = open(game->so, O_RDONLY | O_DIRECTORY);
	if (fds[1] > 0)
		return (close(fds[1]), game->so);
	fds[2] = open(game->we, O_RDONLY | O_DIRECTORY);
	if (fds[2] > 0)
		return (close(fds[2]), game->we);
	fds[3] = open(game->ea, O_RDONLY | O_DIRECTORY);
	if (fds[3] > 0)
		return (close(fds[3]), game->ea);
	return (NULL);
}

char*	check_file_exist(t_game *game)
{
	int	fds[4];
	
	fds[0] = open(game->no, O_RDONLY);
	if (fds[0] == -1)
		return (game->no);
	fds[1] = open(game->so, O_RDONLY);
	if (fds[1] == -1)
		return (close(fds[1]), game->so);
	fds[2] = open(game->we, O_RDONLY);
	if (fds[2] == -1)
		return (close(fds[0]), close(fds[1]), game->we);
	fds[3] = open(game->ea, O_RDONLY);
	if (fds[3] == -1)
		return (close(fds[0]), close(fds[1]), close(fds[2]), game->ea);
	return (close(fds[0]), close(fds[1]), close(fds[2]), close(fds[3]), NULL);
}


int	check_correct_paths(t_game *game)
{
	char *ret;
	
	ret = check_is_directory(game);
	if (ret)
		return (ft_putstr_fd(ret, 2), ft_putstr_fd(" is a directory\n", 2), 1);
	ret = check_file_exist(game);
	if (ret)
		return (perror(ret), 1);
	if (check_xpm_extention(game))
		return (ft_putstr_fd("erreur: no extension .xpm\n", 2), 1);
	return (0);
>>>>>>> kscordel
	(void)game;
}
