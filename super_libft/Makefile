########################################################################################################################
#                                                      VARIABLES                                                       #
########################################################################################################################

NAME 				= 	libft.a
CC 					= 	gcc
CFLAGS 				= 	-Wall -Wextra -Werror
AR					=	ar rcs
RM					=	rm -f
SRC_FILES			=	ft_atoi \
						ft_bzero \
						ft_calloc \
						ft_isalnum \
						ft_isalpha \
						ft_isascii \
						ft_isdigit \
						ft_isprint \
						ft_itoa \
						ft_lstadd_back \
						ft_lstadd_front \
						ft_lstclear \
						ft_lstdelone \
						ft_lstiter \
						ft_lstlast \
						ft_lstmap \
						ft_lstnew \
						ft_lstsize \
						ft_memchr \
						ft_memcmp \
						ft_memcpy \
						ft_memmove \
						ft_memset \
						ft_putchar_fd \
						ft_putendl_fd \
						ft_putnbr_fd \
						ft_putstr_fd \
						ft_split \
						ft_strchr \
						ft_strdup \
						ft_striteri \
						ft_strjoin \
						ft_strlcat \
						ft_strlcpy \
						ft_strlen \
						ft_strmapi \
						ft_strncmp \
						ft_strnstr \
						ft_strrchr \
						ft_strtrim \
						ft_substr \
						ft_tolower \
						ft_toupper \
						ft_printf \
						parsing \
						print_adress \
						print_char \
						print_hexa \
						print_int \
						get_next_line \
						get_next_line_utils

LIBFT_SRC 			=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 				= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

HEADERS				=	$(LIBFT_INC)libft.h

########################################################################################################################
#                                                      DIRECTORY                                                       #
########################################################################################################################

SRC_DIR				=	src/
OBJ_DIR				=	obj/
LIBFT_INC			=	include/

########################################################################################################################
#                                                       COMMANDS                                                       #
########################################################################################################################

all:					$(NAME)

$(NAME):				$(OBJ)
							$(AR) $@ $^

$(OBJ_DIR):
							@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: 			$(SRC_DIR)%.c $(HEADERS) | $(OBJ_DIR)
							$(CC) $(CFLAGS) -I$(LIBFT_INC) -c $< -o $@

########################################################################################################################
#                                                      TARGETS                                                         #
########################################################################################################################

clean:
								rm -rf $(OBJ_DIR)

fclean: 				clean
								$(RM) $(NAME)

re: 					fclean all

.PHONY: 				all bonus clean fclean re

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