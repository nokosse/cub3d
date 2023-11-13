/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: kvisouth <kvisouth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:27:14 by kvisouth          #+#    #+#             */
/*   Updated: 2023/11/10 17:21:34 by kvisouth         ###   ########.fr       */
=======
/*   By: kscordel <kscordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:27:14 by kvisouth          #+#    #+#             */
/*   Updated: 2023/11/13 15:40:45 by kscordel         ###   ########.fr       */
>>>>>>> kscordel
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
<<<<<<< HEAD
		return (-1);
=======
		return (perror(file), -1);
>>>>>>> kscordel
	line = get_next_line(fd);
	if (line == NULL)
	{
		close(fd);
<<<<<<< HEAD
		return (0);
=======
		return (ft_putstr_fd("empty file\n", 2), 0);
>>>>>>> kscordel
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
<<<<<<< HEAD
	fd = open(file, O_RDONLY);
	if (fd == -1 || nb_lines == 0)
		return (NULL);
	file_content = malloc(sizeof(char *) * (nb_lines + 1));
	if (file_content == NULL)
		return (NULL);
=======
	if (!nb_lines || nb_lines == -1)
		return (NULL);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (perror(file), NULL);
	file_content = ft_calloc(sizeof(char *), nb_lines + 1);
	if (file_content == NULL)
		return (close(fd), NULL);
>>>>>>> kscordel
	i = 0;
	while (i < nb_lines)
	{
		line = get_next_line(fd);
		if (line == NULL)
<<<<<<< HEAD
			return (NULL);
		file_content[i] = line;
		i++;
	}
	file_content[i] = NULL;
=======
			return (free_array(file_content), close(fd), NULL);
		file_content[i] = line;
		i++;
	}
>>>>>>> kscordel
	skip_lines_end(fd);
	return (close(fd), file_content);
}

// argument_check will check if the argument seems valid.
// parse_map_info will parse the map info such as NO, SO, WE, EA, F, C.
// parse_map will parse the map itself (the 1, 0, N, S, E, W).
int	ft_parse(int ac, char **av, t_game *game)
{
<<<<<<< HEAD
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
	if (parse_map(game) == 0)
	{
		free_array(file_content);
		free(file_content);
		return (0);
	}
	free_array(file_content);
	free(file_content);
	return (1);
=======
	//char	**file_content;

	//file_content = NULL;
	if (argument_check(ac, av))  //ok
		return (1);
	game->map_name = av[1];
	game->file_cont = get_file_content(av[1]); //ok
	if (game->file_cont == NULL)
		return (1);	
//	game->file_cont = file_content;
	if (parse_map_info(game)) //ok
	{
		printf("ret parse info\n");
		free_array(game->file_cont);
		return (1);
	}
	if (parse_map(game))
	{
		printf("ret parse map\n");
		free_array(game->file_cont);
		return (1);
	}
	free_array(game->file_cont);
	return (0);
>>>>>>> kscordel
}
