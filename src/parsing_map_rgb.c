/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_rgb.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvisouth <kvisouth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 09:31:13 by kvisouth          #+#    #+#             */
/*   Updated: 2023/10/27 11:18:25 by kvisouth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// This function will parse the string (path) and store the RGB values in t_game.
// The path have to be : "R,G,B" with R, G and B being integers between 0 and 255.
int	parse_rgb(char *path, t_game *game, char *elem)
{
	int		i;
	int		flag;
	char	*rgb;
	char	**rgb_split;

	(void)elem;
	(void)game;
	

	// The part to check if the path is valid. (R,G,B)
	i = 0;
	while (ft_isdigit(path[i]) == 1)
		i++;
	if (path[i] != ',' || i == 0)
		return (0);
	i++;
	if (ft_isdigit(path[i]) == 0)
		return (0);
	while (ft_isdigit(path[i]) == 1)
		i++;
	if (path[i] != ',')
		return (0);
	i++;
	if (ft_isdigit(path[i]) == 0)
		return (0);
	while (ft_isdigit(path[i]) == 1)
		i++;
	

	// The part to put the RGB values to a string
	flag = i;
	rgb = malloc(sizeof(char) * (i + 1));
	if (rgb == NULL)
		return (0);
	i = 0;
	while (i < flag)
	{
		rgb[i] = path[i];
		i++;
	}
	rgb[i] = '\0';


	// The part we split the R,G,B values with ft_split()
	rgb_split = ft_split(rgb, ',');
	if (rgb_split == NULL)
		return (0);
	ft_putchar_fd('\n', 1);


	// The part we check if the values are between 0 and 255
	if (ft_atoi(rgb_split[0]) < 0 || ft_atoi(rgb_split[0]) > 255)
		return (0);
	if (ft_atoi(rgb_split[1]) < 0 || ft_atoi(rgb_split[1]) > 255)
		return (0);
	if (ft_atoi(rgb_split[2]) < 0 || ft_atoi(rgb_split[2]) > 255)
		return (0);

	printf("elem : %s\n", elem);
	printf("rgb_split[0] : %s\n", rgb_split[0]);
	printf("rgb_split[1] : %s\n", rgb_split[1]);
	printf("rgb_split[2] : %s\n", rgb_split[2]);
	
	// The part we store the values of rgb_split in t_game.
	// if (elem == 'F')
	// {
	// 	game->floor.r = ft_atoi(rgb_split[0]);
	// 	game->floor.g = ft_atoi(rgb_split[1]);
	// 	game->floor.b = ft_atoi(rgb_split[2]);
	// }
	// else if (elem == "C")
	// {
	// 	game->ceil.r = ft_atoi(rgb_split[0]);
	// 	game->ceil.g = ft_atoi(rgb_split[1]);
	// 	game->ceil.b = ft_atoi(rgb_split[2]);
	// }
	return (1);
}

// A slightly modified version of process_element() from src/parsing_map_info.c
// This one will not check for elem[1] because we are searching for 1 letter
// elements (F and C).
static int	process_element(char *line, t_game *game, char *elem, int *i)
{
	skip_spaces_tabs(line, i);
	if (line[*i] == elem[0] && (line[*i + 1] == ' ' || line[*i + 1] == '\t'))
	{
		*i += 1;
		skip_spaces_tabs(line, i);
		if (line[*i] == '\0' || line[*i] == '\n')
			return (0);
		if (get_path(&line[*i], game, elem) == 0)
			return (0);
		return (1);
	}
	return (0);
}

int	search_rgb(int fd, char *elem, t_game *game)
{
	char	*line;
	int		result;
	int		i;

	line = NULL;
	i = 0;
	line = get_next_line(fd);
	if (line == NULL)
		return (0);
	while (line != NULL)
	{
		result = process_element(line, game, elem, &i);
		free(line);
		if (result == 1)
			return (1);
		line = get_next_line(fd);
		if (line == NULL)
			break ;
	}
	skip_lines(fd);
	if (line != NULL)
		free(line);
	return (0);
}