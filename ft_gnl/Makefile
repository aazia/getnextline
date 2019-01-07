# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azkeever <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/02 10:36:43 by azkeever          #+#    #+#              #
#    Updated: 2019/01/07 15:36:39 by azkeever         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gnl
HEADER = get_next_line.h
LIBRARY = libft/libft.a
SOURCE = get_next_line.c gnl1_2.c

all: $(NAME)

$(NAME):
	gcc -Wall -Werror -Wextra $(HEADER) $(LIBRARY) $(SOURCE)

clean: 
	rm -f *.o *.swp *~ *.gch

fclean: clean
	rm -f $(NAME) a.out

re: fclean all

