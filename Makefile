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

SRCS		=	./src

DIR			=	./

RM			=	rm -rf

CHECKER		=	checker

PUSH_SWAP	=	push_swap

all:			$(CHECKER) $(PUSH_SWAP)

$(CHECKER):		
				@printf	"\033[2K\r$(_BLUE)$(_BOLD)$(CHECKER) $(_END)\n"
				@$(MAKE) -C $(SRCS)/$(CHECKER)
				@cp -rf $(SRCS)/$(CHECKER)/$(CHECKER) $(DIR)/$(CHECKER)

$(PUSH_SWAP):	
				@printf	"\033[2K\r$(_BLUE)$(_BOLD)$(PUSH_SWAP) $(_END)\n"
				@$(MAKE) -C $(SRCS)/$(PUSH_SWAP)
				@cp -rf $(SRCS)/$(PUSH_SWAP)/$(PUSH_SWAP) ./$(PUSH_SWAP)

clean:
				@printf	"\033[2K\r$(_BLUE)$(_BOLD)$(CHECKER) $(_END)\n"
				@make clean -C $(SRCS)/$(CHECKER)
				@printf	"\033[2K\r$(_BLUE)$(_BOLD)$(PUSH_SWAP) $(_END)\n"
				@make clean -C $(SRCS)/$(PUSH_SWAP)

fclean:			
				@printf	"\033[2K\r$(_BLUE)$(_BOLD)$(CHECKER) $(_END)\n"
				@make fclean -C $(SRCS)/$(CHECKER)
				@printf	"\033[2K\r$(_BLUE)$(_BOLD)$(PUSH_SWAP) $(_END)\n"
				@make fclean -C $(SRCS)/$(PUSH_SWAP)
				@$(RM) $(CHECKER)
				@$(RM) $(PUSH_SWAP)

re:				fclean all

norm:
				@printf	"\033[2K\r$(_BLUE)$(_BOLD)$(CHECKER) $(_END)\n"
				make norm -C $(SRCS)/$(CHECKER)
				@printf	"\033[2K\r$(_BLUE)$(_BOLD)$(PUSH_SWAP) $(_END)\n"
				make norm -C $(SRCS)/$(PUSH_SWAP)

.PHONY:			all clean fclean checker push_swap
