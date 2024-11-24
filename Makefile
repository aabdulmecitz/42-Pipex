NAME			= pipex
NAME_BONUS		= pipex_bonus

GREEN			= \033[0;32m
RED				= \033[0;31m
RESET			= \033[0m

LIBFT 			= lib/lft/libft.a

CC 				= cc

STANDARD_FLAGS 	= -Wall -Werror -Wextra

VALGRIND		= @valgrind --leak-check=full --show-leak-kinds=all \
--track-origins=yes --quiet --tool=memcheck --keep-debuginfo=yes

REMOVE 			= rm -f

SRCS_DIR		= ./src/

SRCS 			= $(addprefix $(SRCS_DIR),\
				error_msg.c pipex.c\
				ft_error_msg.c )

all:			${NAME} ${LIBFT} 

${NAME}: 		
				${CC} -Wall -Wextra -Werror ${SRCS} ${LIBFT} -g -o ${NAME}
				@echo "$(NAME): $(GREEN)$(NAME) was compiled.$(RESET)"
				@echo

${LIBFT}:
				@echo
				make bonus -C lib/lft

clean:
				make clean -C lib/lft
				@echo

fclean:
				${REMOVE} ${NAME} ${NAME_BONUS}
				@echo "${NAME}: ${RED}${NAME} and ${NAME_BONUS} were deleted${RESET}"
				@echo
push:
	git add .
	git commit -m "commit"
	git push

re:				fclean all

compile_libs:
	@make -sC lib/lft
update:
	git submodule update --init --recursive --remote

run:			re
				./${NAME} assets/maps/invalid/map-missing-W.ber

valgrind: $(NAME)
	$(VALGRIND) ./${NAME} assets/maps/valid/map4.ber 


.PHONY:			all clean fclean re rebonus valgrind run run_bonus makefile
