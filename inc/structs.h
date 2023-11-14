/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvisouth <kvisouth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:30:41 by kvisouth          #+#    #+#             */
/*   Updated: 2023/11/14 18:13:51 by kvisouth         ###   ########.fr       */
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

// t_player contains all the informations about the player.
// pos_x is the player position on the x axis.
// pos_y is the player position on the y axis.
// It is the position of the player in game->map.map[x][y]
typedef struct s_player
{
	int		pos_x;
	int		pos_y;
	char	orient;
}				t_player;

// t_map contains all the informations about the map.
// (The map is all the 1, 0 and N S E or W)
typedef struct s_map
{
	char		**map;
	int			map_start;
	int			map_end;
	int			map_width;
	int			map_height;
	t_player	player;
}				t_map;

// t_parse contains all the informations about the parsing.
// elem_lines is an array of int.
// elem_lines[0] is the line in the file where the NO argument is.
// elem_lines[1] is the same for SO.
// all the way with this order: NO (0), SO (1), WE (2), EA (3), F (4), C (5).
// last_elem is the last element parsed.
// it's the lower (in lines) of the arguments.
// it's the closest element to the map.
typedef struct s_parse
{
	int			elem_lines[6];
	int			last_elem;
	int			last_line;
}				t_parse;

// t_game is the main strucure.
// it includes all the others structures.
typedef struct s_game
{
	char		*map_name;
	char		**file_cont;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	t_rgb		floor;
	t_rgb		ceil;
	t_map		map;
	t_parse		parse;
	t_player	player;
}				t_game;

#endif