# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcolumbu <hcolumbu@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/30 09:09:32 by hcolumbu          #+#    #+#              #
#    Updated: 2022/03/14 10:16:40 by hcolumbu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_FR = fractol

DIR = mandatory/
FILES = main.c	draw.c	types.c	hooks.c

DIR_BONUS = bonus/
FILES_BONUS = main_bonus.c	draw_bonus.c	types_bonus.c	hooks_bonus.c

SRCS_FR = $(addprefix $(DIR), $(FILES))
SRCS_FR_BONUS = $(addprefix $(DIR_BONUS), $(FILES_BONUS))

OBJS_FR = $(SRCS_FR:%.c=%.o)
OBJS_FR_BONUS = $(SRCS_FR_BONUS:%.c=%.o)

HEADER_FR = includes/fractol.h
HEADER_FR_BONUS = includes/fractol_bonus.h
INCLUDES = includes/

CFLAGS = -Wall -Wextra -Werror -O2
LIBFT = libft/libft.a

.PHONY: all clean fclean re libft bonus

all: libft $(NAME_FR)

libft:
	@make -C libft/

bonus:
		@make OBJS_FR="$(OBJS_FR_BONUS)" \
		HEADER_FR="$(HEADER_FR_BONUS)" all

$(NAME_FR): $(OBJS_FR)
	cc $(OBJS_FR) $(LIBFT) -lmlx -framework OpenGL -framework AppKit -o $@

%.o: %.c $(LIBFT) $(HEADER_FR) Makefile
	cc $(CFLAGS) -I $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS_FR) $(OBJS_FR_BONUS)
	@make -C libft/ clean

fclean: clean
	rm -f $(NAME_FR)
	@make -C libft/ fclean

re: fclean all
