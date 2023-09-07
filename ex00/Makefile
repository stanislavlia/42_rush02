NAME = rush-02
SRCS = srcs/main.c srcs/num_to_word.c srcs/parse_dict_to_struct.c srcs/read_dict.c srcs/utility_funcs.c srcs/validate_input.c
OBJS = $(SRCS:.c=.0)
INCS = includes
FLAGS = -Wall -Wextra -Werror

all:
	cc $(SRCS)$< $(FLAGS) -o $(NAME) -I $(INCS)

fclean:
	rm -f $(NAME)
