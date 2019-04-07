# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: osloboda <osloboda@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/04 14:11:49 by osloboda          #+#    #+#              #
#    Updated: 2019/04/07 17:35:22 by osloboda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_retro

INCDIR = includes/
 
SRC = main.cpp Enemy.cpp Rocket.cpp

SRCDIR = srcs

OBJDIR = objects

OBJ = $(addprefix $(OBJDIR)/, $(SRC:.cpp=.o))

FSRC = $(addprefix $(SRCDIR)/, $(SRC))

INCDIR = includes

FLAGS = -Wall -Werror -Wextra  -std=c++98

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	clang++ -lncurses $(OBJ) -o $(NAME)
	@echo \\033[32m======[Compiled]========\\033[0m
	
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(INCDIR)/*.hpp | $(OBJDIR)
	clang++ $(FLAGS) -o $@ -c $< -I $(INCDIR)

$(OBJDIR):
	@mkdir $(OBJDIR)

clean:
	@rm -Rf $(OBJDIR)
	@echo \\033[34m======[Cleaned]=========\\033[0m

fclean: clean
	@rm -f $(NAME)

re: fclean all
