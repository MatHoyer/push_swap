CC = cc

CFLAGS = -Wall -Wextra -Werror -I. -MMD -g3

SRC_PATH = sources/

OBJS_PATH = obj/

SRC = check_tri.c \
	fonctions_sort.c \
	ft_a.c \
	ft_b.c \
	ft_free.c \
	init.c \
	main.c \
	mini_sort_inv.c \
	mini_sort.c \
	parsing.c \
	push.c \
	rotate.c \
	sort.c \
	swap.c \

OBJS = $(SRC:.c=.o)

DEP = $(SRC:.c=.d)

PREFC = $(addprefix $(SRC_PATH),$(SRC))

PREFO = $(addprefix $(OBJS_PATH),$(OBJS))

PREFD = $(addprefix $(OBJS_PATH),$(DEP))

OBJ_DIR = obj

NAME = push_swap

all : $(NAME)

$(NAME) : $(PREFO)
	@make -s -C libft all
	@echo "Compilation de push_swap en cours..."
	@$(CC) $(PREFO) ./libft/libft.a -o $(NAME)
	@echo "Terminé!"

bonus : all

$(OBJ_DIR) :
	@mkdir -p $(OBJ_DIR)

$(OBJS_PATH)%.o: $(SRC_PATH)%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@rm -rf $(OBJ_DIR)
	@make -s -C libft clean

fclean :
	@rm -f $(NAME)
	@rm -f $(PREFO) $(PREFD)
	@make -s -C libft fclean

re : fclean all

-include $(PREFD)

.PHONY : all clean fclean re