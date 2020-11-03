# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmorimot <kmorimot@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/12 13:07:44 by kmorimot          #+#    #+#              #
#    Updated: 2020/11/03 19:51:09 by kmorimot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a
CC := gcc
CFLAGS := -Wall -Wextra -Werror
SRC_DIR := ./
SRCS := ft_printf.c \
		ft_printf_utils.c \
		ft_get_format.c \
		ft_get_type_and_output.c \
		ft_get_type_and_output2.c \
		ft_output_null_p.c \
		ft_output_null_p2.c \
		ft_output_null_s.c \
		ft_output_null_s2.c \
		ft_type_largex.c \
		ft_type_c.c \
		ft_type_d.c \
		ft_type_d2.c \
		ft_type_d3.c \
		ft_type_p.c \
		ft_type_p2.c \
		ft_type_s.c \
		ft_type_s2.c \
		ft_type_u.c \
		ft_type_u2.c \
		ft_type_u3.c \
		ft_type_x1.c \
		ft_type_x2.c 
OBJS := $(SRCS:.c=.o)
INCLUDE := -I.ft_printf.h \
	   -I./libft/libft.h \

AR := ar
ARFLAGS := rcs

.c.o:
	$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $<

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)
	$(MAKE) -C ./libft clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C ./libft fclean

re: fclean all

.PHONY: all clean fclean re
