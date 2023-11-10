/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_error_message.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvisouth <kvisouth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 13:17:07 by kvisouth          #+#    #+#             */
/*   Updated: 2023/11/10 13:39:50 by kvisouth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	parse_error_msg(void)
{
	printf("Error\n");
	printf("\nUsage: ./cub3D <map.cub>\n\n");
	printf("The map.cub file must follow the following rules :\n");
	printf("The elements :\n");
	printf("\t- Each elements must be separatated by one or more newlines.\n");
	printf("\t- Those newlines must be completely empty lines\n");
	printf("\t- The arguments of an element can be separated by space(s)\n");
	printf("\t- The elements can be in mixed order\n");
	printf("\t- There must be in the following elements :");
	printf(" R, NO, SO, WE, EA, S, F, C\n");
	printf("\t- The assets must be in .xpm format\n");
	printf("\nThe map :\n");
	printf("\t- The map must be placed after all the elements\n");
	printf("\t- The map must be surrounded by walls\n");
	printf("\t- The map must contain one of character inside : N, S, E, W\n");
}
