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
	@cd include/libft && make && cd ../..
%.o: %.c
	@$(CC) $(FLAGS) $(INCLUDE_PATH) -O3 -c $< -o $@
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIB_PATH) $(LIB_NAME) $(INCLUDE_PATH) -o $(NAME)
clean:
	rm -rf *.o ./$(OBJDIR)/*.o include/libft/*.o src/*.o
	rm -rf *.d ./$(OBJDIR)/*.d include/libft/*.d src/*.d

fclean: clean
	rm -rf $(NAME) libft/libft.a
re : fclean all

listC:
	@find -wholename "./src/*.c" | cut -c 3- | tr '\n' ' '