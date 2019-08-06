# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ititkov <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/21 17:51:10 by ititkov           #+#    #+#              #
#    Updated: 2019/05/22 20:25:50 by ititkov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCLUDES = -I ./includes

SRCS = ./srcs/*

LIBFT = libft/libft.a
LIB_FILLER = lib_filler.a

OBJ = ./obj

EXE = ititkov.filler

RESET = \033[0m
RED = \033[0;31m
GREEN = \033[0;32m
BLUE = \033[0;36m
RED_EXTRA = \033[1;31m
GREEN_EXTRA = \033[1;32m
BLUE_EXTRA = \033[1;36m

all: $(EXE)

$(EXE):
	gcc -Wall -Wextra -Werror $(SRCS) $(INCLUDES) -c
	ar rc $(LIB_FILLER) *.o
	ranlib $(LIB_FILLER)
	if [ ! -d " ./obj" ]; then mkdir -p $(OBJ); fi
	mv *.o $(OBJ)
	make -C libft
	gcc -Wall -Wextra -Werror $(LIB_FILLER) $(LIBFT) $(INCLUDES) -o $(EXE)

clean:
	if [ ! -d " ./obj" ]; then \
	/bin/rm -rf $(OBJ); \
	fi
	#/bin/rm -rf $(OBJ)
	make -C libft clean

fclean: clean
	if [ ! -a "$(LIB_FILLER)" ]; then \
	/bin/rm -f $(LIB_FILLER); \
	fi
	
	if [ -a "$(EXE)" ]; then \
	echo "Deleting execetable $(RED_EXTRA)$(EXE)$(RESET)"; \
	/bin/rm -f $(EXE); \
	fi

	#bin/rm -f $(LIB_FILLER)
	#bin/rm -f $(EXE)

	make -C libft fclean
	@echo "$(BlUE_EXTRA)fclean$(BLUE); Complete$(RESSET)"

re: fclean all
