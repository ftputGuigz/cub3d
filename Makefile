# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpetit <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/14 17:14:39 by gpetit            #+#    #+#              #
#    Updated: 2021/02/26 10:54:23 by gpetit           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

IMG = img.bmp

CC = clang

CFLAGS = -Wall -Werror -Wextra

OS = $(shell uname -s)

MAX_RESX = $(shell system_profiler SPDisplaysDataType | grep -m 1 Resolution | tr -s ' ' | cut -d ' ' -f 3)

MAX_RESY = $(shell system_profiler SPDisplaysDataType | grep -m 1 Resolution | tr -s ' ' | cut -d ' ' -f 5)

MINILIBX = ./minilibx/libmlx.a -framework OpenGL -framework AppKit 

MINILIBX_LINUX = -L ./minilibx-linux -lmlx -lXext -lX11

SRCS_RAW = parsor parsor2 parsor3 parsor4 main map_parsor display movements display_fps \
		display_sprites display_sprites2 bmp_maker initialize screen_size

SRCS = $(addsuffix .c, $(addprefix srcs/, $(SRCS_RAW)))

SRCS_BONUS = $(addsuffix _bonus.c, $(addprefix srcs_bonus/, $(SRCS_RAW) display_minimap))

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

DEP = -Iincludes

LIBGNL = ./libft/gnl/get_next_line.a

LIBFT = ./libft/libft.a

all: $(NAME)

%.o: %.c
ifeq ($(OS),Linux)
	$(CC) $(CFLAGS) $(DEP) -o $@ -c $< -D LINUX=1 -D MAX_X=0 -D MAX_Y=0
else
	$(CC) $(CFLAGS) $(DEP) -o $@ -c $< -D LINUX=0 -D MAX_X=$(MAX_RESX) -D MAX_Y=$(MAX_RESY)
endif

$(NAME): libs $(OBJS) 
ifeq ($(OS),Linux)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBGNL) $(LIBFT) $(MINILIBX_LINUX) -lm
else
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBGNL) $(LIBFT) $(MINILIBX)
endif

bonus : libs $(OBJS_BONUS)
ifeq ($(OS),Linux)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS_BONUS) $(LIBGNL) $(LIBFT) $(MINILIBX_LINUX) -lm
else
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS_BONUS) $(LIBGNL) $(LIBFT) $(MINILIBX) 
endif

libs :
ifeq ($(OS),Linux)
	make -C minilibx-linux/ && make -C libft/gnl/ && make -C libft/
else
	make -C minilibx/ && make -C libft/gnl/ && make -C libft/
endif

clean:
ifeq ($(OS),Linux)
	make clean -C libft/gnl/ && make clean -C libft/ && make clean -C minilibx-linux/
else
	make clean -C libft/gnl/ && make clean -C libft/ && make clean -C minilibx/
endif
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	make fclean -C libft/gnl/ && make fclean -C libft/
	rm -f $(NAME) $(IMG)
	
re: fclean $(NAME)

.PHONY: all re clean fclean
