# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbouma <tbouma@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/16 14:13:55 by tbouma            #+#    #+#              #
#    Updated: 2021/12/16 14:13:57 by tbouma           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a
OBJFILES := obj/ft_printf.o obj/print_flag.o
LIBFT := ./libft/libft.a
CFLAGS := -Wall -Wextra -Werror

all: libft $(NAME)

libft:
	make -C ./libft

relibft:
	make re -C ./libft

$(NAME): $(OBJFILES)
	cp $(LIBFT) $(NAME)
	ar -rsc  $(NAME) $(OBJFILES)

obj/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	rm -f $(OBJFILES)

fclean:	clean
	rm -f $(NAME)
	make fclean -C ./libft

re: relibft fclean all

.PHONY: clean all fclean re libft relibft
