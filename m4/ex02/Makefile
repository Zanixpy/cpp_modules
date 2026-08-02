CXX = c++

CXXFLAGS = -g3 -Wall -Werror -Wextra -std=c++98 -Wshadow -Wno-shadow

HEADERS = include
INCLUDE = -I $(HEADERS)

NAME = abstract

SRC = 	src/main.cpp \
		src/AAnimal.cpp \
		src/Cat.cpp \
		src/Dog.cpp \
		src/Brain.cpp

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


