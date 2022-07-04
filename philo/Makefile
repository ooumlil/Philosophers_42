NAME = philo

CFLAGS = -Wall -Wextra -Werror

SRC = main.c \
		parsing.c \
		assign_nd_init.c \
		routine.c \
		routine_utils.c
 
OBJ = $(SRC:.c=.o)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ) philo.h
	@$(CC) $(CFLAGS) $(OBJ) -lpthread -o $@

all : $(NAME)

clean :
	@rm -rf $(OBJ)

fclean : clean
	@rm -rf $(NAME)

re : fclean all
