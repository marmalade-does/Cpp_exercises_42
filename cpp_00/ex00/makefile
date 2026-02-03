
NAME = megaphone

SRCS = megaphone.cpp

FLAGS = -Wall -Wextra -Werror -std=c++98

all : $(NAME)

$(NAME) : $(SRCS)
	@g++ $(FLAGS) $(SRCS) -o $(NAME)

clean :
	@rm -f $(NAME)

fclean : clean


re : clean all 

.PHONY: all clean re $(NAME)
