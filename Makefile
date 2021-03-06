# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: bprado <bprado@student.42.fr>                +#+                      #
#                                                    +#+                       #
#    Created: 2019/01/29 17:19:55 by bprado         #+#    #+#                 #
#    Updated: 2019/05/24 14:55:13 by bprado        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FLAGS = -Wall -Wextra -Werror

SRC = main.c get_input.c validate_input.c transform_input.c grid.c solver.c

LIB = ./libft

HDR = ./fillit.h

OBJ += $(SRC:.c=.o)

all: $(NAME)

$(NAME):
		make -C $(LIB) re
		gcc -o $(NAME) $(SRC) -I $(HDR) $(LIB)/libft.a $(FLAGS)

clean:
		rm -f $(OBJ)
		make -C $(LIB) clean

fclean: clean
		rm -rf $(NAME)
		make -C $(LIB) fclean

re: fclean all
