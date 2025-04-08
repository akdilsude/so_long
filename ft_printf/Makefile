SRCS		=		ft_printf.c 		\
					ft_itoa.c			\
					ft_print_hex.c		\
					ft_print_pointer.c	\
					ft_putchar.c		\
					ft_putstr.c			\
					ft_strlen.c			\
					ft_uns_itoa.c		\

OBJS		=		$(SRCS:.c=.o)
CC			=		cc
RM			=		rm -f
CFLAGS		=		-Wall -Wextra -Werror
NAME		=		libftprintf.a
AR			=		ar rc

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -c $(SRCS)
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re