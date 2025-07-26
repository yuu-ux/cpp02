NAME = Fixed
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic-errors
SRC = main.cpp Fixed.cpp

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	$(RM) *.o

fclean: clean
	$(RM) $(NAME)

format:
	clang-format -i *.h *.cpp

re: fclean all

.PHONY: all clean re fclean format
