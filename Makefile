# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcambaki <jcambaki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/30 12:09:28 by jcambaki          #+#    #+#              #
#    Updated: 2022/01/24 13:36:55 by jcambaki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
GREY = \033[4;34m
RED = \033[1;31m
GREEN = \033[3;32m
YELLOW = \033[2;49;33m
BLUE = \033[4;34m
BLUEE = \033[3;34m
PURPLE = \033[3;35m
CYAN = \033[3;36m
RESET = \033[0m
ICONOK = \033[1;32m
ICONKO = \033[1;31m
CO_DELET = \033[3;31m
CO_A_OUT = \033[96m
WHITE = \033[1;49;97m

NAME			=	containers

INCS_DIR		=	incs
SRCS_DIR		=	srcs
COMPILED_DIR	=	compiled_sources

-include		includes.mk
SRCS_FILES		=	main.cpp

INCS			=	$(addprefix $(INCS_DIR)/,$(INCS_FILES))
OBJS			=	$(addprefix $(COMPILED_DIR)/,$(SRCS_FILES:.cpp=.o))

CC				=	clang++
FLAGS			=	-Wall -Wextra -Werror -std=c++98 -g

all: $(NAME)

$(COMPILED_DIR)/%.o:$(SRCS_DIR)/%.cpp	$(INCS)
	mkdir -p $(@D)
	$(CC) $(FLAGS) -I $(INCS_DIR) -o $@ -c $<

$(NAME): $(INCS) $(OBJS)
	$(CC) $(FLAGS) -I $(INCS_DIR) -o $(NAME) $(OBJS)

clean:
	rm -rf $(COMPILED_DIR)

fclean: clean
	rm -f $(NAME)

re:	fclean all

tmap: fclean all
	@printf "\n\033[2K\r$(GREEN)################################$(RESET)\n"
	@printf "\033[2K\r$(GREEN)########### Test Map ###########$(RESET)\n"
	@printf "\033[2K\r$(GREEN)################################$(RESET)\n\n"
	-./scripts/testmap.sh

tvect: fclean all
	@printf "\n\033[2K\r$(CYAN)################################$(RESET)\n"
	@printf "\033[2K\r$(CYAN)######### Test Vector ##########$(RESET)\n"
	@printf "\033[2K\r$(CYAN)################################$(RESET)\n\n"
	-./scripts/testvector.sh

tall: fclean all tvect tmap

.PHONY: all clean fclean re tall tvect tmap