# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/18 13:11:02 by dapaulin          #+#    #+#              #
#    Updated: 2023/08/22 14:57:38 by dapaulin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= BraiiiiiiinnnzzzZ
HEADER			= Zombie.hpp 
FLAGS			= -Wall -Wextra -Werror -std=c++98
OBJ_PATH		= ./objs/
SRC				= Zombie.cpp main.cpp newZombie.cpp randomChump.cpp
OBJ				= $(SRC:%.cpp=$(OBJ_PATH)%.o)

all: mkdir_path_objs $(NAME)

mkdir_path_objs:
	mkdir -p $(OBJ_PATH) $(HEADER)

$(OBJ_PATH)%.o: %.cpp
	c++ $(FLAGS) -I ./ -c $< -o $@

$(NAME): $(OBJ)
	c++ $(FLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re 