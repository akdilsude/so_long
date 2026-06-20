NAME			=	so_long

CC 				=	cc
CFLAGS			=	-Wall -Wextra -Werror
INCLUDES		=	-I./inc -I./ft_printf -I./minilibx-linux
RM				=	rm -f

SRCS_DIR		=	srcs
LOGIC_DIR		=	$(SRCS_DIR)/logic
MAP_DIR			=	$(SRCS_DIR)/map
GFX_DIR			=	$(SRCS_DIR)/graphics
UTILS_DIR		=	$(SRCS_DIR)/utils

LOGIC_SRCS		=	$(LOGIC_DIR)/main.c $(LOGIC_DIR)/game.c $(LOGIC_DIR)/game_close.c
MAP_SRCS		=	$(MAP_DIR)/map_read.c $(MAP_DIR)/map_control.c $(MAP_DIR)/coordinats.c
GFX_SRCS		=	$(GFX_DIR)/images.c
UTILS_SRCS		=	$(UTILS_DIR)/frees.c $(UTILS_DIR)/ft_split.c $(UTILS_DIR)/ft_substr.c

SRCS			=	$(LOGIC_SRCS) $(MAP_SRCS) $(GFX_SRCS) $(UTILS_SRCS)
OBJS			=	$(SRCS:.c=.o)

MINILIBX_DIR	=	minilibx-linux
MINILIBX		=	$(MINILIBX_DIR)/libmlx.a
MLX_FLAGS		=	-L$(MINILIBX_DIR) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm

FT_PRINTF_DIR	=	ft_printf
FT_PRINTF		=	$(FT_PRINTF_DIR)/libftprintf.a

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(FT_PRINTF):
	@make -C $(FT_PRINTF_DIR)

$(MINILIBX):
	@make -C $(MINILIBX_DIR)

$(NAME): $(OBJS) $(FT_PRINTF) $(MINILIBX)
	$(CC) $(CFLAGS) $(OBJS) $(FT_PRINTF) $(MINILIBX) $(MLX_FLAGS) -o $(NAME)

clean:
	$(RM) $(OBJS)
	@make -C $(FT_PRINTF_DIR) clean

fclean: clean
	$(RM) $(NAME)
	@make -C $(FT_PRINTF_DIR) fclean
	@make -C $(MINILIBX_DIR) clean

re: fclean all

.PHONY: all clean fclean re