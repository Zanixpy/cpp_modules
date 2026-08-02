CXX = c++

CXXFLAGS = -g3 -Wall -Werror -Wextra -std=c++98 -Wshadow -Wno-shadow

HEADERS = include
INCLUDE = -I $(HEADERS)

NAME = polymorphism

SRC = 	src/main.cpp \
		src/Animal.cpp \
		src/Cat.cpp \
		src/Dog.cpp 

OBJS = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

clean:
	-rm -rf $(OBJS)

fclean: clean
	-rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re


