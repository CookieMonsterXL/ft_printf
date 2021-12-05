NAME := libftprintf.a

HEADERFILES := ./libs/ft_printf.h ./libs/libft/libft.h
OBJFILES := obj/ft_printf.o
ARGFILES := ./libs/libft/libft.a
CFLAGS := -Wall -Wextra -Werror

all: libft $(NAME)

libft:
	make libs/libft
	cp $(ARGFILES) $(NAME)

$(NAME): $(OBJFILES)
	ar -rsc  $(NAME) $@

obj/%.o: %.c $(HEADERFILES)
	@mkdir -p $(dir $@)
	$(CC) -c $(CFLAGS) -o $@ $<



	ar -rsc  $(NAME) $@


#	$(CC) -C lib/libft


#	$(CC) -L./lib/libft.a -l ft

	#$(CC) -c name.o name.c -I./includefolder
    	#$(MAKE) -C $(LIBFT_DIR)
    	#$(CC) -L$(LIBFT_DIR) -lft -o exec_name src_file1 src_file2