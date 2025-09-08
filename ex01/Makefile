NAME = phonebook

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

INCLUDES = Contact.hpp \
			PhoneBook.hpp

SRCS = Contact.cpp \
		PhoneBook.cpp \
		main.cpp \

OBJ = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 