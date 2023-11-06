/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvisouth <kvisouth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:27:14 by kvisouth          #+#    #+#             */
/*   Updated: 2023/11/06 17:25:09 by kvisouth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	count_file_lines(char *file)
{
	int		fd;
	int		nb_lines;
	char	*line;

	nb_lines = 0;
	line = NULL;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	line = get_next_line(fd);
	if (line == NULL)
	{
		close(fd);
		return (0);
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
	fd = open(file, O_RDONLY);
	if (fd == -1 || nb_lines == 0)
		return (NULL);
	file_content = malloc(sizeof(char *) * (nb_lines + 1));
	if (file_content == NULL)
		return (NULL);
	i = 0;
	while (i < nb_lines)
	{
		line = get_next_line(fd);
		if (line == NULL)
			return (NULL);
		file_content[i] = line;
		i++;
	}
	file_content[i] = NULL;
	skip_lines_end(fd);
	return (close(fd), file_content);
}

void	free_array(char	**array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
}

// argument_check will check if the argument seems valid.
// parse_map_info will parse the map info such as NO, SO, WE, EA, F, C.
// parse_map will parse the map itself (the 1, 0, N, S, E, W).
int	ft_parse(int ac, char **av, t_game *game)
{
	char	**file_content;

	file_content = NULL;
	if (argument_check(ac, av) == 0)
		return (0);
	game->map_name = av[1];
	file_content = get_file_content(av[1]);
	if (file_content == NULL)
		return (0);
	game->file_cont = file_content;
	if (parse_map_info(game) == 0)
	{
		free_array(file_content);
		free(file_content);
		return (0);
	}
	free_array(file_content);
	free(file_content);
	return (1);
}
