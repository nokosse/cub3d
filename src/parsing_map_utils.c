/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvisouth <kvisouth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:10:43 by kvisouth          #+#    #+#             */
/*   Updated: 2023/11/14 18:12:41 by kvisouth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	skip_newlines(t_game *game, int *i)
{
	while (game->file_cont[*i][0] == '\n')
		(*i)++;
}

// Will check if line (i) is completely empty (only \n at [0])
int	is_empty_line2(t_game *game, int i)
{
	if (game->file_cont[i][0] == '\n')
		return (1);
	return (0);
}

// Will check if line (i) is empty but can contain spaces.
int	is_empty_line(t_game *game, int i)
{
	int	j;

	j = 0;
	while (game->file_cont[i][j] == ' ')
		j++;
	if (game->file_cont[i][j] == '\n')
		return (1);
	return (0);
}

int	get_map_size(t_game *game, int i)
{
	int	j;
	int	size;

	j = 0;
	size = 0;
	while (game->file_cont[i] != NULL)
	{
		j = 0;
		skip_spaces(game->file_cont[i], &j);
		if (game->file_cont[i][j] != '1' && game->file_cont[i][j] != '0')
		{
			if (game->file_cont[i][0] == '\n')
			{
				game->map.map_height = size;
				return (size);
			}
			else
				return (0);
		}
		size++;
		i++;
	}
	game->map.map_height = size;
	return (size);
}

int	get_width_of_map(t_game *game)
{
	int	i;
	int	j;
	int	max;
	int	tmp;

	i = 0;
	max = 0;
	while (game->map.map[i] != NULL)
	{
		j = 0;
		tmp = 0;
		while (game->map.map[i][j] != '\n')
		{
			if (game->map.map[i][j] != ' ')
				tmp++;
			j++;
		}
		if (tmp > max)
			max = tmp;
		i++;
	}
	return (max);
}
