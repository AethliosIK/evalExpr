# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tchambar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/17 17:50:16 by tchambar          #+#    #+#              #
#    Updated: 2017/08/20 20:26:10 by tchambar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm
EXEC = eval_expr
OBJECTS = main.o eval_expr.o binary_tree.o operand.o util.o ft_split_whitespaces.o

all: $(EXEC)

$(EXEC): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(EXEC)

clean:
	$(RM) -f $(OBJECTS)

fclean: clean
	$(RM) -f $(EXEC)

re: fclean all

main.o: main.c eval_expr.h util.h ft_split_whitespaces.h

eval_expr.o: eval_expr.c eval_expr.h binary_tree.h operand.h util.h

binary_tree.o: binary_tree.c binary_tree.h operand.h

operand.o: operand.c operand.h

util.o: util.c util.h ft_split_whitespaces.h 

ft_split_whitespaces.o: ft_split_whitespaces.c ft_split_whitespaces.h
