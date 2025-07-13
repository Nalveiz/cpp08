NAME = mutantstack

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp

all: $(NAME)
$(NAME): $(SRC) MutantStack.hpp MutantStack.tpp
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME)
	@echo "\n"
	@echo "\033[32m             ___  ___         ___    _____     _      _      ___  ___ \033[0m"
	@echo "\033[32m ___  _ _   |   ||_  |   ___ |  _|  |   __|  _| |_  _| |_   |   || . |\033[0m"
	@echo "\033[32m| -_||_'_|  | | ||  _|  | . ||  _|  |  |__  |_   _||_   _|  | | || . |\033[0m"
	@echo "\033[32m|___||_,_|  |___||___|  |___||_|    |_____|   |_|    |_|    |___||___|\033[0m"
	@echo "\033[32m                                                                      \033[0m"
	@echo "\033[32m                                                                      \033[0m"
	@echo "\n"

clean:
	@echo "\033[34mNothing to clean in /ex02...\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[1m\033[4;32mAll files cleaned !\033[0m"

re: fclean all

.PHONY: all clean fclean re
