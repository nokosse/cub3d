/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvisouth <kvisouth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:27:14 by kvisouth          #+#    #+#             */
/*   Updated: 2023/11/16 15:48:16 by kvisouth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// Counts the number of lines in the file.
int	count_file_lines(char *file)
{
	int		fd;
	int		nb_lines;
	char	*line;

	nb_lines = 0;
	line = NULL;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (perror(file), -1);
	line = get_next_line(fd);
	if (line == NULL)
	{
		close(fd);
		return (ft_putstr_fd("empty file\n", 2), 0);
	}
	while (line != NULL)
	{
		free(line);
		nb_lines++;
		line = get_next_line(fd);
	}
	close(fd);
	return (nb_lines);
}

// This function will put all the content of the file in a char **.
// It will return NULL if there is a read error or if the file is empty.
// It will return the char ** if everything is ok.
char	**get_file_content(char *file)
{
	int		fd;
	int		nb_lines;
	int		i;
	char	*line;
	char	**file_content;

	nb_lines = count_file_lines(file);
	if (!nb_lines || nb_lines == -1)
		return (NULL);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (perror(file), NULL);
	file_content = ft_calloc(sizeof(char *), nb_lines + 1);
	if (file_content == NULL)
		return (close(fd), NULL);
	i = 0;
	while (i < nb_lines)
	{
		line = get_next_line(fd);
		if (line == NULL)
			return (free_array(file_content), close(fd), NULL);
		file_content[i] = line;
		i++;
	}
	return (skip_lines_end(fd), close(fd), file_content);
}

// 1. We parse the argument
// 2. We parse the elements
// 3. We parse the map itself
int	ft_parse(int ac, char **av, t_game *game)
{
	if (argument_check(ac, av))
		return (1);
	game->map_name = av[1];
	game->parse.file_cont = get_file_content(av[1]);
	if (game->parse.file_cont == NULL)
		return (1);
	if (parse_map_info(game))
	{
		free_array(game->parse.file_cont);
		return (1);
	}
	if (parse_map(game))
	{
		free_array(game->parse.file_cont);
		return (1);
	}
	free_array(game->parse.file_cont);
	return (0);
}
