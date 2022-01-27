# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpereira <cpereira@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/27 00:08:05 by cpereira          #+#    #+#              #
#    Updated: 2022/01/27 18:31:46 by cpereira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = DiamondTrap.out

ODIR =	./objs/

SRCS =	src/main.cpp \
		src/ClapTrap.cpp \
		src/ScavTrap.cpp \
		src/FragTrap.cpp \
		src/DiamondTrap.cpp

OBJS =	$(patsubst %.c, $(ODIR)%.o, $(SRCS))

CC = c++
C_FLAGS = -Wall -Werror -Wextra -std=c++98 -Wshadow


$(NAME): $(OBJS)
		@$(CC) $(OBJS) $(C_FLAGS) -g -o $@
		@echo "\033[1;34mDone\033[0;37m"

$(ODIR)%.o: $(SDIR)%.c
		@mkdir -p $(ODIR)
		@$(CC) $(C_FLAGS) -c $< -o $@


all: karen

clean:
	@rm -rf $(ODIR)

fclean: clean
	@rm -f $(NAME)
	@echo "\033[1;33mCleaned\033[0;37m"

re: fclean all
