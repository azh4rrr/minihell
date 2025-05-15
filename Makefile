# Makefile for minishell project

NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = ./libft
LIBFT_A = $(LIBFT)/libft.a
SOURCES = main.c utils_a.c utils_b.c redirection.c parse_redir.c
OBJECTS = $(SOURCES:.c=.o)
INCLUDES = -I./

RL_LIB = -lreadline

all: $(NAME)
	@echo "\033[38;5;220m"
	@echo "888b     d888 d8b          d8b  .d8888b.  888               888 888"
	@echo "8888b   d8888 Y8P          Y8P d88P  Y88b 888               888 888"
	@echo "88888b.d88888                  Y88b.      888               888 888"
	@echo "888Y88888P888 888 88888b.  888  \"Y888b.   88888b.   .d88b.  888 888"
	@echo "888 Y888P 888 888 888 \"88b 888     \"Y88b. 888 \"88b d8P  Y8b 888 888"
	@echo "888  Y8P  888 888 888  888 888       \"888 888  888 88888888 888 888"
	@echo "888   \"   888 888 888  888 888 Y88b  d88P 888  888 Y8b.     888 888"
	@echo "888       888 888 888  888 888  \"Y8888P\"  888  888  \"Y8888  888 888"
	@echo "\033[0m"

$(NAME): $(LIBFT_A) $(OBJECTS)
	@echo "\033[38;5;208mLinking...\033[0m"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) $(RL_LIB) -L$(LIBFT) -lft

$(LIBFT_A):
	@echo "\033[38;5;208mBuilding libft...\033[0m"
	@make -C $(LIBFT) --no-print-directory

%.o: %.c minishell.h
	@echo "\033[38;5;208mCompiling $<...\033[0m"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@echo "\033[38;5;208mCleaning object files...\033[0m"
	@make -C $(LIBFT) clean --no-print-directory
	@rm -f $(OBJECTS)

fclean: clean
	@echo "\033[38;5;208mCleaning executable...\033[0m"
	@make -C $(LIBFT) fclean --no-print-directory
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re