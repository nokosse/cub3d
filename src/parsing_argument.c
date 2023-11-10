/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_argument.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvisouth <kvisouth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:29:12 by kvisouth          #+#    #+#             */
/*   Updated: 2023/11/10 13:27:04 by kvisouth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// Argument check will check if the argument seems valid.
// Meaning it has to be :
// - only 1 argument which is the map file.
// - this map file has to end with '.cub'
// - the map file has to have a character before the '.'
// - the character before the '.' has to be alphanumeric
// - this file has to exist.
int	argument_check(int ac, char **av)
{
	if (ac != 2)
	{
		return (0);
	}
	if (ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".cub", 4) != 0)
	{
		return (0);
	}
	if (ft_strlen(av[1]) <= 4 || ft_isalnum(av[1][ft_strlen(av[1]) - 5]) == 0)
	{
		return (0);
	}
	if (open(av[1], O_RDONLY) == -1)
	{
		return (0);
	}
	return (1);
}
