/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_rgb.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvisouth <kvisouth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 09:31:13 by kvisouth          #+#    #+#             */
/*   Updated: 2023/11/07 17:35:54 by kvisouth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	parse_rgb(char *str, t_game *game, char *elem)
{
	int	i;

	// part 1 : check if the string is valid
	i = 0;
	if (ft_isdigit(str[i]) == 0)
		return (0);
	while (ft_isdigit(str[i]) == 1)
		i++;
	if (str[i] != ',')
		return (0);
	i++;
	if (ft_isdigit(str[i]) == 0)
		return (0);
	while (ft_isdigit(str[i]) == 1)
		i++;
	if (str[i] != ',')
		return (0);
	i++;
	if (ft_isdigit(str[i]) == 0)
		return (0);
	while (ft_isdigit(str[i]) == 1)
		i++;
	if (str[i] != '\0' && str[i] != '\n' && str[i] != ' ' && str[i] != '\t')
		return (0);
	
	// part 2 : check if the numbers are between 0 and 255
	char	**rgb;
	
	rgb = NULL;
	rgb = ft_split(str, ',');
	if (ft_atoi(rgb[0]) > 255 || ft_atoi(rgb[0]) < 0)
	{
		free_array(rgb);
		free(rgb);
		return (0);
	}
	if (ft_atoi(rgb[1]) > 255 || ft_atoi(rgb[1]) < 0)
	{
		free_array(rgb);
		free(rgb);
		return (0);
	}
	if (ft_atoi(rgb[2]) > 255 || ft_atoi(rgb[2]) < 0)
	{
		free_array(rgb);
		free(rgb);
		return (0);
	}
	
	// part 3 : store the numbers in the struct
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

	free_array(rgb);
	free(rgb);
	return (1);	
}