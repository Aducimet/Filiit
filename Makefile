# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: calin <calin@student.le-101.fr>            +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/11/13 16:45:37 by aducimet     #+#   ##    ##    #+#        #
#    Updated: 2018/12/05 16:28:40 by calin       ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = fillit

SRCS = 	srcs/parsing.c\
		srcs/struct_utils.c\
		srcs/coord.c\
		srcs/resolve.c\
		srcs/main.c\
		srcs/ft_utils.c\

FLAG = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

CC = gcc $(FLAG)

RM = /bin/rm -f

all: $(NAME)

$(NAME):
	@make -C libft/
	@$(CC) -o $(NAME) $(SRCS) libft/libft.a
	@echo "Make executable :\033[0;32m DONE !\033[0m"
	@echo "\033[1;32m ---------------------------------------------------------- \033[0m"
	@echo "\033[1;32m|     _______   __   __        __        __   __________   |\033[0m"
	@echo "\033[1;32m|    |  _____| |  | |  |      |  |      |  | |___    ___|  |\033[0m"
	@echo "\033[1;37m|    | |___    |  | |  |      |  |      |  |     |  |      |\033[0m"
	@echo "\033[1;37m|    |  ___|   |  | |  |      |  |      |  |     |  |      |\033[0m"
	@echo "\033[1;31m|    |  |      |  | |  |____  |  |____  |  |     |  |      |\033[0m"
	@echo "\033[1;31m|    |__|      |__| |_______| |_______| |__|     |__|      |\033[0m"
	@echo "\033[1;31m|                                                          |\033[0m"
	@echo "\033[1;31m ---------------------------------------------------------- \033[0m"


%.o: %.c
	@$(CC) -o $@ -c $< -I ./

clean:
	@make clean -C libft/
	@$(RM) $(OBJ)

fclean:
	@$(RM) $(NAME)
	@make fclean -C libft/
	@echo "Executable clean :\033[0;32m DONE !\033[0m"

re:	fclean all

.PHONY: all clean fclean re
