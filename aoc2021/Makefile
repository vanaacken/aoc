NAME 		=	exec
CC			= 	clang++
FLAGS		=	-Wall -Wextra -Werror
PREFIX_S	=	cpp
PREFIX_O	=	o
RM			=	rm -f

SRC			=	test.cpp
SRCS_P		=	srcs
OBJ_P		=	objs
OBJS		=	$(addprefix $(OBJ_P)/, $(SRC:.cpp=.o))
INCLUDES	=	-I inc/settings.hpp
MESSAGE		= "run ./exec" 
C_MESSAGE	= "Building CPP objects... %-33.33s\r"
all: $(NAME)

$(NAME): $(OBJS)
	@echo "\n"
	@$(CC) $(FLAGS) $(OBJS) -o $(NAME) 
	@echo $(MESSAGE)

$(OBJ_P)/%.$(PREFIX_O): $(SRCS_P)/%.$(PREFIX_S)
	@mkdir -p $(dir $@)
	@printf $(C_MESSAGE) $@
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
	@rm -rf $(OBJ_P)
	@echo "Objects cleaned"

fclean: clean
	@$(RM) $(NAME)
	@echo "Executable cleaned"

run: all
	@./exec

re: fclean all
