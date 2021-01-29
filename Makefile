# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpetit <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/14 17:14:39 by gpetit            #+#    #+#              #
#    Updated: 2021/01/29 13:39:46 by gpetit           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

CC = clang

CFLAGS = -Wall -Werror -Wextra 

MINILIBX = minilibx/libmlx.a -framework OpenGL -framework AppKit

SRCS = main.c parsor.c map_parsor.c display.c display_minimap.c map_conversion.c display_fps.c

OBJS = $(SRCS:.c=.o)

LIBGNL = libft/gnl/get_next_line.a

LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft/gnl/ && make -C libft/ 
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBGNL) $(LIBFT) $(MINILIBX)

clean:
	make clean -C libft/gnl/ && make clean -C libft/
	rm -f $(OBJS)

fclean: clean
	make fclean -C libft/gnl/ && make fclean -C libft/
	rm -f $(NAME)
	
re: fclean $(NAME)

.PHONY: all re clean fclean
