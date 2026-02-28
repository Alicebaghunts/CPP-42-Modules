NAME = phonebook

CPP = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

HEADER = Contact.hpp \
			PhoneBook.hpp

SRC  = PhoneBook.cpp \
		Contact.cpp \
		main.cpp

OBJ  = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp $(HEADER)
	$(CPP) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re