CXX = c++

CXXFLAGS = -Wall -Werror -Wextra -std=c++98

HEADERS = include
INCLUDE = -I $(HEADERS)

NAME = ex02

SRC = 	src/main.cpp \
		
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