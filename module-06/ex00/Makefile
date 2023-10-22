# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/09 23:11:37 by dapaulin          #+#    #+#              #
#    Updated: 2023/10/12 18:29:14 by dapaulin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= convert
HEADER			= define.hpp ScalarConverter.hpp
FLAGS			= -Wall -Wextra -Werror -std=c++98
OBJ_PATH		= ./objs/
SRC				= ScalarConverter.cpp main.cpp
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

r: all
	./convert "0";
	./convert "nan";
	./convert "nanf";
	./convert "42.0f";
	./convert "-42.0";
	./convert "-42";
	./convert "-42.0f";
	./convert "48";
	./convert "340282346638528859811704183484516925440.0f";
	./convert "350282346638528859811704183484516925440.0f";
	./convert "350282346638528859811704183484516925440.0";
	