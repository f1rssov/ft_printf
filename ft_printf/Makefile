NAME		= libftprintf.a

SRCS		= func.c	ft_itoa.c	ft_printf.c		ft_uitoa.c

CC			= cc

CFLAGS		= -Wall -Werror -Wextra

RM			= rm -f

AR			= ar rcs

OBJ			= ${SRCS:%.c=%.o}

HEADER		= ft_printf.h

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
		$(AR) $(NAME) $?

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER)

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re:		fclean all

.PHONY: all clean fclean re