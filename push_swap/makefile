CC = cc
FLAGS = -Wall -Wextra -Werror -g3
NAME = a.out
SRCS = src/push_swap.c src/push_swap_utils.c src/push_swap_algo.c src/push_swap_sorts.c src/push_swap_algo_bis.c src/push_swap_algo_ter.c src/push_swap_sorter.c
OBJ = $(SRCS:.c=.o)
LIB_PATH = -L./include/libft
LIB_NAME = -lft
INCLUDE_PATH = -I./include/libft -I./include

all: LIBFT $(NAME)

LIBFT:
	@cd include/libft && make && cd ../..
%.o: %.c
	@$(CC) $(FLAGS) $(INCLUDE_PATH) -O3 -c $< -o $@
$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) $(LIB_PATH) $(LIB_NAME) $(INCLUDE_PATH) -o $(NAME)
clean:
	rm -rf *.o ./sources/*.o include/libft/*.o src/*.o
fclean: clean
	rm -rf $(NAME) libft/libft.a
re : fclean all

listC:
	@find -wholename "./src/*.c" | cut -c 3- | tr '\n' ' '