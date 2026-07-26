CXX = c++

CXXFLAGS = -g3 -Wall -Werror -Wextra -std=c++98

NAME = phonebook

SRCS =  src/main.cpp \
		src/PhoneBook.cpp \
		src/Contact.cpp

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