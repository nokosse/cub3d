/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvisouth <kvisouth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:30:26 by kvisouth          #+#    #+#             */
/*   Updated: 2023/10/25 13:32:23 by kvisouth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

//for minimap
# define MINI_SIZE 360
# define MINI_BLOCK 20
# define MINI_PERSO 4
# define MINI_WALL_COLOR 0xFF000066
# define MINI_FLOOR_COLOR 0xFF99CCFF
# define MINI_PERSO_COLOR 0xFFFF3333

//key_presse
# define K_UP		65362
# define K_DOWN		65364
# define K_LEFT		65361
# define K_RIGHT	65363
# define K_W		122
# define K_S		115
# define K_A		113
# define K_D		100
# define ECHAP		65307

//# define PI 3.14159265358979323846264338327950288419716939937510582
# define PI 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117067982148086513282306647093844609550582231725359408128481117450284102701938521105559644622948954930381964428810975665933446128475648233786783165

# define ROTATION_SPEED 1 * (PI / 180) 
# define MOUV_SPEED     1
# define FOV            60 * (PI / 180)

#endif