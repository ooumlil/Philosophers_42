BONUS = philo_bonus

CFLAGS = -Wall -Wextra -Werror

SRC = parse_nd_assign.c \
		routine.c \
		routine_utils.c \
		main.c
 
OBJ = $(SRC:.c=.o)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(BONUS) : $(OBJ) philo_bonus.h
	@$(CC) $(CFLAGS) $(OBJ) -o $@

bonus : $(BONUS)

clean :
	@rm -rf $(OBJ)

fclean : clean
	@rm -rf $(BONUS)

re : fclean bonus
