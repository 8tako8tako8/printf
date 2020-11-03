# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tauehara <tauehara@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/12 23:42:23 by tauehara          #+#    #+#              #
#    Updated: 2020/10/30 13:58:21 by tauehara         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		:=	gcc
CFLAGS	:=	-Wall -Wextra -Werror
SRC_DIR	:=	./
SRCS	:=	ft_printf.c  \
			check_format.c \
            output_format.c \
            parse_format.c \
            parse_format2.c \
			create_str_by_precision.c \
			create_str_by_precision2.c \
			padding_zero_strnum.c \
            print_format.c \
			print_str_by_field_width.c \
			print_str_by_field_width2.c \
            fmt_flgs_utils.c \
			ft_itoa_hex.c \
			ft_uitoa.c \
			ft_ptoa.c \
			ft_putstr.c \
			mem_free.c
B_SRCS	:=	$(SRCS)
OBJS	:=	$(SRCS:.c=.o)
B_OBJS	:=	$(OBJS) $(B_SRCS:.c=.o)
INCLUDE := -I.ft_printf.h \
			-I./libft/libft.h
NAME	:=	libftprintf.a
AR		:=	ar
ARFLAGS	:=	rcs

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

bonus: $(B_OBJS) 
	$(AR) $(ARFLAGS) $(NAME) $(B_OBJS)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $<

clean:
	$(RM) $(OBJS) $(B_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:	all clean fclean re bonus
