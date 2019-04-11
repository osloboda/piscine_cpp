# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: osloboda <osloboda@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/26 15:05:19 by osloboda          #+#    #+#              #
#    Updated: 2019/04/11 18:22:16 by osloboda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = convert

SRC = main.cpp cast.cpp

OBJDIR = objects

OBJ = $(addprefix $(OBJDIR)/, $(SRC:.cpp=.o))

FLAGS = -Wall -Werror -Wextra

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	clang++ $(FLAGS) $(OBJ) -o $(NAME)
	@echo \\033[32m======[Compiled]========\\033[0m
	
$(OBJDIR)/%.o: ./%.cpp ./*.hpp | $(OBJDIR)
	clang++ $(FLAGS) -o $@ -c $< -I .

$(OBJDIR):
	@mkdir $(OBJDIR)

clean:
	@rm -Rf $(OBJDIR)
	@echo \\033[34m======[Cleaned]=========\\033[0m

fclean: clean
	@rm -f $(NAME)

re: fclean all
