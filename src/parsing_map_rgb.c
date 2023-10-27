/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_rgb.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvisouth <kvisouth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 09:31:13 by kvisouth          #+#    #+#             */
/*   Updated: 2023/10/27 15:38:02 by kvisouth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	store_rgb(t_game *game, char *elem, char **rgb_split)
{
	if (elem[0] == 'F')
	{
		game->floor.r = ft_atoi(rgb_split[0]);
		game->floor.g = ft_atoi(rgb_split[1]);
		game->floor.b = ft_atoi(rgb_split[2]);
	}
	else if (elem[0] == 'C')
	{
		game->ceil.r = ft_atoi(rgb_split[0]);
		game->ceil.g = ft_atoi(rgb_split[1]);
		game->ceil.b = ft_atoi(rgb_split[2]);
	}
	free(rgb_split[0]);
	free(rgb_split[1]);
	free(rgb_split[2]);
	free(rgb_split);
}

int	check_rgb_ints(t_game *game, char *elem)
{
	if (elem[0] == 'F')
	{
		if (game->floor.r < 0 || game->floor.r > 255)
			return (0);
		if (game->floor.g < 0 || game->floor.g > 255)
			return (0);
		if (game->floor.b < 0 || game->floor.b > 255)
			return (0);
	}
	else if (elem[0] == 'C')
	{
		if (game->ceil.r < 0 || game->ceil.r > 255)
			return (0);
		if (game->ceil.g < 0 || game->ceil.g > 255)
			return (0);
		if (game->ceil.b < 0 || game->ceil.b > 255)
			return (0);
	}
	return (1);
}

int	split_and_check_ints(char *path, int flag, t_game *game, char *elem)
{
	int		i;
	char	*rgb;
	char	**rgb_split;

	rgb = malloc(sizeof(char) * (flag + 1));
	if (rgb == NULL)
		return (0);
	i = 0;
	while (i < flag)
	{
		rgb[i] = path[i];
		i++;
	}
	rgb[i] = '\0';
	rgb_split = ft_split(rgb, ',');
	free(rgb);
	if (rgb_split == NULL)
		return (0);
	store_rgb(game, elem, rgb_split);
	if (check_rgb_ints(game, elem) == 0)
		return (0);
	return (1);
}

// This function will parse the *path and store the RGB values in t_game.
// The path have to be : "R,G,B" with R, G and B being ints between 0 & 255.
int	parse_rgb(char *path, t_game *game, char *elem)
{
	int		i;
	int		flag;

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
	if (path[i] != '\0' && path[i] != '\n' && path[i] != ' ' && path[i] != '\t')
		return (0);
	flag = i;
	if (split_and_check_ints(path, flag, game, elem) == 0)
		return (0);
	return (1);
}

// A slightly modified version of get_path() from src/parsing_map_info.c
// This one will work 100% like the other one but it is freeing path_cpy.
static int	get_path(char *str, t_game *game, char *elem)
{
	int		i;
	char	*path;
	char	*path_cpy;

	i = 0;
	while (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i] != '\0')
		i++;
	path = malloc(sizeof(char) * (i + 1));
	if (path == NULL)
		return (0);
	i = 0;
	while (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i] != '\0')
	{
		path[i] = str[i];
		i++;
	}
	path[i] = '\0';
	path_cpy = ft_strdup(path);
	free(path);
	if (parse_rgb(path_cpy, game, elem) == 0)
		return (0);
	free(path_cpy);
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
