# Compiler
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

# Directories
SRC_DIR = src
INC_DIR = includes
LIBFT_DIR = libft
LIBMLX = MLX42

# Libs
LIBS = $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

# BUILTINS_DIR = $(SRC_DIR)/built_ins
OBJ_DIR = obj

# Executable
NAME = cub3D

# Sources
SRCS = $(SRC_DIR)/cub3D.c \
		$(SRC_DIR)/parsing/parsing.c $(SRC_DIR)/parsing/check_data.c $(SRC_DIR)/parsing/data_utils.c $(SRC_DIR)/parsing/error.c \
		$(SRC_DIR)/parsing/create_map.c $(SRC_DIR)/parsing/clear_map.c $(SRC_DIR)/parsing/check_map.c

# Object files in obj/ folder
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

# Libraries
LIBFT = $(LIBFT_DIR)/libft.a

# Include flags
INC_FLAGS = -I$(INC_DIR) -I$(LIBFT_DIR) -I$(LIBMLX)/include -Irea

# Rules
all: libmlx $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

# Compile objects, creating subdirectories if needed
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INC_FLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

libmlx:
	cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -rf $(OBJ_DIR)
	rm -rf $(LIBMLX)/build

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

valgrind:
	clear && valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes ./cub3D maps/map2.cub

.PHONY: all clean fclean re valgrind libmlx
