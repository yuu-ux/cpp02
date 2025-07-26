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

linter:
	clang-tidy *cpp --extra-arg="-isysroot" --extra-arg="$(xcrun --show-sdk-path)" -- -I. -std=c++98

re: fclean all

.PHONY: all clean re fclean format
