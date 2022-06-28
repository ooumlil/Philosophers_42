NAME = philo

CFLAGS = -Wall -Wextra -Werror

SRC = main.c \
		parsing.c \
		thread_and_mutex_init.c \

OBJ = $(SRC:.c=.o)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ) philo.h
	@$(CC) $(CFLAGS) $(OBJ) -o $@

all : $(NAME)

clean :
	@rm -rf $(OBJ)

fclean : clean
	@rm -rf $(NAME)

re : fclean all
