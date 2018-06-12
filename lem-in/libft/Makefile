# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpop <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/25 02:05:19 by gpop              #+#    #+#              #
#    Updated: 2018/06/12 14:04:30 by gpop             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FUNCTIONS = ft_bzero \
			ft_memmove \
			ft_memdel \
			ft_strdel \
			ft_strlen \
			ft_strdup \
			ft_strcpy \
			ft_strncat \
			ft_strchr \
			ft_strstr \
			ft_strcmp \
			ft_atoi \
			ft_isdigit \
			ft_strnew \
			ft_strsub \
			ft_strjoin \
			ft_putchar \
			ft_putstr \
			ft_putendl \
			ft_putnbr \
			ft_lstnew \
			ft_lstadd \
			ft_intlen \
			ft_lstlen \
			ft_lstappend \
			ft_strshorten \
			ft_strcutuntil \
			get_next_line \
			ft_isnumeric_str
OBJ = $(patsubst %,%.o,$(FUNCTIONS))
SRC = $(patsubst %,%.c,$(FUNCTIONS))
CFLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)
	@true

$(NAME):
	@gcc -I ./includes $(CFLAGS) -c $(SRC)
	@ar rcs $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
