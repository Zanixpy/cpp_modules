CXX = c++

CXXFLAGS = -g3 -Wall -Wextra -Werror -Wshadow -Wno-shadow

SRC =	src/main.cpp		\
		src/Cure.cpp		\
		src/Ice.cpp			\
		src/Character.cpp	\
		src/AMateria.cpp	\
		src/MateriaSource.cpp

OBJS = $(SRC:.cpp=.o)

HEADERS = include
INCLUDES = -I $(HEADERS)

NAME = interface

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY : all clean fclean re

