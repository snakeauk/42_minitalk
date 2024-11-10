NAME		=	minitalk
SERVER_NAME	=	server
CLIENT_NAME	=	client

# commands
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -rf
MAKE		=	make

# libft
LIBFT		=	libft
LIBFT_A		=	$(LIBFT).a
LIBFT_DIR	=	./$(LIBFT)

# srcs
SRCS_DIR	=	./srcs

CLIENT_SRCS	=	$(SRCS_DIR)/client.c
SERVER_SRCS	=	$(SRCS_DIR)/server.c

# object
CLIENT_OBJS	=	$(CLIENT_SRCS:.c=.o)
SERVER_OBJS	=	$(SERVER_SRCS:.c=.o)

# OS differences
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Darwin)
	OS_DIR		=	$(LIBFT_DIR)/mac
else
	OS_DIR		=	$(LIBFT_DIR)/linux
endif

# includes
INCLUDES	=	-I ./includes -I $(LIBFT_DIR)/includes -I $(OS_DIR)/includes

# font color
RESET		=	\033[0m
BOLD		=	\033[1m
DIM			=	\033[2m
UNDERLINE	=	\033[4m
BLINK		=	\033[5m
INVERT		=	\033[7m
LIGHT_BLUE	=	\033[94m
YELLOW		=	\033[93m

# extra rule
MAKEFLAGS	+=	--no-print-directory

# rule
all: $(LIBFT_A) $(CLIENT_NAME) $(SERVER_NAME)

$(CLIENT_NAME): $(LIBFT) $(CLIENT_OBJS)
	@echo "$(BOLD)$(LIGHT_BLUE)Compile $(CLIENT_NAME)...$(RESET)"
	@$(CC) $(CFLAG) $(INCLUDES) $(CLIENT_OBJS) $(LIBFT_DIR)/$(LIBFT_A) -o $(CLIENT_NAME)
	@echo "$(BOLD)$(LIGHT_BLUE)Compile $(CLIENT_NAME) Complete!$(RESET)"

$(SERVER_NAME): $(LIBFT) $(SERVER_OBJS)
	@echo "$(BOLD)$(LIGHT_BLUE)Compile $(SERVER_NAME)...$(RESET)"
	@$(CC) $(CFLAG) $(INCLUDES) $(SERVER_OBJS) $(LIBFT_DIR)/$(LIBFT_A) -o $(SERVER_NAME)
	@echo "$(BOLD)$(LIGHT_BLUE)Compile $(SERVER_NAME) Complete!$(RESET)"

$(LIBFT_A):
	@$(MAKE) -C $(LIBFT_DIR)

.c.o:
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@echo "$(BOLD)$(LIGHT_BLUE)Cleaning $(NAME)...$(RESET)"
	@$(MAKE) clean -C $(LIBFT_DIR)
	@$(RM) $(CLIENT_OBJS) $(SERVER_OBJS)
	@echo "$(BOLD)$(LIGHT_BLUE)Cleaning $(NAME) Complete!$(RESET)"

fclean:
	@echo "$(BOLD)$(LIGHT_BLUE)ALL Cleaning $(NAME)...$(RESET)"
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@$(RM) $(CLIENT_OBJS) $(SERVER_OBJS) $(CLIENT_NAME) $(SERVER_NAME)
	@echo "$(BOLD)$(LIGHT_BLUE)ALL Cleaning $(NAME) Complete!$(RESET)"

bonus: all

re: fclean all

.PHONY: all clean fclean re bonus