# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/22 12:04:28 by jvarila           #+#    #+#              #
#    Updated: 2025/06/10 09:49:56 by jvarila          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= aaaaand____open

CC			:= c++
CFLAGS		:= -Wall -Wextra -Werror -std=c++20
DEBUG_FLAGS	:= -g
# ---------------------------------------------------------------------------- #
INC_DIR		:= ./inc
HEADERS		:= $(INC_DIR)/ClapTrap.hpp
# ---------------------------------------------------------------------------- #
SRC_DIR	:=	./src
OBJ_DIR	:=	./obj
# ---------------------------------------------------------------------------- #
SRC :=	$(SRC_DIR)/ClapTrap.cpp	\
		$(SRC_DIR)/main.cpp
# ---------------------------------------------------------------------------- #
OBJ :=	$(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC))

.SECONDARY: $(OBJ)
# ---------------------------------------------------------------------------- #
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -I $(INC_DIR) $(OBJ) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADERS)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@
# ---------------------------------------------------------------------------- #
clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
# ---------------------------------------------------------------------------- #
debug: CFLAGS += $(DEBUG_FLAGS)
debug: fclean all
# ---------------------------------------------------------------------------- #
.PHONY: all clean fclean re debug
# ---------------------------------------------------------------------------- #
