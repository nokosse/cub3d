/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_info.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvisouth <kvisouth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:28:34 by kvisouth          #+#    #+#             */
/*   Updated: 2023/11/06 17:51:14 by kvisouth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	parse_path(char *str, t_game *game, char *elem)
{
	printf("str = %s\n", str);
	(void)game;
	(void)elem;
	return (1);
}

int	parse_rgb(char *str, t_game *game, char *elem)
{
	printf("str = %s\n", str);
	(void)game;
	(void)elem;
	return (1);	
}

// Will search in game->file_cont (is a char**) for *elem.
// If it finds it, it will parse the path.
int	search_elem(char *elem, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->file_cont[i] != NULL)
	{
		j = 0;
		skip_spaces_tabs(game->file_cont[i], &j);
		if ((ft_strncmp(game->file_cont[i] + j, elem, ft_strlen(elem)) == 0)
			&& (game->file_cont[i][j + ft_strlen(elem)] == ' '
			|| game->file_cont[i][j + ft_strlen(elem)] == '\t'))
		{
			printf("Found %s\n", elem);
			j += ft_strlen(elem);
			skip_spaces_tabs(game->file_cont[i], &j);
			if (elem[0] != 'F' && elem[0] != 'C')
			{
				if (parse_path(game->file_cont[i] + j, game, elem) == 0)
					return (0);
			}
			else
			{
				if (parse_rgb(game->file_cont[i] + j, game, elem) == 0)
					return (0);
			}
			return (1);
		}
		i++;
	}
	printf("Couldn't find %s\n", elem);
	return (0);
}

int	parse_map_info(t_game *game)
{
	if (search_elem("NO", game) == 0)
		return (0);
	if (search_elem("SO", game) == 0)
		return (0);
	if (search_elem("WE", game) == 0)
		return (0);
	if (search_elem("EA", game) == 0)
		return (0);
	if (search_elem("F", game) == 0)
		return (0);
	if (search_elem("C", game) == 0)
		return (0);
	return (1);
}
