NAME	:= libftprintf.a
CC		:= cc
CFLAGS	:= -Wall -Wextra -Werror -g3

SRCS	:= \
	srcs/main.c \
	srcs/helper_functions.c \
	srcs/write_functions.c
OBJS	:= $(SRCS:.c=.o)
INC		:= -I includes


all: $(NAME)

%.o: %.c $(INC)/header.h
	$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re