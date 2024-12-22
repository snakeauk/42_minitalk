NAME		=	minitalk
SERVER_NAME	=	server
CLIENT_NAME	=	client

# commands
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -rf

# libft
LIBFT		=	libft
LIBFT_DIR	=	./$(LIBFT)
LIBFT_A     =	$(LIBFT_DIR)/$(LIBFT).a

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
LIGHT_BLUE	=	\033[94m
YELLOW		=	\033[93m

# extra rule
TOTAL_FILES := $(words $(CLIENT_OBJS) $(SERVER_OBJS))
CURRENT_FILE := 0

define progress
	@CURRENT_PERCENT=$$(expr $(CURRENT_FILE) \* 100 / $(TOTAL_FILES)); \
	printf "$(YELLOW)Progress: %3d%% (%d/%d)$(RESET)\r" $$CURRENT_PERCENT $(CURRENT_FILE) $(TOTAL_FILES); \
	$(eval CURRENT_FILE=$$(($(CURRENT_FILE)+1)))
endef

# rule
all: $(LIBFT_A) $(CLIENT_NAME) $(SERVER_NAME)

$(CLIENT_NAME): $(CLIENT_OBJS) $(LIBFT_A)
	@echo "$(BOLD)$(LIGHT_BLUE)Compiling $(CLIENT_NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) $(CLIENT_OBJS) $(LIBFT_A) -o $(CLIENT_NAME)
	@echo "$(BOLD)$(LIGHT_BLUE)$(CLIENT_NAME) created successfully!$(RESET)"

$(SERVER_NAME): $(SERVER_OBJS) $(LIBFT_A)
	@echo "$(BOLD)$(LIGHT_BLUE)Compiling $(SERVER_NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) $(SERVER_OBJS) $(LIBFT_A) -o $(SERVER_NAME)
	@echo "$(BOLD)$(LIGHT_BLUE)$(SERVER_NAME) created successfully!$(RESET)"

$(LIBFT_A):
	@echo "$(BOLD)$(LIGHT_BLUE)Compiling $(LIBFT)...$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	@$(eval CURRENT_FILE=$(shell expr $(CURRENT_FILE) + 1))
	@CURRENT_PERCENT=$$(expr $(CURRENT_FILE) \* 100 / $(TOTAL_FILES)); \
	printf "$(YELLOW)Progress: %3d%% (%d/%d)$(RESET)\r" $$CURRENT_PERCENT $(CURRENT_FILE) $(TOTAL_FILES); \
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@echo "$(BOLD)$(LIGHT_BLUE)Cleaning objects...$(RESET)"
	@$(MAKE) clean -C $(LIBFT_DIR)
	@$(RM) $(CLIENT_OBJS) $(SERVER_OBJS)
	@echo "$(BOLD)$(LIGHT_BLUE)Objects cleaned!$(RESET)"

fclean:
	@echo "$(BOLD)$(LIGHT_BLUE)Full clean...$(RESET)"
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@$(RM) $(CLIENT_OBJS) $(SERVER_OBJS) $(CLIENT_NAME) $(SERVER_NAME)
	@echo "$(BOLD)$(LIGHT_BLUE)Full clean complete!$(RESET)"

bonus: all

re: fclean all

.PHONY: all clean fclean re bonus
