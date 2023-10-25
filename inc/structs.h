/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvisouth <kvisouth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:30:41 by kvisouth          #+#    #+#             */
/*   Updated: 2023/10/25 16:25:17 by kvisouth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

// All the content of a map :
// The argument, it is the map file.
// The textures paths :
//      - NO ./path_to_the_north_texture
//      - SO ./path_to_the_south_texture
//      - WE ./path_to_the_west_texture
//      - EA ./path_to_the_east_texture
// The color of the ceiling and the floor :
//      - F 220,100,0
//      - C 225,30,0
// The map is composed of :
// 1 and 0 : Walls and empty spaces
// N, S, E, W : The player's starting position and orientation

// t_rgb contains the 3 colors of the rgb format.
// It is for the ceiling and the floor arguments.
typedef struct s_rgb
{
	int		r;
	int		g;
	int		b;
}				t_rgb;

// t_map contains all the informations about the map.
// (The map is all the 1, 0 and N S E or W)
typedef struct s_map
{
	char		**map;
	int			map_width;
	int			map_height;
	t_player	player;
}				t_map;

// t_player contains all the informations about the player.
typedef struct s_player
{
	int		pos_x;
	int		pos_y;
	char	orient;
}				t_player;

// t_game is the main strucure.
// it includes all the others structures.
typedef struct s_game
{
	char		*map_name;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	t_rgb		floor;
	t_rgb		ceil;
	t_map		map;
	t_player	player;
}				t_game;

#endif