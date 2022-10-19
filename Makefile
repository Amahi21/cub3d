# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amahi <amahi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/19 11:28:23 by amahi             #+#    #+#              #
#    Updated: 2022/10/19 12:17:37 by amahi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	=	cub3d

HEADER	=	cub3d.h

LIBRARIES = -Lmlx -lmlx -framework OpenGL -framework AppKit -lm


FLAGS 	=	#-Wextra -Werror -Wall
# FLAGS =	-Wextra -Werror -Wall -fsanitize=address -fsanitize=undefined

SOURCE	=	main.c				GNL/get_next_line.c			\
			GNL/get_next_line_utils.c


OBJECT	=	$(SOURCE:.c=.o)

.PHONY	:	all clean fclean re

all		:	$(NAME)

$(NAME)	:	$(OBJECT)
			$(CC) $(OBJECT) -g $(LIBRARIES) -o $(NAME)

%.o		:	%.c $(HEADER)
			$(CC) $(FLAGS) -Imlx -g -c $< -o $@

clean	:
			$(RM) $(OBJECT)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all