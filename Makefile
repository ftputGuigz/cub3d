# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpetit <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/14 17:14:39 by gpetit            #+#    #+#              #
#    Updated: 2021/01/19 14:30:48 by gpetit           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = execub3d

CC = clang

CFLAGS = -Wall -Werror -Wextra 

MINILIBX = -lmlx -framework OpenGL -framework AppKit

SRCS = main.c parsor.c map_parsor.c 

OBJS = $(SRCS:.c=.o)

LIBGNL = ./srcs/gnl/get_next_line.a

LIBFT = ./srcs/libft/libft.a

all: $(NAME)

$(NAME): $(OBJS)
	make -C srcs/gnl/ && make -C srcs/libft/ 
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBGNL) $(LIBFT) $(MINILIBX)

clean:
	make clean -C srcs/gnl/ && make clean -C srcs/libft/
	rm -f $(OBJS)

fclean: clean
	make fclean -C srcs/gnl/ && make fclean -C srcs/libft/
	rm -f $(NAME)
	
re: fclean $(NAME)

.PHONY: all re clean fclean
