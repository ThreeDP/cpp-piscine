# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/18 16:00:57 by dapaulin          #+#    #+#              #
#    Updated: 2023/07/18 16:01:35 by dapaulin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= hiThisIsBrainp
FLAGS			= -Wall -Wextra -Werror -std=c++98
OBJ_PATH		= ./objs/
SRC				= main.cpp
OBJ				= $(SRC:%.cpp=$(OBJ_PATH)%.o)

all: mkdir_path_objs $(NAME)

mkdir_path_objs:
	mkdir -p $(OBJ_PATH)

$(OBJ_PATH)%.o: %.cpp
	c++ $(FLAGS) -I ./ -c $< -o $@

$(NAME): $(OBJ)
	c++ $(FLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re 