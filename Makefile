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
