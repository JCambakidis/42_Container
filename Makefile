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

NAME			=	container

INCS			=	./srcs/Vector/Vector.hpp ./tests/vector/test_vector.hpp

SRCS			=	./main.cpp 


COMPILED_DIR	=	./compiled_sources
OBJS			=	$(SRCS:.cpp=.o)

CC				=	clang++
FLAGS			=	-Wall -Wextra -Werror -std=c++98 -g #3 -fsanitize=address

all: $(NAME)

$(COMPILED_DIR):
	mkdir -p $(COMPILED_DIR)

%.o:%.cpp
	$(CC) $(FLAGS) -o $@ -c $<

$(NAME): $(COMPILED_DIR) $(INCS) $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re