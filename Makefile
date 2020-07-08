NAME = lem-in

SRC = main.c \
    init.c \
	parse.c valid_room.c valid_link.c rev.c utils.c \
	make_links.c \
	find_path.c bfs.c trail.c


S_DIR = src
O_DIR = obj
OBJ = $(addprefix $(O_DIR)/, $(SRC:.c=.o))
HEAD = lem.h struct.h
H_DIR = includes
LIBFT = libft/libft.a
GCC = gcc -Wall -Wextra -Werror
DEPS = $(patsubst %,$(H_DIR)/%,$(HEAD))

all: $(NAME)

$(NAME): $(OBJ) | $(LIBFT)
	@$(GCC) -o $@ $^ -I $(H_DIR) $(BONUS) $(LIBFT)
	@echo  "lem-in \033[1;32m[OK]\033[0m"

$(O_DIR)/%.o : $(S_DIR)/%.c $(DEPS)
	$(GCC) -o $@ -c $< -I $(H_DIR)

$(OBJ): | $(O_DIR)

clean:
	@make -C libft clean
	@rm -rf $(O_DIR)
	@echo "clean \033[1;32m[OK]\033[0m"

fclean:
	@make -C libft fclean
	@rm -rf $(O_DIR)
	@rm -rf $(NAME)
	@echo "fclean \033[1;32m[OK]\033[0m"

re: fclean all

$(LIBFT):
	@make -C libft

$(O_DIR):
	mkdir $(O_DIR)
