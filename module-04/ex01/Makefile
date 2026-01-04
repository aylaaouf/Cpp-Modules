CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp Animal.cpp Dog.cpp Cat.cpp Brain.cpp
OBJS = $(SRCS:.cpp=.o)
NAME = Animal
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