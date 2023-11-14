# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kvisouth <kvisouth@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/07 12:36:43 by kvisouth          #+#    #+#              #
#    Updated: 2023/11/14 16:39:45 by kvisouth         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

SRCS =	main.c \
		parsing_main.c \
		parsing_argument.c \
		parsing_elem_info.c \
		parsing_elem_utils.c \
		parsing_elem_rgb.c \
		parsing_rgb_utils.c \
		parsing_utils.c \
		parsing_paths.c \
		parsing_error_message.c \
		parsing_map.c \
		parsing_check_map.c \
		parsing_check_player.c \

OBJS = $(addprefix obj/, $(notdir $(SRCS:.c=.o)))

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3

LIBFT_MAKEFILE = libft/Makefile
MINILIBX_MAKEFILE = minilibx-linux/Makefile

all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft
	@make -C minilibx-linux
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L libft -lft -L minilibx-linux -lmlx -lXext -lX11 -lm

obj/%.o: src/%.c
	@mkdir -p obj
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make -C libft clean
	@make -C minilibx-linux clean
	@rm -rf obj

fclean: clean
	@make -C libft fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
