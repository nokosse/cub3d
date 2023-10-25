/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvisouth <kvisouth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:27:14 by kvisouth          #+#    #+#             */
/*   Updated: 2023/10/25 16:28:19 by kvisouth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// argument_check will check if the argument seems valid.
// parse_map_info will parse the map info such as NO, SO, WE, EA, F, C.
// parse_map will parse the map itself (the 1, 0, N, S, E, W).
int	ft_parse(int ac, char **av)
{
	if (argument_check(ac, av) == 0)
		return (0);
	if (parse_map_info(av[1]) == 0)
		return (0);
	if (parse_map(av[1]) == 0)
		return (0);
	return (1);
}
