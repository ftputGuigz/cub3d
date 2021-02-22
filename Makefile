# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpetit <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/14 17:14:39 by gpetit            #+#    #+#              #
#    Updated: 2021/02/22 19:09:52 by gpetit           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

IMG = img.bmp

CC = clang

CFLAGS = -Wall -Werror -Wextra

MINILIBX = ./minilibx/libmlx.a -framework OpenGL -framework AppKit 

SRCS = $(addprefix srcs/, parsor.c main.c map_parsor.c display.c display_minimap.c movements.c display_fps.c \
	   display_sprites.c bmp_maker.c initialize.c)

OBJS = $(SRCS:.c=.o)

DEP = -I includes/

LIBGNL = ./libft/gnl/get_next_line.a

LIBFT = ./libft/libft.a

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(DEP) -o $@ -c $<

$(NAME): $(OBJS) libs
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBGNL) $(LIBFT) $(MINILIBX)

libs : 
	 make -C minilibx/ && make -C libft/gnl/ && make -C libft/

clean:
	make clean -C libft/gnl/ && make clean -C libft/ && make clean -C minilibx/
	rm -f $(OBJS)

fclean: clean
	make fclean -C libft/gnl/ && make fclean -C libft/
	rm -f $(NAME) $(IMG)
	
re: fclean $(NAME)

.PHONY: all re clean fclean
