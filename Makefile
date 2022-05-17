NAME := containers
FT_NAME := ft_containers
HEADERFILES := 	vector.hpp\
				stack.hpp\
				map.hpp\
				set.hpp\
				Aordered.hpp\
				RBtree.hpp\
				Itree.hpp\
				node.hpp\
				utilities.hpp\
				Iterators/iterator.hpp\
				Iterators/iterator_traits.hpp\
				Iterators/reverse_iterator.hpp\
				Iterators/bidirectional_iterator.hpp
SRCS :=	main.cpp\
		tests/vector/stringVectorTests.cpp tests/vector/intVectorTests.cpp\
		tests/stack/intStackTests.cpp tests/stack/stringStackTests.cpp\
		tests/map/mapTests.cpp\
		tests/set/setTests.cpp\
		tests/speed/speed.cpp

FLAGS := -Wall -Wextra -Werror -std=c++98
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
	rm -f $(FT_OBJFILES)

fclean: clean
	rm -f $(NAME)
	rm -f $(FT_NAME)

re: fclean all

test: all
	./containers && ./ft_containers
	diff TestOutput/my_output TestOutput/std_output