# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpetit <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/14 17:14:39 by gpetit            #+#    #+#              #
#    Updated: 2021/01/14 17:58:20 by gpetit           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a.out

CC = clang

CFLAGS = -Wall -Wextra -Werror

SRCS = main.c parsor.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): make -C $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $()

clean:
	rm $(OBJS)

fclean: clean
	rm $(NAME)
	
re: fclean $(NAME)

.PHONY: all re clean fclean
