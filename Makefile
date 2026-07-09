# Compiler
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

# Directories
SRC_DIR = src
INC_DIR = includes
LIBFT_DIR = libft
# BUILTINS_DIR = $(SRC_DIR)/built_ins
OBJ_DIR = obj

# Executable
NAME = cub3D

# Sources
SRCS = $(SRC_DIR)/cub3D.c \
		$(SRC_DIR)/parsing/parsing.c $(SRC_DIR)/parsing/check_data.c $(SRC_DIR)/parsing/parsing_utils.c $(SRC_DIR)/parsing/error.c \

# Object files in obj/ folder
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

# Libraries
LIBFT = $(LIBFT_DIR)/libft.a

# Include flags
INC_FLAGS = -I$(INC_DIR) -I$(LIBFT_DIR) -Irea

# Rules
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

# Compile objects, creating subdirectories if needed
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INC_FLAGS) -c $< -o $@

$(LIBFT):
	# $(MAKE) -C $(LIBFT_DIR)

clean:
	# $(MAKE) -C $(LIBFT_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	# $(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

valgrind:
	clear && valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes ./cub3D maps/map.cub

.PHONY: all clean fclean re valgrind
