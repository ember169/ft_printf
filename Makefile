NAME	:= libftprintf.a
CC		:= cc
CFLAGS	:= -Wall -Wextra -Werror -g3
AR		:= ar rcs
RM		:= rm -f
INCS	:= includes

SRCS	:= \
	srcs/ft_printf.c \
	srcs/core/dispatch.c \
	srcs/utils/write_basics.c \
	srcs/utils/strings.c \
	srcs/utils/numbers.c

OBJS	:= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c $(INCS)/ft_printf.h
	$(CC) $(CFLAGS) -I$(INCS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
