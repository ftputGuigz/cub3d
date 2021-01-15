# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpetit <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/14 17:14:39 by gpetit            #+#    #+#              #
#    Updated: 2021/01/15 12:38:45 by gpetit           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a.out

CC = clang

CFLAGS = -Wall -Werror -Wextra 

SRCS = main.c parsor.c map_parsor.c

OBJS = $(SRCS:.c=.o)

LIBGNL = ./srcs/gnl/get_next_line.a

LIBFT = ./srcs/libft/libft.a

all: $(NAME)

$(NAME): $(OBJS)
	make -C srcs/gnl/ && make -C srcs/libft/ 
	$(CC) $(CFLAGS) $(OBJS) $(LIBGNL) $(LIBFT)

clean:
	make clean -C srcs/gnl/ && make clean -C srcs/libft/
	rm -f $(OBJS)

fclean: clean
	make fclean -C srcs/gnl/ && make fclean -C srcs/libft/
	rm -f $(NAME)
	
re: fclean $(NAME)

.PHONY: all re clean fclean
