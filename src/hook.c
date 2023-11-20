#include "../inc/cub3d.h"

int	key_hook(int key, t_game *data)
{
	if (key == 65307)
		quit(data);
    return (0);
}

