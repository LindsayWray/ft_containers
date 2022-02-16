NAME := containers
FT_NAME := ft_containers
HEADERFILES := vector.hpp # map.hpp stack.hpp
SRCS :=	main.cpp stringTests.cpp intTests.cpp

FLAGS := -Wall -Wextra -Werror -std=c++98 -pedantic
OBJFILES := $(SRCS:%.cpp=obj/%.o)
FT_OBJFILES := $(SRCS:%.cpp=ft_obj/%.o)

all: $(NAME) $(FT_NAME)

$(NAME): $(OBJFILES) 
	c++ -o $@ $^
$(FT_NAME): $(FT_OBJFILES) 
	c++ -o $@ $^

obj/%.o: %.cpp $(HEADERFILES)
	@mkdir -p $(dir $@)
	c++ -c $(FLAGS) -o $@ $< -D STD_CONTAINER=1

ft_obj/%.o: %.cpp $(HEADERFILES)
	@mkdir -p $(dir $@)
	c++ -c $(FLAGS) -o $@ $< -D STD_CONTAINER=0

clean:
	rm -f $(OBJFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

test: all
	diff myVectorOutput realVectorOutput