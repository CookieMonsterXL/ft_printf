NAME := libftprintf.a
#HEADERFILES := ./libs/ft_printf.h ./libs/libft/libft.h
OBJFILES := obj/ft_printf.o
LIBFT := ./libs/libft/libft.a
CFLAGS := -Wall -Wextra -Werror

all: libft $(NAME)

libft:
	make -C ./libs/libft

relibft:
	make re -C ./libs/libft

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
	make fclean -C ./libs/libft

re: relibft fclean all

.PHONY: clean all fclean re libft

#	$(CC) -C lib/libft


#	$(CC) -L./lib/libft.a -l ft

	#$(CC) -c name.o name.c -I./includefolder
    	#$(MAKE) -C $(LIBFT_DIR)
    	#$(CC) -L$(LIBFT_DIR) -lft -o exec_name src_file1 src_file2