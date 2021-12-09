NAME := libftprintf.a
OBJFILES := obj/ft_printf.o obj/print.o
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

.PHONY: clean all fclean re libft

#	$(CC) -C lib/libft


#	$(CC) -L./lib/libft.a -l ft

	#$(CC) -c name.o name.c -I./includefolder
    	#$(MAKE) -C $(LIBFT_DIR)
    	#$(CC) -L$(LIBFT_DIR) -lft -o exec_name src_file1 src_file2