CC = cc

CFLAGS = -Wall -Werror -Wextra -I. -MMD

SRC = push_swap.c \
	init.c \
	swaps.c \
	push.c \
	rotates.c \
	error.c \
	fonctions.c

OBJS = $(SRC:.c=.o)

DEP = $(SRC:.c=.d)

LIB = libpush_swap.a

NAME = push_swap

all : $(NAME)

$(NAME) : $(OBJS)
	@make -s -C libft all 
	@cp libft/libft.a .
	@mv libft.a $(LIB)
	@ar rcs $(LIB) $(OBJS)
	@echo "creation de l'executable"
	@$(CC) $(CFLAGS) -o $(NAME) main.c -L. -lpush_swap
	@echo "Terminé!"

bonus : all

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@rm -f $(OBJS) $(DEP)
	@make -s -C libft clean

fclean : clean
	@rm -f $(NAME) $(LIB)
	@make -s -C libft fclean

re : fclean all

-include $(DEP)

.PHONY : all clean fclean re