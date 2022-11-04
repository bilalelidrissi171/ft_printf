# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bel-idri <bel-idri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/03 20:41:47 by bel-idri          #+#    #+#              #
#    Updated: 2022/11/03 20:46:18 by bel-idri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c \
	ft_printf_functions.c \


# SRCSB =



OBJS = $(SRCS:.c=.o)
# OBJSB = $(SRCSB:.c=.o)


CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

AR = ar -rcs

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

# bonus: all $(OBJSB)
# 	$(AR) $(NAME) $(OBJSB)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $<

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re # bonus
