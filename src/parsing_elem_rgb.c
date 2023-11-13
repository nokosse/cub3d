/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_elem_rgb.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvisouth <kvisouth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 09:31:13 by kvisouth          #+#    #+#             */
/*   Updated: 2023/11/13 16:45:35 by kvisouth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	check_string_valid(char *str)
{
	int	i;

	i = 0;
	if (ft_isdigit(str[i]) == 0)
		return (0);
	while (ft_isdigit(str[i]) == 1)
		i++;
	if (skip_spaces(str, &i), str[i++] != ',')
		return (0);
	skip_spaces(str, &i);
	if (ft_isdigit(str[i]) == 0)
		return (0);
	while (ft_isdigit(str[i]) == 1)
		i++;
	if (skip_spaces(str, &i), str[i++] != ',')
		return (0);
	skip_spaces(str, &i);
	if (ft_isdigit(str[i]) == 0)
		return (0);
	while (ft_isdigit(str[i]) == 1)
		i++;
	skip_spaces(str, &i);
	if (str[i] != '\0' && str[i] != '\n' && str[i] != ' ')
		return (0);
	return (1);
}

void	store_rgb_values(char **rgb, t_game *game, char *elem)
{
	if (elem[0] == 'F')
	{
		game->floor.r = ft_atoi(rgb[0]);
		game->floor.g = ft_atoi(rgb[1]);
		game->floor.b = ft_atoi(rgb[2]);
	}
	else if (elem[0] == 'C')
	{
		game->ceil.r = ft_atoi(rgb[0]);
		game->ceil.g = ft_atoi(rgb[1]);
		game->ceil.b = ft_atoi(rgb[2]);
	}
}

int	check_valid_rgb_number(char *str, t_game *game, char *elem)
{
	char	**rgb;

	rgb = NULL;
	rgb = ft_split(str, ',');
	if (ft_atoi(rgb[0]) > 255 || ft_atoi(rgb[0]) < 0)
	{
		free_array(rgb);
		return (0);
	}
	if (ft_atoi(rgb[1]) > 255 || ft_atoi(rgb[1]) < 0)
	{
		free_array(rgb);
		return (0);
	}
	if (ft_atoi(rgb[2]) > 255 || ft_atoi(rgb[2]) < 0)
	{
		free_array(rgb);
		return (0);
	}
	store_rgb_values(rgb, game, elem);
	free_array(rgb);
	return (1);
}

int	parse_rgb(char *str, t_game *game, char *elem)
{
	if (check_string_valid(str) == 0)
		return (0);
	if (check_valid_rgb_number(str, game, elem) == 0)
		return (0);
	return (1);
}
