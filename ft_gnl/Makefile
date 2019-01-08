# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azkeever <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/02 10:36:43 by azkeever          #+#    #+#              #
#    Updated: 2019/01/08 14:01:14 by azkeever         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gnl
HEADER = get_next_line.h
LIBRARY = libft/libft.a
SOURCE = get_next_line.c gnl7_3.c

all: $(NAME)

$(NAME):
	gcc -Wall -Werror -Wextra $(HEADER) $(LIBRARY) $(SOURCE)

clean: 
	rm -f *.o *.swp *~ *.gch

fclean: clean
	rm -f $(NAME) a.out

re: fclean all

