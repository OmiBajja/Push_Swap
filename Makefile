OBJDIR = obj
SRCDIR = src
CC = cc
FLAGS = -Wall -Wextra -Werror -g3
NAME = push_swap
SRCS = src/push_swap.c src/push_swap_utils.c src/push_swap_algo.c src/push_swap_sorts.c src/push_swap_algo_bis.c src/push_swap_algo_ter.c src/push_swap_sorter.c src/push_swap_calc.c src/push_swap_calc_bis.c src/push_swap_sorting_bis.c src/push_swap_sorting_extra.c src/push_swap_bs.c
OBJ = $(SRCS:.c=.o)
OBJ := $(patsubst $(SRCDIR)/%, $(OBJDIR)/%, $(OBJ))
LIB_PATH = -L./include/libft
LIB_NAME = -lft
INCLUDE_PATH = -I./include/libft -I./include
CFLAGS = $(FLAGS) $(INCLUDE_PATH)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	@mkdir -p $(dir $@)
	$(V)$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

all: LIBFT $(NAME)

LIBFT:
	@cd include/libft && $(MAKE) all && cd ../..

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIB_PATH) $(LIB_NAME) -o $(NAME)

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR)
	@cd include/libft && $(MAKE) clean && cd ../..

fclean: clean
	rm -rf $(NAME) include/libft/libft.a
	@cd include/libft && $(MAKE) fclean && cd ../..

re: fclean all

.PHONY: all clean fclean re LIBFT