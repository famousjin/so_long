# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myyou <myyou@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/19 12:47:36 by myyou             #+#    #+#              #
#    Updated: 2022/11/20 19:45:22 by myyou            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = so_long

SRC	    = 	so_long.c \
			map_name_check.c \	
			map.c \
			end.c \
			game_start.c \
			walk.c \
			side.c \
			move.c \
			get_next_line.c \
			get_next_line_utils.c \
			ft_printf.c \ 
			ft_printf_utils.c \
			ft_printf_utils2.c \

OBJS	= $(SRCS:.c=.o)

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -lmlx -framework OpenGL -framework Appkit -o $(NAME)

%.o: %.c
	$(CC) -Imlx -Imac -03 -c $< -o $@

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all