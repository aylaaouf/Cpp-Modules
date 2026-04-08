CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp ScalarConverter.cpp
OBJS = $(SRCS:.cpp=.o)
NAME = ScalarConverter
all: $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $<

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

clean: 
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re