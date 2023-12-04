#include "../inc/cub3d.h"

int	key_down_hook(int key, t_game *game)
{
	//printf("key = %d\n", key);
	if (key == ECHAP)
		quit(game);
	if (key == K_LEFT)
	{
		game->mouv.rotate_left = true;
	//	game->mouv.rotate_dir = -1;
	}
	if (key == K_RIGHT)
	{
		game->mouv.rotate_right = true;
	//	game->mouv.rotate_dir = 1;
	}
	if (key == K_UP || key == K_W)
		game->mouv.go_straigth = true;
	if (key == K_DOWN || key == K_S)
		game->mouv.go_backward = true;
	if (key == K_A)
		game->mouv.go_left = true;
	if (key == K_D)
		game->mouv.go_right = true;
	return (0);
}

int	key_up_hook(int key, t_game *game)
{
	if (key == K_LEFT)
	{
		game->mouv.rotate_left = false;
	//	game->mouv.rotate_dir = 0;
	}
	if (key == K_RIGHT)
	{
		game->mouv.rotate_right = false;
	//	game->mouv.rotate_dir = 0;
	}
	if (key == K_UP || key == K_W)
		game->mouv.go_straigth = false;
	if (key == K_DOWN || key == K_S)
		game->mouv.go_backward = false;
	if (key == K_A)
		game->mouv.go_left = false;
	if (key == K_D)
		game->mouv.go_right = false;
	return (0);
}
