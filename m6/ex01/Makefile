CXX = c++

CXXFLAGS = -Wall -Werror -Wextra -std=c++98

HEADERS = include
INCLUDE = -I $(HEADERS)

NAME = ex01

SRC = 	src/main.cpp \
		src/Serializer.cpp \
		
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