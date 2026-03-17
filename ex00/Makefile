# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ankozako <ankozako@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/17 12:02:27 by ankozako          #+#    #+#              #
#    Updated: 2026/03/17 12:02:29 by ankozako         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bureaucrat

SRC = main.cpp Bureaucrat.cpp
OBJ = $(SRC:.cpp=.o)

CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

all:	$(NAME)

$(NAME): $(OBJ)
		$(CC) $(CPPFLAGS) $(SRC) -o $(NAME)

%.o: %.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re:	clean all

.PHONY: all clean fclean re

