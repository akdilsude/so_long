SRCS			=	coordinats.c	\
					frees.c			\
					ft_split.c		\
					ft_substr.c		\
					game.c			\
					images.c		\
					main.c			\
					map_control.c	\
					map_read.c		\

OBJS			=	$(SRCS:.c=.o)
RM				=	rm -f
CFLAGS			=	-Wall -Wextra -Werror
CC 				=	cc
MINILIBX_DIR	=	minilibx-linux
MINILIBX 		=	$(MINILIBX_DIR)/libmlx.a
LFLAGS 			=	-L$(MINILIBX_DIR) -lmlx -L/lib/x86_64-linux-gnu -lXext -lX11 -lm -lbsd
FT_PRINTF_DIR = ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a
NAME			=	so_long

all: $(NAME)

$(FT_PRINTF):
	@make -C $(FT_PRINTF_DIR)

$(MINILIBX):
	@make -C $(MINILIBX_DIR)

$(NAME): $(OBJS) $(FT_PRINTF) $(MINILIBX)
	$(CC) $(CFLAGS) $(OBJS) $(FT_PRINTF) $(MINILIBX) $(LFLAGS) -o $(NAME)

clean:
	$(RM) $(OBJS)
	@make -C $(FT_PRINTF_DIR) clean

fclean: clean
	$(RM) $(NAME)
	@make -C $(FT_PRINTF_DIR) fclean
	@make -C $(MINILIBX_DIR) clean

re: fclean all

.PHONY: all clean fclean re