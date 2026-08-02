CXX = c++

CXXFLAGS = -g3 -Wall -Werror -Wextra -std=c++98

NAME = harl

SRCS =  src/main.cpp \
		src/Harl.cpp \

OBJS = $(SRCS:.cpp=.o)

HEADERS = include
INCLUDES = -I $(HEADERS)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	-rm -rf $(OBJS)

fclean: clean
	-rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re