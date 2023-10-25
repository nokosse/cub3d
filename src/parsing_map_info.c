/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_info.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvisouth <kvisouth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:28:34 by kvisouth          #+#    #+#             */
/*   Updated: 2023/10/25 16:44:46 by kvisouth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// This function will check if the map info exist.
// It will check if there is a :
// NO ./path_to_texture
int	check_exist(char *map_file)
{
	
}

// We will check if the map info are VALID.
// We are not putting anything in the t_game struct yet.
// We will do this once all the parsing is done.
//
// The map info are :
// - NO, SO, WE, EA, F, C
// We MUST have all of them in the map file.
// So first, we will check if they all exist.
// If all of these informations exist, we will then check
// if they are VALID.
// If they are VALID, then we can return 1.
int	parse_map_info(char *map_file)
{
	if (check_exist(map_file) == 0)
		return (0);
	return (1);
}