NAME = libgnl.a

SRCS_DIR = src
OBJ_DIR = .obj
INC_DIR = inc

SRCS = $(SRCS_DIR)/get_next_line.c $(SRCS_DIR)/get_next_line_utils.c

TEST_DIR = test
TEST_SRC = $(TEST_DIR)/main.c $(TEST_DIR)/test_invalid.c $(TEST_DIR)/test_files.c $(TEST_DIR)/test_read.c $(TEST_DIR)/test_multi.c
TEST_BIN = gnl_test

OBJS = $(patsubst $(SRCS_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR)
AR = ar rcs

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@printf "  \033[33m⚙\033[0m  Compiling %d files...\n" $(words $(OBJS))
	@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJS)
	@printf "  \033[32m✓\033[0m Compiled %d files → $(NAME)\n" $(words $(OBJS))
	@$(AR) $(NAME) $(OBJS)

clean:
	@printf "  \033[31m✗\033[0m  Removing object files...\n"
	@rm -rf $(OBJ_DIR)

fclean: clean
	@printf "  \033[31m✗\033[0m  Removing $(NAME)...\n"
	@rm -f $(NAME)
	@printf "  \033[31m✗\033[0m  Removing test binary...\n"
	@rm -f $(TEST_BIN)

re: fclean all

test: all
	@printf "  \033[33m⚙\033[0m  Building test binary...\n"
	@$(CC) $(CFLAGS) -I $(TEST_DIR) $(TEST_SRC) $(NAME) -o $(TEST_BIN)
	@printf "  \033[32m✓\033[0m Test binary ready → $(TEST_BIN)\n"
	@printf "  \033[33m⚙\033[0m  Running tests...\n"
	@./$(TEST_BIN)

.PHONY: all clean fclean re test
