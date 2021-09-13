# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpereira <cpereira@student.42sp.org>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/27 00:08:05 by cpereira          #+#    #+#              #
#    Updated: 2021/09/09 00:48:45 by cpereira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phone_book

ODIR =	./objs/

SRCS =	main.cpp \
		ClassContact.cpp \
		ClassBook.cpp

OBJS =	$(patsubst %.c, $(ODIR)%.o, $(SRCS))

CC = clang++
C_FLAGS = -Wall -Werror -Wextra


$(NAME): $(OBJS)
		@$(CC) $(OBJS) $(C_FLAGS) -g -o $@
		@echo "\033[1;34mDone\033[0;37m"

$(ODIR)%.o: $(SDIR)%.c
		@mkdir -p $(ODIR)
		@$(CC) $(C_FLAGS) -c $< -o $@


all: phone_book

clean:
	@rm -rf $(ODIR)

fclean: clean
	@rm -f $(NAME)
	@echo "\033[1;33mCleaned\033[0;37m"

re: fclean all
