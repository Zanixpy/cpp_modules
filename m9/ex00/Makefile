CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

INCLUDES = -I srcs/class_bitcoin

NAME = btc

SRC = 	srcs/main.cpp \
	srcs/class_bitcoin/BitcoinExchange.cpp

OBJDIR = objs
OBJS = $(SRC:%.cpp=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re