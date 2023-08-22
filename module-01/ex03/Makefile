# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/18 16:06:39 by dapaulin          #+#    #+#              #
#    Updated: 2023/08/22 14:58:29 by dapaulin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= unnecessaryViolence
HEADER			= Weapon.hpp HumanA.hpp HumanB.hpp
FLAGS			= -Wall -Wextra -Werror -std=c++98
OBJ_PATH		= ./objs/
SRC				= main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
OBJ				= $(SRC:%.cpp=$(OBJ_PATH)%.o)

all: mkdir_path_objs $(NAME)

mkdir_path_objs:
	mkdir -p $(OBJ_PATH)

$(OBJ_PATH)%.o: %.cpp $(HEADER)
	c++ $(FLAGS) -I ./ -c $< -o $@

$(NAME): $(OBJ)
	c++ $(FLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re 