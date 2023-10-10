# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/09 23:11:37 by dapaulin          #+#    #+#              #
#    Updated: 2023/10/10 12:48:36 by dapaulin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= rein
HEADER			= define.hpp Serializer.hpp data.h
FLAGS			= -Wall -Wextra -Werror -std=c++98
OBJ_PATH		= ./objs/
SRC				= Serializer.cpp main.cpp
OBJ				= $(SRC:%.cpp=$(OBJ_PATH)%.o)

all: $(NAME)

$(OBJ_PATH)%.o: %.cpp $(HEADER)
	mkdir -p $(OBJ_PATH)
	c++ $(FLAGS) -I ./ -c $< -o $@

$(NAME): $(OBJ)
	c++ $(FLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -rf $(NAME)
	rm -rf *_shrubbery

re: fclean all

.PHONY: all clean fclean re 

	