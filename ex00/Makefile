# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nlewicki <nlewicki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/26 10:27:15 by nlewicki          #+#    #+#              #
#    Updated: 2025/02/26 10:43:16 by nlewicki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= Bureaucrat
CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98

SRCS	= Bureaucrat.cpp main.cpp
OBJS	= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
