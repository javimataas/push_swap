# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmatas-p <jmatas-p@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/03 16:10:26 by jmatas-p          #+#    #+#              #
#    Updated: 2023/05/09 16:06:38 by jmatas-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a

SRC =   main.c \
        argv_formatters.c \
        argv_checkers.c \
        costs.c \
        rotations_selector.c \
        swappers.c \
        rotations.c \
        sort_three.c \
        sortings.c \
        targets.c \
        tools.c \
		storage_utils.c

SRCBONUS =	checker.c \
			argv_formatters.c \
			argv_checkers.c \
			costs.c \
			rotations_selector.c \
			swappers.c \
			rotations.c \
			sort_three.c \
			sortings.c \
			targets.c \
			tools.c \
			storage_utils.c

OBJ = $(SRC:.c=.o)

OBJBONUS = $(SRCBONUS:.c=.o)

NAME = push_swap

BONUS = checker

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(BONUS): $(LIBFT) $(OBJBONUS)
	$(CC) $(CFLAGS) $(OBJBONUS) $(LIBFT) -o $(BONUS)

$(LIBFT):
	make -C libft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(BONUS) all

clean:
	rm -f $(OBJ)
	rm -f $(OBJBONUS)

fclean: clean
	rm -f $(NAME)
	rm -f $(BONUS)
	make fclean -C libft

re: fclean all

py:	all
	python3 python_visualizer.py `ruby -e "puts (-249..250).to_a.shuffle.join(' ')"`

.PHONY: all clean fclean re py
