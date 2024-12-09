########################################################################################################################
#                                                      VARIABLES                                                       #
########################################################################################################################\

NAME_C 				= 	client
NAME_S				=	server
NAME				=	$(NAME_C) $(NAME_S)
NAME_BONUS_C		=	client_bonus
NAME_BONUS_S		=	server_bonus
NAME_BONUS			=	$(NAME_BONUS_C) $(NAME_BONUS_S)
HEADER				=	minitalk.h
CC 					= 	gcc
CFLAGS 				= 	-Wall -Wextra -Werror
AR					=	ar rcs
RM					=	rm -f

SRC_F_C				=	client
SRC_F_S				=	server
SRC_BONUS_F_C		=	client_bonus
SRC_BONUS_F_S		=	server_bonus

SRC_C				=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_F_C)))
OBJ_C 				= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_F_C)))
SRC_S				=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_F_S)))
OBJ_S 				= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_F_S)))
SRC_BONUS_C			=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_BONUS_F_C)))
OBJ_BONUS_C 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_BONUS_F_C)))
SRC_BONUS_S			=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_BONUS_F_S)))
OBJ_BONUS_S 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_BONUS_F_S)))

########################################################################################################################
#                                                      DIRECTORY                                                       #
########################################################################################################################

SRC_DIR				=
OBJ_DIR				=	obj/
INC_DIR				=	.

########################################################################################################################
#                                                         LIB                                                          #
########################################################################################################################

LIBFT_DIR			=	super_libft/
LIBFT				=	$(LIBFT_DIR)libft.a

########################################################################################################################
#                                                      TARGETS                                                         #
########################################################################################################################

all:					$(NAME) $(LIBFT)

bonus:					$(NAME_BONUS) $(LIBFT)

clean:
								@rm -rf $(OBJ_DIR)
								@$(MAKE) -C $(LIBFT_DIR) clean

fclean: 				clean
								@$(RM) $(NAME) $(NAME_BONUS)
								@$(MAKE) -C $(LIBFT_DIR) fclean

re: 					fclean all

.PHONY: 				all bonus clean fclean re

########################################################################################################################
#                                                       COMMANDS                                                       #
########################################################################################################################

$(NAME_C):				$(OBJ_C) $(LIBFT)
							@echo "$(YELLOW)[client]:$(DEF_COLOR)"
							@$(CC) $(CFLAGS) $(OBJ_C) $(LIBFT) -o $(NAME_C)
							@echo "$(GREEN)=> Success!$(DEF_COLOR)"

$(NAME_S):				$(OBJ_S) $(LIBFT)
							@echo "$(YELLOW)[server]:$(DEF_COLOR)"
							@$(CC) $(CFLAGS) $(OBJ_S) $(LIBFT) -o $(NAME_S)
							@echo "$(GREEN)=> Success!$(DEF_COLOR)"

$(NAME_BONUS_C):		$(OBJ_BONUS_C) $(LIBFT)
							@echo "$(YELLOW)[client_bonus]:$(DEF_COLOR)"
							@$(CC) $(CFLAGS) $(OBJ_BONUS_C) $(LIBFT) -o $(NAME_BONUS_C)
							@echo "$(GREEN)=> Success!$(DEF_COLOR)"

$(NAME_BONUS_S):		$(OBJ_BONUS_S) $(LIBFT)
							@echo "$(YELLOW)[server_bonus]:$(DEF_COLOR)"
							@$(CC) $(CFLAGS) $(OBJ_BONUS_S) $(LIBFT) -o $(NAME_BONUS_S)
							@echo "$(GREEN)=> Success!$(DEF_COLOR)"

$(LIBFT):
							@$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR)%.o: 			$(SRC_DIR)%.c $(HEADER)
							@mkdir -p $(OBJ_DIR)
							@$(CC) $(CFLAGS) -I$(INC_DIR) -I$(LIBFT_DIR)include/ -c $< -o $@

########################################################################################################################
#                                                      COLOURS                                                         #
########################################################################################################################

DEF_COLOR			=	\033[0;39m
ORANGE				=	\033[0;33m
GRAY				=	\033[0;90m
RED					=	\033[0;91m
GREEN				=	\033[1;92m
YELLOW				=	\033[1;93m
BLUE				=	\033[0;94m
MAGENTA				=	\033[0;95m
CYAN				=	\033[0;96m
WHITE				=	\033[0;97m
