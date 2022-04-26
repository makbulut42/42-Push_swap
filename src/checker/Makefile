_END		=	\e[0m
_BOLD		=	\e[1m
_UNDER		=	\e[4m
_REV		=	\e[7m
_GREY		=	\e[30m
_RED		=	\e[31m
_GREEN		=	\e[32m
_YELLOW		=	\e[33m
_BLUE		=	\e[34m
_PURPLE		=	\e[35m
_CYAN		=	\e[36m
_WHITE		=	\e[37m
_IGREY		=	\e[40m
_IRED		=	\e[41m
_IGREEN		=	\e[42m
_IYELLOW	=	\e[43m
_IBLUE		=	\e[44m
_IPURPLE	=	\e[45m
_ICYAN		=	\e[46m
_IWHITE		=	\e[47m

NORMINETTE	:=	$(shell which norminette)

ifeq (, $(shell which norminette))
	NORMINETTE	:= ${HOME}/.norminette/norminette.rb
endif

CC			=	gcc

CC_FLAGS	=	-Wall -Wextra -Werror

RM			=	rm -rf

DIR_HEADERS =	./includes/

DIR_SRCS	=	./srcs/

DIR_OBJS	=	./compiled_srcs/

SRC			=	checker.c \
				init_stacks.c \
				operations.c \
				instructions.c \
				utils.c \
				print.c \
				debug.c \
				zero.c

SRCS		=	$(SRC)

OBJS 		=	$(SRCS:%.c=$(DIR_OBJS)%.o)

NAME 		=	checker

all:			$(NAME)

$(NAME):		$(OBJS)
				@printf "\033[2K\r$(_GREEN) All files compiled into '$(DIR_OBJS)'. $(_END)✅\n"
				@$(CC) $(CC_FLAGS) -I $(DIR_HEADERS) $(OBJS) -o $(NAME)
				@printf "\033[2K\r$(_GREEN) Executable '$(NAME)' created. $(_END)✅\n"

$(OBJS):		| $(DIR_OBJS)


$(DIR_OBJS)%.o: $(DIR_SRCS)%.c
				@printf "\033[2K\r $(_YELLOW)Compiling $< $(_END)⌛ "
				@$(CC) $(CC_FLAGS) -I $(DIR_HEADERS) -c $< -o $@

$(DIR_OBJS):
				@mkdir $(DIR_OBJS)

clean:
				@$(RM) $(DIR_OBJS)
				@printf "\033[2K\r$(_RED) '"$(DIR_OBJS)"' has been deleted. $(_END)🗑️\n"

fclean:			clean
				@$(RM) $(NAME)
				@printf "\033[2K\r$(_RED) '"$(NAME)"' has been deleted. $(_END)🗑️\n"

re:				fclean all

norm:
				@$(NORMINETTE) $(DIR_SRCS)
				@$(NORMINETTE) $(DIR_HEADERS)

.PHONY:			all clean fclean re norm
